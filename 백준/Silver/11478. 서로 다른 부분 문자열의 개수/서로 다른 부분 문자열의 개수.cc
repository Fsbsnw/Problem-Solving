#include <iostream>
#include <set>

using namespace std;

int main()
{
    string S;
    cin >> S;
    
    set<string> UniqueWords;
    
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = i; j < S.size(); j++)
        {
            string Temp = S.substr(i, j - i + 1);
            UniqueWords.insert(Temp);
        }
    }
    
    cout << UniqueWords.size();

    return 0;
}