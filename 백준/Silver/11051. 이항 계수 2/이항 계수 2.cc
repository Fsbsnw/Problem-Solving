#include <iostream>

#define MOD 10007;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    
    int Combination[1001][1001];
    for (int i = 0; i <= 1000; i++)
    {
        Combination[i][i] = 1;
        Combination[i][0] = 1;
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            Combination[i][j] = (Combination[i - 1][j - 1] + Combination[i - 1][j]) % MOD;
        }
    }
    
    printf("%d", Combination[N][K]);
    
    return 0;
}