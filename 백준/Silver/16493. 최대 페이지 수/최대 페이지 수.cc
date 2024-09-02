#include <iostream>

using namespace std;

int n, m;
int dp[21][201];
int chapter[21];
int page[21];

int main()
{
    cin >> n >> m;
    
    for (int t = 1; t <= m; t++)
    {
        cin >> chapter[t] >> page[t];
        
        for (int i = 1; i <= n; i++)
        {
            if (i - chapter[t] < 0)
            {
                dp[t][i] = max(dp[t][i], dp[t - 1][i]);
                continue;
            }
            
            dp[t][i] = max(dp[t - 1][i], dp[t - 1][i - chapter[t]] + page[t]);
        }
    }
    
    cout << dp[m][n];

    return 0;
}