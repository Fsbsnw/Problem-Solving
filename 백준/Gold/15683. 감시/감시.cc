#include <iostream>
#include <vector>

using namespace std;

#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3

int N, M;
int MIN = 64;
vector<vector<int>> OfficeMap;
vector<pair<int, int>> CCTVPos;

vector<int> CCTVPatterns[6] = 
{
    {},              
    {0, 1, 0, 0},    
    {0, 1, 0, 1},    
    {1, 1, 0, 0},    
    {1, 1, 0, 1},    
    {1, 1, 1, 1}     
};

void Input()
{
    cin >> N >> M;
    OfficeMap.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> OfficeMap[i][j];
            if (OfficeMap[i][j] > 0 && OfficeMap[i][j] < 6)
            {
                CCTVPos.push_back({i, j});
            }
        }
    }
}

void MoveDirection(int x, int y, int Dir, vector<vector<int>>& Visited)
{
    if (Dir == TOP) 
    {
        for (int i = x - 1; i >= 0; i--) 
        {
            if (Visited[i][y] == 6) break;
            if (Visited[i][y] == 0) Visited[i][y] = -1;
        }
    }
    else if (Dir == RIGHT) 
    {
        for (int j = y + 1; j < M; j++) 
        {
            if (Visited[x][j] == 6) break;
            if (Visited[x][j] == 0) Visited[x][j] = -1;
        }
    }
    else if (Dir == BOTTOM) 
    {
        for (int i = x + 1; i < N; i++) 
        {
            if (Visited[i][y] == 6) break;
            if (Visited[i][y] == 0) Visited[i][y] = -1;
        }
    }
    else if (Dir == LEFT) 
    {
        for (int j = y - 1; j >= 0; j--) 
        {
            if (Visited[x][j] == 6) break;
            if (Visited[x][j] == 0) Visited[x][j] = -1;
        }
    }
}

void RotateClockwise(vector<int>& CCTV)
{
    int Temp = CCTV.back();
    CCTV.pop_back();
    CCTV.insert(CCTV.begin(), Temp);
}

void CheckCCTVArea(int Index, vector<vector<int>> Visited)
{
    if (Index == CCTVPos.size()) 
    {
        int TempMIN = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (Visited[i][j] == 0) TempMIN++;

        MIN = min(MIN, TempMIN);
        return;
    }

    int x = CCTVPos[Index].first;
    int y = CCTVPos[Index].second;
    int CCTVNum = OfficeMap[x][y];
    vector<int> CurrCCTV = CCTVPatterns[CCTVNum];

    for (int t = 0; t < 4; t++) 
    {
        vector<vector<int>> Backup = Visited;

        for (int Dir = 0; Dir < 4; Dir++) 
        {
            if (CurrCCTV[Dir] == 1)
                MoveDirection(x, y, Dir, Visited);
        }

        CheckCCTVArea(Index + 1, Visited);
        Visited = Backup;

        RotateClockwise(CurrCCTV);
    }
}

int main()
{
    Input();
    CheckCCTVArea(0, OfficeMap);
    cout << MIN;
    return 0;
}
