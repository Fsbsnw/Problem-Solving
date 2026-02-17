#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

vector<vector<int>> map;

void bfs()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int depth = q.front().second;
        q.pop();
        
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
            if (map[nx][ny] == 1 || depth + 1 < map[nx][ny])
            {
                map[nx][ny] = depth + 1;
                q.push({{nx, ny}, depth + 1});
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    map = maps;
    bfs();
    
    return (map[n - 1][m - 1] == 1) ? -1 : map[n - 1][m - 1];
}