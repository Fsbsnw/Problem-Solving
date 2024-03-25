#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][10] = {0, };

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += dp[n][i];
    }
    
    cout << sum % 10007;
    
    return 0;
}
