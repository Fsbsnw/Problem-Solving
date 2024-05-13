#include <iostream>

using namespace std;

int n, m;
int graph[501][501];

int CountType1(int x, int y)
{
    int temp = 0;
    
    if (x + 3 <= n) temp = max(temp, graph[x][y] + graph[x + 1][y] + graph[x + 2][y] + graph[x + 3][y]);
    if (y + 3 <= m) temp = max(temp, graph[x][y] + graph[x][y + 1] + graph[x][y + 2] + graph[x][y + 3]);
    
    return temp;
}

int CountType2(int x, int y)
{
    int temp = 0;
    
    if (x + 1 <= n && y + 1 <= m) temp = max(temp, graph[x][y] + graph[x + 1][y] + graph[x][y + 1] + graph[x + 1][y + 1]);
    
    return temp;
}

int CountType3(int x, int y)
{
    int temp = 0;
    
    if (x + 2 <= n && y + 1 <= m) temp = max(temp, graph[x][y] + graph[x + 1][y] + graph[x + 2][y] + graph[x + 2][y + 1]);
    if (x + 2 <= n && y - 1 >= 0) temp = max(temp, graph[x][y] + graph[x + 1][y] + graph[x + 2][y] + graph[x + 2][y - 1]);
    
    if (x + 1 <= n && y + 2 <= m) temp = max(temp, graph[x][y] + graph[x][y + 1] + graph[x][y + 2] + graph[x + 1][y + 2]);
    if (x - 1 >= 0 && y + 2 <= m) temp = max(temp, graph[x][y] + graph[x][y + 1] + graph[x][y + 2] + graph[x - 1][y + 2]);
    
    if (x - 2 >= 0 && y + 1 <= m) temp = max(temp, graph[x][y] + graph[x - 1][y] + graph[x - 2][y] + graph[x - 2][y + 1]);
    if (x - 2 >= 0 && y - 1 >= 0) temp = max(temp, graph[x][y] + graph[x - 1][y] + graph[x - 2][y] + graph[x - 2][y - 1]);
    
    if (x + 1 <= n && y - 2 >= 0) temp = max(temp, graph[x][y] + graph[x][y - 1] + graph[x][y - 2] + graph[x + 1][y - 2]);
    if (x - 1 >= 0 && y - 2 >= 0) temp = max(temp, graph[x][y] + graph[x][y - 1] + graph[x][y - 2] + graph[x - 1][y - 2]);
    
    return temp;
}

int CountType4(int x, int y)
{
    int temp = 0;
    
    if (x + 2 <= n && y + 1 <= m) temp = max(temp, graph[x][y] + graph[x + 1][y] + graph[x + 1][y + 1] + graph[x + 2][y + 1]);
    if (x + 2 <= n && y - 1 >= 0) temp = max(temp, graph[x][y] + graph[x + 1][y] + graph[x + 1][y - 1] + graph[x + 2][y - 1]);
    
    if (x + 1 <= n && y + 2 <= m) temp = max(temp, graph[x][y] + graph[x][y + 1] + graph[x + 1][y + 1] + graph[x + 1][y + 2]);
    if (x - 1 >= 0 && y + 2 <= m) temp = max(temp, graph[x][y] + graph[x][y + 1] + graph[x - 1][y + 1] + graph[x - 1][y + 2]);
    
    return temp;
}

int CountType5(int x, int y)
{
    int temp = 0;
    
    if (x + 1 <= n && y + 2 <= m) temp = max(temp, graph[x][y] + graph[x][y + 1] + graph[x][y + 2] + graph[x + 1][y + 1]);
    if (x - 1 >= 0 && y + 2 <= m) temp = max(temp, graph[x][y] + graph[x][y + 1] + graph[x][y + 2] + graph[x - 1][y + 1]);
    
    if (x + 2 <= n && y + 1 <= m) temp = max(temp, graph[x][y] + graph[x + 1][y] + graph[x + 2][y] + graph[x + 1][y + 1]);
    if (x + 2 <= n && y - 1 >= 0) temp = max(temp, graph[x][y] + graph[x + 1][y] + graph[x + 2][y] + graph[x + 1][y - 1]);
    
    return temp;
}

int CountMax()
{
    int result = 0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            result = max(result, CountType1(i, j));
            result = max(result, CountType2(i, j));
            result = max(result, CountType3(i, j));
            result = max(result, CountType4(i, j));
            result = max(result, CountType5(i, j));
        }
    }
    
    return result;
}

int main()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
        }
    }
    
    cout << CountMax();

    return 0;
}
