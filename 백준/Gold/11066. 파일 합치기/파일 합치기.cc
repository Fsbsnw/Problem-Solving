#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int t, k;
int sum[501], file[501], dp[501][501];
int INF = 123456789;

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}

		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= k - i; j++)
			{
				dp[j][i + j] = INF;
				for (int l = j; l < i + j; l++)
				{
					dp[j][i + j] = min(dp[j][i + j], dp[j][l] + dp[l + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}

		cout << dp[1][k] << endl;
	}
	
	return 0;
}