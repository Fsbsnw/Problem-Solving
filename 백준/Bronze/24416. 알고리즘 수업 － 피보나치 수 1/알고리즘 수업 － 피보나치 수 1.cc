#include <iostream>

using namespace std;

int DP[41];
int DPCount = 0;
int RecursiveCount = 0;

int RecursiveFibo(int Num)
{
    if (Num == 1 || Num == 2) 
    {
        RecursiveCount++;
        return 1;
    }
    return RecursiveFibo(Num - 2) + RecursiveFibo(Num - 1);
}

void DPFibo(int Num)
{
    for (int i = 3; i <= Num; i++)
    {
        DP[i] = DP[i - 2] + DP[i - 1];
        DPCount++;
    }
}

int main()
{
    DP[1] = 1;
    DP[2] = 1;
    
    int n; cin >> n;
    
    RecursiveFibo(n);
    DPFibo(n);
    
    cout << RecursiveCount << ' ' << DPCount;

    return 0;
}