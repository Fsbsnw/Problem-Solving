#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y, vector<vector<int>>& visited, vector<vector<int>>& arr)
{
    queue<pair<int, int>> q;
    int answer = 0;
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
            if (0 <= nx && nx < arr.size() && 0 <= ny && ny < arr[0].size() && !visited[nx][ny] && arr[nx][ny] == 0)
            {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
                arr[nx][ny] = 2;
            }
        }
    }
}


int main()
{
    int n, m;
    int answer = 0;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<pair<int, int>> virus;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                virus.push_back(make_pair(i, j));
            }
        }
    }
    
    for (int i = 0; i < n * m; i++)
    {
        if (arr[i / m][i % m] != 0) continue;
        visited[i / m][i % m] = 1;
        arr[i / m][i % m] = 1;
        for (int j = i + 1; j < n * m; j++)
        {
            if (arr[j / m][j % m] != 0) continue;
            visited[j / m][j % m] = 1;
            arr[j / m][j % m] = 1;
            for (int k = j + 1; k < n * m; k++)
            {
                if (arr[k / m][k % m] != 0) continue;
                visited[k / m][k % m] = 1;
                arr[k / m][k % m] = 1;
                
                vector<vector<int>> ta(arr);
                vector<vector<int>> tv(visited);
                
                for (pair<int, int> v : virus)
                {
                    bfs(v.first, v.second, tv, ta);
                }
                
                int temp = 0;
                for (vector<int> i : ta)
                {
                    for (int j : i)
                    {
                        if (j == 0) temp++;
                    }
                }
                answer = max(answer, temp);
                
                arr[k / m][k % m] = 0;
                visited[k / m][k % m] = 0;
            }
            arr[j / m][j % m] = 0;
            visited[j / m][j % m] = 0;
        }
        arr[i / m][i % m] = 0;
        visited[i / m][i % m] = 0;
    }
    
    cout << answer;

    return 0;
}
