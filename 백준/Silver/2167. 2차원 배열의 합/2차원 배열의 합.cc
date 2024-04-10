#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    
    int k;
    cin >> k;
    
    for (int i = 0; i < k; i++)
    {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        cout << dp[ex][ey] - dp[ex][sy - 1] - dp[sx - 1][ey] + dp[sx - 1][sy - 1] << endl;
    }

    return 0;
}
