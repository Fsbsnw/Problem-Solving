#include <iostream>
#include <vector>

using namespace std;

int dp[1001];
int arr[1001];

int main()
{
    int n; cin >> n;
    fill(dp + 1, dp + n + 1, 1);
    
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
            }
        }
        len = max(len, dp[i]);
    }
    
    cout << len << '\n';
    
    vector<int> result;
    for (int i = n; i >= 1; i--)
    {
        if (dp[i] == len)
        {
            len--;
            result.push_back(arr[i]);
        }
    }
    
    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i] << ' ';
    }

    return 0;
}
