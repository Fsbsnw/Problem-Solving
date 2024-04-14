#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[17][17] = {0, };
    int dp[17][17][4] = {0, };
    dp[1][2][1] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 3; i <= n; i++)
    {
        if (!arr[1][i]) dp[1][i][1] = dp[1][i - 1][1];
    }
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 3; j <= n; j++)
        {
            if (!arr[i][j])
            {
                dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][2];
                dp[i][j][3] = dp[i - 1][j][3] + dp[i - 1][j][2];
                if (!arr[i - 1][j] && !arr[i][j - 1]) 
                {
                    dp[i][j][2] = dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2] + dp[i - 1][j - 1][3];
                }
            }
        }
    }
    
    cout << dp[n][n][1] + dp[n][n][2] + dp[n][n][3];

    return 0;
}
