#include <iostream>
#include <vector>

using namespace std;

// 1. 시야를 완전히 차단했는지 확인하는 함수
// 2. 브루트포스, 백트래킹

int N;
string Result = "NO";
vector<vector<char>> Map;
vector<vector<bool>> Visited;
vector<pair<int, int>> Teacher;
vector<pair<int, int>> Obstacle;

bool IsSightBlocked()
{
    for (auto& t : Teacher)
    {
        // 행 탐색
        for (int i = 0; i < N; ++i)
        {
            if (Map[t.first][i] != 'S') continue;
            
            int l = min(i, t.second);
            int r = max(i, t.second);
            
            bool bBlocked = false;
            
            // 사이 범위에서 장애물 확인
            for (; l <= r; ++l)
            {
                if (Map[t.first][l] == 'O') 
                {
                    bBlocked = true;
                    break;
                }
            }
            
            // 장애물에 막혀있지 않으면 false
            if (!bBlocked) return false;
        }
        
        // 열 탐색
        for (int i = 0; i < N; ++i)
        {
            if (Map[i][t.second] != 'S') continue;
            
            int l = min(i, t.first);
            int r = max(i, t.first);
            
            bool bBlocked = false;
            
            // 사이 범위에서 장애물 확인
            for (; l <= r; ++l)
            {
                if (Map[l][t.second] == 'O') 
                {
                    bBlocked = true;
                    break;
                }
            }
            
            // 장애물에 막혀있지 않으면 false
            if (!bBlocked) return false;
        }
    }
    return true;
}

void SetObstacle(int Depth)
{
    if (Depth == 3)
    {
        if (IsSightBlocked()) Result = "YES";
        return;
    }
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (Visited[i][j] || Map[i][j] == 'S' || Map[i][j] == 'T') continue;
            
            Visited[i][j] = true;
            Map[i][j] = 'O';
            SetObstacle(Depth + 1);
            Map[i][j] = 'X';
            Visited[i][j] = false;
        }
    }
}

int main()
{
    cin >> N;
    
    Map.assign(N, vector<char>(N));
    Visited.assign(N, vector<bool>(N));
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Map[i][j];
            
            if (Map[i][j] == 'T') Teacher.push_back({i, j});
            if (Map[i][j] == 'O') Obstacle.push_back({i, j});
        }
    }
    
    SetObstacle(0);
    
    cout << Result;

    return 0;
}