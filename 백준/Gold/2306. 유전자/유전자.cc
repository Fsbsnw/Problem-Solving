#include <iostream>
#include <cstring>

using namespace std;

string s;
int dp[501][501];

int KOI(int left, int right)
{
    if (left >= right) return 0;
    if (dp[left][right] != -1) return dp[left][right];
    
    int result = 0;
    
    for (int k = left; k < right; k++)
    {
        result = max(result, KOI(left, k) + KOI(k + 1, right));
    }
    
    if ((s[left] == 'a' && s[right] == 't') || (s[left] == 'g' && s[right] == 'c'))
    {
        result = max(result, KOI(left + 1, right - 1) + 2);
    }
    
    return dp[left][right] = result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    
    memset(dp, -1, sizeof(dp));
    KOI(0, s.size() - 1);
    
    cout << dp[0][s.size() - 1];

    return 0;
}