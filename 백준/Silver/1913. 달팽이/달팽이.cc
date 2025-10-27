#include <iostream>
#include <vector>

using namespace std;

const int TOP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, K;
int Depth = 0;
int cx = 0, cy = 0;
int kx = 0, ky = 0;
vector<vector<int>> answer;

bool CanMove(int x, int y)
{
    return (0 <= x && x < N && 0 <= y && y < N && answer[x][y] == 0);
}

void CheckAndSavePos()
{
    if (Depth == K) {kx = cx; ky = cy;}
}

int Move(int Direction)
{
    // cw : ClockWise
    int cwx = cx + dx[(Direction + 1) % 4];
    int cwy = cy + dy[(Direction + 1) % 4];
    
    if (CanMove(cwx, cwy))
    {
        answer[cwx][cwy] = ++Depth;
        cx = cwx;
        cy = cwy;
        return (Direction + 1) % 4;
    }
    
    int nx = cx + dx[Direction];
    int ny = cy + dy[Direction];
    
    if (CanMove(nx, ny))
    {
        answer[nx][ny] = ++Depth;
        cx = nx;
        cy = ny;
        return Direction;
    }
    
    return -1;
}

void FindSnailPath(int Direction)
{
    while (Depth != N * N)
    {
        CheckAndSavePos();
        
        int NextDirection = Move(Direction);
        Direction = NextDirection;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    
    answer.assign(N, vector<int>(N, 0));
    answer[N / 2][N / 2] = ++Depth;
    cx = N / 2;
    cy = N / 2;
    CheckAndSavePos();
    answer[N / 2 - 1][N / 2] = ++Depth;
    cx -= 1;
    
    FindSnailPath(TOP);
    
    for (auto a : answer)
    {
        for (auto b : a)
        {
            cout << b << ' ';
        }
        cout << '\n';
    }
    
    cout << kx + 1 << ' ' << ky + 1;

    return 0;
}