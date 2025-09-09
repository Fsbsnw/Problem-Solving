#include <iostream>
#include <vector>

using namespace std;

bool IsGroupedWord(const string& S)
{
    vector<bool> Visited(26);
    char Prev = ' ';
    
    for (char C : S)
    {
        if (C != Prev)
        {
            if (Visited[C - 'a']) return false;
            
            Visited[C - 'a'] = true;
            Prev = C;
        }
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
        
        if (IsGroupedWord(S)) Count++;
    }
    
    cout << Count;

    return 0;
}