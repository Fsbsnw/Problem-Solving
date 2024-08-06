#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int student[10000001];
unordered_map<int, int> dp;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> student[i];
    
    int mmax = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[student[i]] = dp[student[i] - 1] + 1;
        mmax = max(mmax, dp[student[i]]);
    }
    
    cout << n - mmax;

    return 0;
}