#include <iostream>

using namespace std;

int dp[2][46];

int main()
{
    int n; cin >> n;
    dp[0][1] = 0;
    dp[1][1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = dp[1][i - 1];
        dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
    }
    
    cout << dp[0][n] << ' ' << dp[1][n];

    return 0;
}
