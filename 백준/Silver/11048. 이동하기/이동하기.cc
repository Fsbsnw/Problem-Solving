#include <iostream>

using namespace std;

int dp[1001][1001];
int arr[1001][1001];

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(arr[i][j] + dp[i - 1][j], arr[i][j] + dp[i][j - 1]);
        }
    }
    
    cout << dp[n][m];
    return 0;
}
