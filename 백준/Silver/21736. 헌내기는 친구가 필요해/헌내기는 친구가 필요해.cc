#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;
int FoundFriendCount = 0;
char Campus[601][601];
bool Visited[601][601];

void FindFriendInCampus(int x, int y)
{
    Visited[x][y] = true;
    
    for (int Dir = 0; Dir < 4; Dir++)
    {
        int nx = x + dx[Dir];
        int ny = y + dy[Dir];
        
        if (0 <= nx && nx < N && 0 <= ny && ny < M && !Visited[nx][ny] && Campus[nx][ny] != 'X')
        {
            if (Campus[nx][ny] == 'P')
            {
                FoundFriendCount++;
            }
            FindFriendInCampus(nx, ny);
        }
    }
}

int main()
{
    cin >> N >> M;
    
    int StartX, StartY;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Campus[i][j];
            
            if (Campus[i][j] == 'I')
            {
                StartX = i;
                StartY = j;
            }
        }
    }
    
    FindFriendInCampus(StartX, StartY);
    
    if (FoundFriendCount > 0)
    {
        cout << FoundFriendCount;
    }
    else
    {
        cout << "TT";
    }

    return 0;
}