#include <iostream>

using namespace std;

int n, m, k;
int dp[1025][1025];
int graph[1025][1025];

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
            dp[i][j] = dp[i - 1][j] - dp[i - 1][j - 1] + graph[i][j] + dp[i][j - 1];
        }
    }
    
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << dp[x2][y2] -(dp[x1 - 1][y2] + dp[x2][y1 - 1] - dp[x1 - 1][y1 - 1]) << '\n';
    }
    

    return 0;
}