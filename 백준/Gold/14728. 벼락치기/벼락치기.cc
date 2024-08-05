#include <iostream>

using namespace std;

int n, t;
int dp[101][10001];
int study[10001];
int point[10001];

int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> study[i] >> point[i];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (j - study[i] < 0) 
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                continue;
            }
            
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - study[i]] + point[i]);
        }
    }
    
    cout << dp[n][t];
    
    return 0;
}