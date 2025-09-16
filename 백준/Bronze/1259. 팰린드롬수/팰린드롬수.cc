#include <iostream>

using namespace std;

int main()
{
    string S;
    
    while (cin >> S)
    {
        if (S == "0") break;
        
        int Left = 0;
        int Right = S.size() - 1;
        bool bIsValid = true;
        
        while (Left <= Right)
        {
            if (S[Left] != S[Right])
            {
                bIsValid = false;
                break;
            }
            
            Left++;
            Right--;
        }
        
        cout << ((bIsValid ? "yes" : "no")) << '\n';
    }

    return 0;
}