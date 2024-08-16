#include <iostream>

using namespace std;

int main()
{
    int dp[11];
    dp[1] = 0;
    dp[2] = 1;
    
    for (int i = 3; i <= 10; i++)
    {
        int share = i / 2;
        dp[i] = (share * (i - share)) + dp[share] + dp[i - share];
    }
    
    int n; cin >> n;
    cout << dp[n];

    return 0;
}