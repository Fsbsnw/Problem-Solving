#include<iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    long long DP[81];
    
    DP[1] = 1;
    DP[2] = 1;
    
    for (int i = 3; i <= N; i++)
    {
        DP[i] = DP[i - 2] + DP[i - 1];
    }
    
    long long Result = (N == 1) ? 4 : 2 * (DP[N] + DP[N] + DP[N - 1]);
    cout << Result;

    return 0;
}