#include <iostream>

using namespace std;

int dp[201][201];

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= 200; i++)
    {
        dp[1][i] = i;
    }
    
    for (int i = 1; i <= 200; i++)
    {
        dp[i][1] = 1;
    }
    
    for (int i = 2; i <= 200; i++)
    {
        for (int j = 2; j <= 200; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
        }
    }
    
    cout << dp[n][m];

    return 0;
}
