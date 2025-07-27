#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N;
int NormalCount = 0;
int ColorBlindCount = 0;
char Region[101][101];
bool NormalVisited[101][101];
bool ColorBlindVisited[101][101];

void FindNormalRegion(int x, int y)
{
    NormalVisited[x][y] = true;
    char CurrentColor = Region[x][y];
    
    for (int Dir = 0; Dir < 4; Dir++)
    {
        int nx = x + dx[Dir];
        int ny = y + dy[Dir];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || NormalVisited[nx][ny]) continue;
        
        if (Region[nx][ny] == CurrentColor)
        {
            FindNormalRegion(nx, ny);
        }
    }
}

bool AreBothRedOrGreen(int x, int y, int nx, int ny)
{
    return (Region[x][y] == 'R' || Region[x][y] == 'G') && (Region[nx][ny] == 'R' || Region[nx][ny] == 'G');
}

void FindColorBlindRegion(int x, int y)
{
    ColorBlindVisited[x][y] = true;
    char CurrentColor = Region[x][y];
    
    for (int Dir = 0; Dir < 4; Dir++)
    {
        int nx = x + dx[Dir];
        int ny = y + dy[Dir];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || ColorBlindVisited[nx][ny]) continue;
        
        if (Region[nx][ny] == CurrentColor || AreBothRedOrGreen(x, y, nx, ny))
        {
            FindColorBlindRegion(nx, ny);
        }
    }
}

int main()
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Region[i][j];
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!NormalVisited[i][j])
            {
                FindNormalRegion(i, j);
                NormalCount++;
            }
            if (!ColorBlindVisited[i][j])
            {
                FindColorBlindRegion(i, j);
                ColorBlindCount++;
            }
        }
    }
    
    cout << NormalCount << ' ' << ColorBlindCount;
    
    return 0;
}