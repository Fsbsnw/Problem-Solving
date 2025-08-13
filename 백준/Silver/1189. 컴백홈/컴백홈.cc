#include <iostream>

using namespace std;

int R, C, K;
int PathCount = 0;
int DeltaX[4] = {-1, 1, 0, 0};
int DeltaY[4] = {0, 0, -1, 1};
char Map[5][5];
bool Visited[5][5];

void FindPath(int X, int Y, int Depth)
{
    if (X == 0 && Y == C - 1)
    {
        if (Depth == K) PathCount++;
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        int NextX = X + DeltaX[i];
        int NextY = Y + DeltaY[i];
        
        if (
            0 <= NextX && NextX < R && 
            0 <= NextY && NextY < C && 
            !Visited[NextX][NextY] && 
            Map[NextX][NextY] != 'T'
            )
        {
            Visited[NextX][NextY] = true;
            FindPath(NextX, NextY, Depth + 1);
            Visited[NextX][NextY] = false;
        }
    }
}

int main()
{
    cin >> R >> C >> K;
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> Map[i][j];
        }
    }
    
    Visited[R - 1][0] = true;
    FindPath(R - 1, 0, 1);
    
    cout << PathCount;

    return 0;
}