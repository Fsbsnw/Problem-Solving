#include <iostream>

using namespace std;

int t;
int dp[10001];

int main()
{
    int t, k; cin >> t >> k;
    
    dp[0] = 1;
    
    for (int c = 0; c < k; c++)
    {
        int p, n; cin >> p >> n;
        
        for (int i = t; i >= 0; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i < j * p) break;
                
                dp[i] += dp[i - j * p];
            }
        }
    }
    
    cout << dp[t];

    return 0;
}