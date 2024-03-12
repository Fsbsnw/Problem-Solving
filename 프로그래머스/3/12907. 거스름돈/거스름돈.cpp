#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int i : money)
    {
        for (int k = i; k <= n; k++)
        {
            dp[k] += dp[k - i];
        }
    }
    
    return dp[n];
}