#include <iostream>
#include <algorithm>

using namespace std;

int PrefixSum[26][200001];

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);            
    
    string Text;
    cin >> Text;
    
    for (int Alpha = 0; Alpha < 26; Alpha++)
    {
        int* AlphaSum = PrefixSum[Alpha];
        
        for (int Index = 0; Index < Text.size(); Index++)
        {
            if (Index == 0)
            {
                AlphaSum[Index] = (Text[Index] - 'a' == Alpha) ? 1 : 0;
            }
            else
            {
                int Alphabet = Text[Index] - 'a';
                
                AlphaSum[Index] = (Alpha == Alphabet) ? AlphaSum[Index - 1] + 1 : AlphaSum[Index - 1];
            }
        }
    }
    
    int T;
    cin >> T;
    
    for (int Case = 0; Case < T; Case++)
    {
        char Character;
        cin >> Character;
        
        int Left, Right;
        cin >> Left >> Right;
        
        int CharIndex = Character - 'a';
        if (Left == 0)
        {
            cout << PrefixSum[CharIndex][Right] << '\n';
        }
        else
        {
            cout << PrefixSum[CharIndex][Right] - PrefixSum[CharIndex][Left - 1] << '\n';
        }
    }

    return 0;
}