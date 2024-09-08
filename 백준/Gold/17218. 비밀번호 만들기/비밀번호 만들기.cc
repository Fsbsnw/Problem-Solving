#include <iostream>

using namespace std;

string s1, s2, dp[41][41];

int main()
{
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    
    for (int i = 1; i < s1.size(); i++)
    {
        for (int j = 1; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + s1[i];
            }
            else
            {
                if (dp[i - 1][j].size() > dp[i][j - 1].size())
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }
    
    cout << dp[s1.size() - 1][s2.size() - 1];

    return 0;
}