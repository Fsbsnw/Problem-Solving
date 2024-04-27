#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];
int arr[1001];
int n;

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    cout << *max_element(dp, dp + 1001) + 1;

    return 0;
}
