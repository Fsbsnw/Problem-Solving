#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m, n, k;
vector<vector<int>> graph;
bool visited[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int start, int end)
{
    int result = 1;
    queue<pair<int, int>> q;
    visited[start][end] = true;
    
    q.push({start, end});
    
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (0 <= nx && nx < m && 0 <= ny && ny < n && !visited[nx][ny] && graph[nx][ny] == 0)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                result++;
            }
        }
    }
    
    return result;
}

int main()
{
    cin >> m >> n >> k;
    graph = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < k; i++)
    {
        int sx, sy, ex, ey, i1, i2, i3, i4;
        cin >> i1 >> i2 >> i3 >> i4;
        
        sx = m - i2;
        sy = i1;
        ex = m - i4;
        ey = i3;
        
        for (int z = ex; z < sx; z++)
        {
            for (int x = sy; x < ey; x++)
            {
                graph[z][x] = 1;
            }
        }
    }
    
    int cnt = 0;
    vector<int> answer;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && graph[i][j] == 0)
            {
                answer.push_back(bfs(i, j));
                cnt++;
            }
        }
    }
    
    cout << cnt << '\n';
    sort(answer.begin(), answer.end());
    for (int i : answer) cout << i << ' ';

    return 0;
}
