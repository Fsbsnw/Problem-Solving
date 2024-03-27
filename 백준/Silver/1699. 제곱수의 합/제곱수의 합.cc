#include <iostream>
#include <cmath>

using namespace std;

int dp[100001] = {0, };

int main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= 100000; i++) dp[i] = i;
    
    for (int i = 2; i <= 100000; i++)
    {
        for (int x = 1; x * x <= i; x++)
        {
            dp[i] = min(dp[i], dp[i - (x * x)] + 1);
        }
    }
    
    cout << dp[n];
    return 0;
}
