#include <iostream>

int DP[41][2];

int main()
{
    int N;
    scanf("%d", &N);
    
    DP[0][0] = 1;
    DP[1][1] = 1;
    
    for (int i = 2; i <= 40; i++)
    {
        DP[i][0] = DP[i - 1][0] + DP[i - 2][0];
        DP[i][1] = DP[i - 1][1] + DP[i - 2][1];
    }
    
    for (int Case = 0; Case < N; Case++)
    {
        int Num;
        scanf("%d", &Num);
        
        printf("%d %d\n", DP[Num][0], DP[Num][1]);
    }

    return 0;
}