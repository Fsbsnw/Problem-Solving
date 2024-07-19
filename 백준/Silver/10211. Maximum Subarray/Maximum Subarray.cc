#include <iostream>

using namespace std;

int t;
int arr[1001];
int dp[1001][1001];

int main()
{
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        int n; cin >> n;
        int result = -1000;
        
        for (int i = 1; i <= n; i++) 
        {
            cin >> arr[i];
            dp[i][i] = arr[i];
            result = max(result, arr[i]);
        }
        
        for (int i = n - 1; i >= 1; i--)
        {
            int temp = arr[i];
            
            for (int j = i + 1; j <= n; j++)
            {
                temp += arr[j];
                dp[i][j] = temp;
                result = max(result, dp[i][j]);
            }
        }
        
        cout << result << '\n';
    }

    return 0;
}