#include <iostream>

using namespace std;

#define mmax 1500001

int n;
int dp[mmax];
int schedule[mmax][2];

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> schedule[i][0] >> schedule[i][1];
    }
    
    
    for (int i = 1; i <= n; i++)
    {
        int t = schedule[i][0];
        int p = schedule[i][1];
        
        // 상담 못 받는 경우 다음 날
        if (i + t - 1 <= n) 
        {
            dp[i + t - 1] = max(dp[i + t - 1], dp[i - 1] + p);
        }
        
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n];
    
    return 0;
}