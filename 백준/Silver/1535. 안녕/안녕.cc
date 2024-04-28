#include <iostream>

using namespace std;

int health[21];
int joy[21];
int dp[101];

int main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> health[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> joy[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 100; j >= health[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - health[i]] + joy[i]);
        }
    }
    
    cout << dp[99];

    return 0;
}
