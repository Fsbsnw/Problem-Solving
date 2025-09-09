#include <iostream>
#include <vector>

using namespace std;

bool IsGroupedWord(vector<int>& Arr)
{
    for (int i = 0; i < Arr.size() - 1; i++)
    {
        if (Arr[i] - Arr[i + 1] != 1) return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    
    int Count = 0;
    
    for (int t = 0; t < N; t++)
    {
        string S;
        cin >> S;
        
        bool bIsGroupedWord = true;
        
        for (int i = 1; i < S.size(); i++)
        {
            vector<int> Arr;
            Arr.push_back(i);
            
            for (int k = i - 1; k >= 0; k--)
            {
                if (S[i] == S[k]) Arr.push_back(k);
            }
            
            if (!IsGroupedWord(Arr)) 
            {
                bIsGroupedWord = false;
                break;
            }
        }
        
        if (bIsGroupedWord) Count++;
    }
    
    cout << Count;

    return 0;
}