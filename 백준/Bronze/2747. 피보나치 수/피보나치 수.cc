#include <iostream>

int main()
{
    int N;
    scanf("%d", &N);
    
    int DP[45];
    DP[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2];
    }

    printf("%d", DP[N]);

    return 0;
}