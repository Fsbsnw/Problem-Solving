#include <iostream>

using namespace std;

int main()
{
    long long X, Y;
    cin >> X >> Y;
    
    long long Target = (Y * 100) / X;
    long long Left = 0;
    long long Right = 2100000000;
    
    if (Target >= 99)
    {
        cout << -1;
    }
    else
    {
        while (Left <= Right)
        {
            long long Mid = (Left + Right) / 2;
            long long Percent = ((Y + Mid) * 100) / (X + Mid);
            
            if (Percent == Target)
            {
                Left = Mid + 1;
            }
            else
            {
                Right = Mid - 1;
            }
        }
        cout << Left;
    }

    return 0;
}