#include <iostream>

using namespace std;

int n, m;
int graph[1002][1002];
int dpLeft[1002][1002];
int dpRight[1002][1002];
int MIN = -987654321;

void Input()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
        }
    }
}

void Solution()
{
    for (int j = 1; j <= m; j++)
    {
        dpLeft[1][j] = dpLeft[1][j - 1] + graph[1][j];
        dpRight[1][j] = dpRight[1][j - 1] + graph[1][j];
    }
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            dpLeft[i][j] = MIN;
            dpRight[i][j] = MIN;
        }
        
        for (int j = 1; j <= m; j++)
        {
            dpLeft[i][j] = max(dpLeft[i - 1][j], dpLeft[i][j - 1]) + graph[i][j];
        }
        for (int j = m; j >= 1; j--)
        {
            dpRight[i][j] = max(dpRight[i - 1][j], dpRight[i][j + 1]) + graph[i][j];
        }
        
        for (int j = 1; j <= m; j++)
        {
            dpLeft[i][j] = max(dpLeft[i][j], dpRight[i][j]);
            dpRight[i][j] = max(dpLeft[i][j], dpRight[i][j]);
        }
    }
}

int main()
{
    Input();
    
    Solution();

    cout << dpLeft[n][m];
    
    return 0;
}