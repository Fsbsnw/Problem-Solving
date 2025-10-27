#include <iostream>
#include <vector>

using namespace std;

const int TOP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M, Answer = 11;
int Depth = 0;
int bx = 0, by = 0;
int rx = 0, ry = 0;
vector<vector<char>> Board;

bool IsInBoard(int x, int y)
{
    return (0 <= x && x < N && 0 <= y && y < M && (Board[x][y] != '#' && Board[x][y] != 'O'));
}

bool IsGameOver(int x, int y)
{
    return Board[x][y] == 'O';
}

void TiltBoard(int Direction)
{
    int bbx = bx, bby = by;
    int rrx = rx, rry = ry;
    
    Board[bx][by] = '.';
    Board[rx][ry] = '.';
    
    while (IsInBoard(bbx, bby))
    {
        bbx += dx[Direction]; bby += dy[Direction];
    }
    
    while (IsInBoard(rrx, rry))
    {
        rrx += dx[Direction]; rry += dy[Direction];
    }
    
    if (IsGameOver(bbx, bby) || IsGameOver(rrx, rry))
    {
        bx = bbx; by = bby;
        rx = rrx; ry = rry;
        return;
    }
    
    bbx -= dx[Direction]; bby -= dy[Direction];
    rrx -= dx[Direction]; rry -= dy[Direction];
    
    if (bbx == rrx && bby == rry)
    {
        switch (Direction)
        {
            case TOP:
                if (bx < rx) rrx -= dx[Direction];
                else bbx -= dx[Direction];
                break;
                
            case RIGHT:
                if (by < ry) bby -= dy[Direction];
                else rry -= dy[Direction];
                break;
                
            case DOWN:
                if (bx < rx) bbx -= dx[Direction];
                else rrx -= dx[Direction];
                break;
                
            case LEFT:
                if (by < ry) rry -= dy[Direction];
                else bby -= dy[Direction];
                break;
        }
    }
    
    bx = bbx; by = bby;
    rx = rrx; ry = rry;
    
    Board[bx][by] = 'B';
    Board[rx][ry] = 'R';
}

void PlayBeadGame(int PrevDirection)
{
    if (Depth > 10 || IsGameOver(bx, by)) return;
    if (IsGameOver(rx, ry))
    {
        Answer = min(Answer, Depth);
        return;
    }
    
    for (int Direction = 0; Direction < 4; ++Direction)
    {
        if (PrevDirection == TOP && Direction == DOWN) continue;
        if (PrevDirection == RIGHT && Direction == LEFT) continue;
        if (PrevDirection == DOWN && Direction == TOP) continue;
        if (PrevDirection == LEFT && Direction == RIGHT) continue;
        
        vector<vector<char>> Temp = Board;
        int bbx = bx, bby = by;
        int rrx = rx, rry = ry;
        ++Depth;
        
        TiltBoard(Direction);
        
        if (bx != bbx || by != bby || rx != rrx || ry != rry)
        {
            PlayBeadGame(Direction);
        }
        
        --Depth;
        bx = bbx, by = bby;
        rx = rrx, ry = rry;
        Board = Temp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    Board.assign(N, vector<char>(M));
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Board[i][j];
            
            if (Board[i][j] == 'R') { rx = i; ry = j; }
            else if (Board[i][j] == 'B') { bx = i; by = j; }
        }
    }
    
    PlayBeadGame(-1);
    
    cout << ((Answer == 11) ? -1 : Answer);

    return 0;
}