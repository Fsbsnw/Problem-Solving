#include <iostream>

using namespace std;

int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) 
{
    return a / gcd(a, b) * b;
}

int Numbers[5];
int MIN = 987654321;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> Numbers[i];
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                int GCD = gcd(gcd(Numbers[i], Numbers[j]), Numbers[k]);
                int LCM = lcm(lcm(Numbers[i], Numbers[j]), Numbers[k]);
                
                if (LCM < MIN) MIN = LCM;
            }
        }
    }
    
    cout << MIN;

    return 0;
}