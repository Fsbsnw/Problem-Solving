#include <iostream>
#include <queue>

using namespace std;

int DeltaX[4] = {-1, 0, 1, 0};
int DeltaY[4] = {0, 1, 0, -1};

int N, M;
int Direction;
int CleanedRoomCount = 0;
int Room[50][50];
bool Cleaned[50][50];

bool IsInValidRange(int X, int Y)
{
    return (0 <= X && X < N && 0 <= Y && Y < M);
}

void StartCleaning(int X, int Y)
{
    // 1
    if (!Cleaned[X][Y] && !Room[X][Y])
    {
        Cleaned[X][Y] = true;
        CleanedRoomCount++;
    }
    
    // 2-0
    bool bAllSidesClean = true;
    for (int Dir = 0; Dir < 4; Dir++)
    {
        int NextX = X + DeltaX[Dir];
        int NextY = Y + DeltaY[Dir];
        
        if (IsInValidRange(NextX, NextY) && !Room[NextX][NextY] && !Cleaned[NextX][NextY])
        {
            bAllSidesClean = false;
        }
    }
    
    // 2
    if (bAllSidesClean)
    {
        int BackX = X - DeltaX[Direction];
        int BackY = Y - DeltaY[Direction];
        
        // 2-1
        if (IsInValidRange(BackX, BackY) && !Room[BackX][BackY])
        {
            StartCleaning(BackX, BackY);
        }
        
        // 2-2
        else
        {
            return;
        }
    }
    // 3
    else
    {
        // 3-1
        Direction = (Direction + 3) % 4;
        
        int ForwardX = X + DeltaX[Direction];
        int ForwardY = Y + DeltaY[Direction];
        
        // 3-2
        if (IsInValidRange(ForwardX, ForwardY) && !Cleaned[ForwardX][ForwardY] && !Room[ForwardX][ForwardY])
        {
            StartCleaning(ForwardX, ForwardY);
        }
        // 3-3
        else
        {
            StartCleaning(X, Y);
        }
    }
}

int main()
{
    cin >> N >> M;
    
    int StartX, StartY;

    cin >> StartX >> StartY >> Direction;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Room[i][j];
        }
    }
    
    StartCleaning(StartX, StartY);
    
    cout << CleanedRoomCount;

    return 0;
}