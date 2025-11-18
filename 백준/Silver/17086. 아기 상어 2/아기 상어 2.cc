#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int N, M, MaxDistance = 0;
vector<vector<int>> Map;

void BFS(int x, int y)
{
    int Result = 10000;
    vector<vector<int>> TMap(N, vector<int>(M, 5000));
    vector<vector<bool>> Visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    q.push({x, y});
    TMap[x][y] = 0;
    Visited[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int dir = 0; dir < 8; ++dir)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (0 <= nx && nx < N && 0 <= ny && ny < M && !Visited[nx][ny])
            {
                Visited[nx][ny] = true;
                TMap[nx][ny] = min(TMap[nx][ny], TMap[cx][cy] + 1);
                q.push({nx, ny});

                if (Map[nx][ny] == 1) 
                {
                    Result = min(Result, TMap[nx][ny]);
                    MaxDistance = max(MaxDistance, Result);
                    return;
                }
            }
        }
    }
}

int main() 
{
    cin >> N >> M;

    Map.assign(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Map[i][j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (Map[i][j] == 1) continue;
            BFS(i, j);
        }
    }

    cout << MaxDistance;

    return 0;
}