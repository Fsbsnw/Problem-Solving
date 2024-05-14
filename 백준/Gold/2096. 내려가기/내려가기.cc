#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> dp(3, 0);
    vector<int> dp2(3, 0);
    
    int result = 0;
    int result2 = 1000000;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        int max1 = max(dp[0] + a, dp[1] + a);
        int max2 = max(max(dp[0] + b, dp[1] + b), dp[2] + b);
        int max3 = max(dp[1] + c, dp[2] + c);
        
        dp = {max1, max2, max3};
         
        int min1 = min(dp2[0] + a, dp2[1] + a);
        int min2 = min(min(dp2[0] + b, dp2[1] + b), dp2[2] + b);
        int min3 = min(dp2[1] + c, dp2[2] + c);
        
        dp2 = {min1, min2, min3};
    }
    
    cout << max(max(dp[0], dp[1]), dp[2]) << ' ' << min(min(dp2[0], dp2[1]), dp2[2]);
    
    return 0;
}

