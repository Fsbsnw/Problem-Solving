#include <iostream>

using namespace std;

int main()
{
    int Sum = 0;
    int Numbers[5];
    int NumberSize = sizeof(Numbers) / sizeof(Numbers[0]);
    
    for (int Index = 0; Index < NumberSize; Index++)
    {
        cin >> Numbers[Index];
        Sum += Numbers[Index];
    }
    
    for (int I = 0; I < NumberSize - 1; I++)
    {
        for (int J = 0; J < NumberSize - 1 - I; J++)
        {
            if (Numbers[J] < Numbers[J + 1])
            {
                int Temp = Numbers[J];
                Numbers[J] = Numbers[J + 1];
                Numbers[J + 1] = Temp;
            }
        }
    }
    
    int Average = Sum / NumberSize;
    int Median = 0;
    if (NumberSize % 2 == 0)
    {
        Median = (Numbers[NumberSize / 2] + Numbers[NumberSize / 2 - 1]) / 2;
    }
    else
    {
        Median = Numbers[NumberSize / 2];
    }

    cout << Average << '\n' << Median;

    return 0;
}