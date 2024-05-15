#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[201];
int dp[201];

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    cout << n - *max_element(dp, dp + 201);

    return 0;
}
