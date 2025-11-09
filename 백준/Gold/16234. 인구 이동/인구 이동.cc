#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, L, R;
vector<vector<int>> Map;
vector<vector<bool>> Visited;
vector<pair<int, int>> Union;

bool IsValidUnion(const pair<int, int>& First, const pair<int, int>& Second)
{
    int DIFF = abs(Map[First.first][First.second] - Map[Second.first][Second.second]);
    return (L <= DIFF && DIFF <= R);
}

void UnionMove(int x, int y)
{
    if (Visited[x][y]) return;
    
    Visited[x][y] = true;
    
    queue<pair<int, int>> q;
    q.push({x, y});
    Union.push_back({x, y});
    
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        
        for (int d = 0; d < 4; ++d)
        {
            int nx = p.first + dx[d];
            int ny = p.second + dy[d];
            
            if (0 <= nx && nx < N && 0 <= ny && ny < N && !Visited[nx][ny] && IsValidUnion(make_pair(p.first, p.second), make_pair(nx, ny)))
            {
                Visited[nx][ny] = true;
                q.push({nx, ny});
                Union.push_back({nx, ny});
            }
        }
    }
    
    int Sum = 0;
    for (const pair<int, int>& Pos : Union)
    {
        Sum += Map[Pos.first][Pos.second];
    }
    
    Sum /= Union.size();
    for (const pair<int, int>& Pos : Union)
    {
        Map[Pos.first][Pos.second] = Sum;
    }
    
    Union.clear();
}

int main()
{
    cin >> N >> L >> R;
    
    Map.assign(N, vector<int>(N));
    Visited.assign(N, vector<bool>(N, false));
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Map[i][j];
        }
    }
    
    vector<vector<int>> Prev = Map;
    for (int Day = 1; Day <= 2000; ++Day)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                UnionMove(i, j);
            }
        }
        
        if (Prev == Map)
        {
            cout << Day - 1;
            break;
        }
        
        Prev = Map;
        Visited.assign(N, vector<bool>(N, false));
    }

    return 0;
}