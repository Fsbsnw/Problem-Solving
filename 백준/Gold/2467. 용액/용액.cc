#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> Liquids(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> Liquids[i];
    }
    
    int MIN = 2000000000;
    int Num1, Num2;
        
    int Left = 0;
    int Right = N - 1;
    
    while (Left < Right)
    {
        int Sum = Liquids[Left] + Liquids[Right];
        if (abs(Sum) < MIN)
        {
            MIN = abs(Sum);
            Num1 = Liquids[Left];
            Num2 = Liquids[Right];
        }
        
        if (Sum > 0)
        {
            Right--;
        }
        else if (Sum < 0)
        {
            Left++;
        }
        else
        {
            break;
        }
    }
        
    cout << Num1 << ' ' << Num2;

    return 0;
}