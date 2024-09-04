#include <iostream>

using namespace std;

#define MOD 16769023

long long dp[100001][3];
int n;

int main()
{
    cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][2] % MOD;
        dp[i][1] = dp[i - 1][2] % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
    
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;

    return 0;
}