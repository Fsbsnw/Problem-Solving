#include <iostream>
#include <cmath>

using namespace std;

pair<int, int> matrix[501];
int dp[501][501];
pair<int, int> dp_matrix[501][501];

int Sum(int dx, int mid, int dy) 
{
	return dp_matrix[dx][mid].first * dp_matrix[dx][mid].second * dp_matrix[mid + 1][dy].second;
}

int main() 
{
    int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> matrix[i].first >> matrix[i].second;
		dp_matrix[i][i] = matrix[i];
	}
	for (int i = 1; i < n; i++) 
	{
		for (int dx = 1; dx + i <= n; dx++) 
		{
			int dy = dx + i;
			dp[dx][dy] = pow(2, 31) - 1;
			for (int mid = dx; mid < dy; mid++) 
			{
				dp[dx][dy] = min(dp[dx][dy], dp[dx][mid] + dp[mid + 1][dy] + Sum(dx, mid, dy));
			}
			dp_matrix[dx][dy].first = matrix[dx].first;
			dp_matrix[dx][dy].second = matrix[dy].second;
		}
	}
	cout << dp[1][n];
	
	return 0;
}