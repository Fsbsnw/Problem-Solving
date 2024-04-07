#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<int>> arr(100, vector<int>(100));
int n, cnt;

void bfs(int x, int y, vector<vector<bool>> &visited, int safe)
{
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && arr[nx][ny] > safe)
            {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

int findMax(int safe, vector<vector<bool>> &visited)
{
    int result = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && arr[i][j] > safe)
            {
                bfs(i, j, visited, safe);
                result++;
            }
        }
    }
    
    return result;
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i <= 100; i++)
    {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        cnt = max(cnt, findMax(i, visited));
    }
    
    cout << cnt;

    return 0;
}
