#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Sort(vector<int>& a, vector<int>& b)
{
    return (a[1] < b[1]);
}

int main()
{
    int n, d; cin >> n >> d;
    vector<vector<int>> arr(n);
    vector<int> dp(d + 1);
    
    for (int i = 0; i <= d; i++) dp[i] = i;
    
    for (int i = 0; i < n; i++)
    {
        int x, y, dis; cin >> x >> y >> dis;
        
        arr[i] = {x, y, dis};
    }
    
    sort(arr.begin(), arr.end(), Sort);
    
    for (int i = 1; i <= d; i++)
    {
        for (vector<int> j : arr)
        {
            if (j[1] == i)
            {
                dp[i] = min(min(dp[i], dp[j[0]] + j[2]), dp[i - 1] + 1);
            }
            else
            {
                dp[i] = min(dp[i], dp[i - 1] + 1);
            }
        }
    }
    
    cout << dp[d];

    return 0;
}
