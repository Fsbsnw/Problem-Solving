#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y, int maxX, int maxY, int arr[50][50])
{
    queue<pair<int, int>> queue;
    queue.push(make_pair(x, y));
    arr[x][y] = 0;
    
    while (!queue.empty())
    {
        int cx = queue.front().first;
        int cy = queue.front().second;
        queue.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (0 <= nx && nx < maxX && 0 <= ny && ny < maxY && arr[nx][ny])
            {
                arr[nx][ny] = 0;
                queue.push(make_pair(nx, ny));
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        int n, m, k, cnt = 0;
        cin >> m >> n >> k;
        int arr[50][50] = {0};
        
        for (int j = 0; j < k; j++)
        {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }
        
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < m; l++)
            {
                if (arr[j][l]) 
                {
                    bfs(j, l, n, m, arr);
                    cnt++;
                }
            }
        }
        
        cout << cnt << endl;
    }
    
    return 0;
}
