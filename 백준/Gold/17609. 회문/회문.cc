#include <iostream>
#include <string>
using namespace std;

bool IsPalindrome(const string& S, int Left, int Right)
{
    while (Left < Right)
    {
        if (S[Left] != S[Right]) return false;
        
        Left++; Right--;
    }
    return true;
}

int PalType(const string& S)
{
    int Left = 0, Right = S.size() - 1;
    
    while (Left < Right)
    {
        if (S[Left] == S[Right]) 
        { 
            Left++; Right--; 
            continue; 
        }
        return (IsPalindrome(S, Left + 1, Right) || IsPalindrome(S, Left, Right - 1)) ? 1 : 2;
    }
    return 0;
}

int main()
{
    int N;
    cin >> N;
    
    while (N--)
    {
        string S;
        cin >> S;
        
        cout << PalType(S) << '\n';
    }
    
    return 0;
}