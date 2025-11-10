#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int R, C, T;
int CleanerTop, CleanerBottom;
vector<vector<int>> Map, Diff;

void Spread(int x, int y)
{
    if (Map[x][y] <= 0) return;
    
    int Div = Map[x][y] / 5;
    
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (0 <= nx && nx < R && 0 <= ny && ny < C && Map[nx][ny] != -1)
        {
            Diff[nx][ny] += Div;
            Diff[x][y] -= Div;
        }
    }
}

void CleanClockWise()
{
    // down
    for (int i = CleanerTop - 2; i >= 0; --i)   
    {
        Map[i + 1][0] = Map[i][0];
        Map[i][0] = 0;
    }
    // left
    for (int j = 1; j < C; ++j)
    {
        Map[0][j - 1] = Map[0][j];
        Map[0][j] = 0;
    }
    // up
    for (int i = 1; i <= CleanerTop; ++i)
    {
        Map[i - 1][C - 1] = Map[i][C - 1];
        Map[i][C - 1] = 0;
    }
    // right
    for (int j = C - 2; j > 0; --j)
    {
        Map[CleanerTop][j + 1] = Map[CleanerTop][j];
        Map[CleanerTop][j] = 0;
    }
}

void CleanRClockWise()
{
    // up
    for (int i = CleanerBottom + 2; i < R; ++i)
    {
        Map[i - 1][0] = Map[i][0];
        Map[i][0] = 0;
    }
    // left
    for (int j = 1; j < C; ++j)
    {
        Map[R - 1][j - 1] = Map[R - 1][j];
        Map[R - 1][j] = 0;
    }
    // down
    for (int i = R - 2; i >= CleanerBottom; --i)   
    {
        Map[i + 1][C - 1] = Map[i][C - 1];
        Map[i][C - 1] = 0;
    }
    // right
    for (int j = C - 2; j > 0; --j)
    {
        Map[CleanerBottom][j + 1] = Map[CleanerBottom][j];
        Map[CleanerBottom][j] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> R >> C >> T;
    
    Map.assign(R, vector<int>(C, 0));
    Diff.assign(R, vector<int>(C, 0));
    
    // input
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> Map[i][j];
            
            if (Map[i][j] == -1 && i - 1 >= 0)
            {
                CleanerTop = i - 1;
                CleanerBottom = i;
            }
        }
    }
    
    // solution
    for (int t = 1; t <= T; ++t)
    {
        // Spread
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                Spread(i, j);
            }
        }
        
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                Map[i][j] += Diff[i][j];
            }
        }
        
        // Clean
        CleanClockWise();
        CleanRClockWise();
        
        Diff.assign(R, vector<int>(C, 0));
    }
    
    int Result = 0;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (Map[i][j] > 0) Result += Map[i][j];
        }
    }
    
    cout << Result;

    return 0;
}