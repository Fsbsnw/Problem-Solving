#include <iostream>

using namespace std;

int n;
int arr[1001];
int dp[1001];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int temp = 10000;
        for (int j = 1; j <= i; j++)
        {
            temp = min(temp, dp[i - j] + arr[j]);
        }
        dp[i] = temp;
    }
    
    cout << dp[n];

    return 0;
}
