#include <iostream>

using namespace std;

bool Numbers[10001];

int FunctionD(int Num)
{
    string StrNum = to_string(Num);
    int Sum = 0;
    
    for (int i = 0; i < StrNum.size(); i++)
    {
        Sum += StrNum[i] - '0';
    }
    return (Num + Sum);
}

int main()
{
    for (int i = 1; i <= 10000; i++)
    {
        Numbers[FunctionD(i)] = true;
    }
    
    for (int i = 1; i <= 10000; i++)
    {
        if (!Numbers[i])
        {
            cout << i << '\n';
        }
    }

    return 0;
}