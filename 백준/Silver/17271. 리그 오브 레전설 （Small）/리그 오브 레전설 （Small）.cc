#include <iostream>

using namespace std;

#define MOD 1000000007

long long dp[10001];

int main()
{
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        dp[i] = 1;
    }
    
    for (int i = m; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
    }
    
    cout << dp[n];

    return 0;
}