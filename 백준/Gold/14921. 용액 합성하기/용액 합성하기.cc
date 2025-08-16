#include <iostream>

using namespace std;

int MIN = 200000000;
int Liquids[100000];

int main()
{
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> Liquids[i];
    }
    
    int IndexL = 0;
    int IndexR = N - 1;
    int Left = 0;
    int Right = N - 1;
    
    while (Left < Right)
    {
        int Sum = Liquids[Left] + Liquids[Right];
        if (abs(Sum) < MIN)
        {
            IndexL = Left;
            IndexR = Right;
            MIN = abs(Sum);
        }
        if (Sum > 0)
        {
            Right--;
        }
        else
        {
            Left++;
        }
    }
    
    cout << Liquids[IndexL] + Liquids[IndexR];

    return 0;
}