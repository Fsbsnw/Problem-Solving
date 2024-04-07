#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int l, sx, sy, ex, ey;

int bfs(int x, int y, int visited[300][300])
{
    int result = 90000;
    queue<vector<int>> q;
    q.push({x, y, 0});
    visited[x][y] = 1;
    
    while (!q.empty())
    {
        int cx = q.front()[0];
        int cy = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        
        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (0 <= nx && nx < l && 0 <= ny && ny < l && !visited[nx][ny])
            {
                if (nx == ex && ny == ey)
                {
                    result = min(result, cnt + 1);
                }
                else
                {
                    q.push({nx, ny, cnt + 1});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    result = (result == 90000) ? 0 : result;
    return result;
}

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        cin >> l >> sx >> sy >> ex >> ey;
        
        int visited[300][300] = {0};
        
        cout << bfs(sx, sy, visited) << endl;
    }

    return 0;
}
