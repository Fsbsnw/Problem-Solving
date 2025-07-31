#include<iostream>

int main()
{
    int N;
    scanf("%d", &N);
    
    long long DP[41];
    
    DP[1] = 1;
    DP[2] = 1;
    
    for (int i = 3; i <= N; i++)
    {
        DP[i] = DP[i - 2] + DP[i - 1];
    }
    
    long long Result = DP[N] * 2 + (DP[N - 1] + DP[N]) * 2;
    
    printf("%d", Result);

    return 0;
}