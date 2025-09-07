#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> Liquids(N);
    
    int Num1, Num2;
    
    for (int i = 0; i < N; i++)
    {
        cin >> Liquids[i];
    }
    
    int MIN = 2000000000;
    
    for (int i = 0; i < N; i++)
    {
        int Left = i + 1;
        int Right = N - 1;
        
        while (Left <= Right)
        {
            int Mid = (Left + Right) / 2;
            int Sum = Liquids[i] + Liquids[Mid];
            int Target = abs(Sum);
            
            if (Target < MIN)
            {
                MIN = Target;
                Num1 = Liquids[i];
                Num2 = Liquids[Mid];
            }
            
            if (Sum > 0)
            {
                Right = Mid - 1;
            }
            else
            {
                Left = Mid + 1;
            }
        }
    }
    
    cout << Num1 << ' ' << Num2;

    return 0;
}