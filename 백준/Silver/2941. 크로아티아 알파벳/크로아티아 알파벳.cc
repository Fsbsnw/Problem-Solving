#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;
    
    int Count = 0;
    
    for (int i = S.size() - 1; i >= 0; i--)
    {
        char C = S[i];
        
        if (C == '=' && i - 1 >= 0)
        {
            if (S[i - 1] == 'c')
            {
                Count++;
                i--;
            }
            else if (S[i - 1] == 's')
            {
                Count++;
                i--;
            }
            else if (S[i - 1] == 'z')
            {
                if (i - 2 >= 0 && S[i - 2] == 'd')
                {
                    Count++;
                    i -= 2;
                }
                else
                {
                    Count++;
                    i--;
                }
            }
        }
        else if (C == '-' && i - 1 >= 0)
        {
            if (S[i - 1] == 'c')
            {
                Count++;
                i--;
            }
            else if (S[i - 1] == 'd')
            {
                Count++;
                i--;
            }
        }
        else if (C == 'j' && i - 1 >= 0)
        {
            if (S[i - 1] == 'l')
            {
                Count++;
                i--;
            }
            else if (S[i - 1] == 'n')
            {
                Count++;
                i--;
            }
            else
            {
                Count++;
            }
        }
        else
        {
            Count++;
        }
    }
    
    cout << Count;

    return 0;
}