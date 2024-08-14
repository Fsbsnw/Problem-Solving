#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t; cin >> t;
    
    for (int Case = 0; Case < t; Case++)
    {
        int n; cin >> n;
        
        vector<int> coins(n, 0);
        for (int i = 0; i < n; i++) cin >> coins[i];
        
        int TargetPrice; cin >> TargetPrice;
        vector<int> dp(TargetPrice + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < n; i++)
        {
            int coin = coins[i];
            for (int j = 1; j <= TargetPrice; j++)
            {
                if (j - coin < 0) continue;
                
                dp[j] += dp[j - coin];
            }
        }
        
        cout << dp[TargetPrice] << '\n';
    }

    return 0;
}