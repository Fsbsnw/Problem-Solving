#include <iostream>

using namespace std;

int r, c, w;
int dp[31][31];

int main()
{
    cin >> r >> c >> w;
    
    for (int i = 1; i <= 30; i++)
    {
        dp[i][1] = 1;
        dp[i][i] = 1;
    }
    
    for (int i = 2; i <= 30; i++)
    {
        for (int j = 2; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    
    int diff = 1;
    int result = 0;
    for (int i = r; i < r + w; i++)
    {
        for (int j = c; j < c + diff; j++)
        {
            result += dp[i][j];
        }
        diff++;
    }
    
    cout << result;

    return 0;
}