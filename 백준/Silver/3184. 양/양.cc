#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char Yard[250][250];
bool Visited[250][250];

pair<int, int> FindAnimal(int x, int y)
{
    int Sheep = 0;
    int Wolf = 0;
    
    queue<pair<int, int>> Queue;
    Queue.push({x, y});
    Visited[x][y] = true;
    
    while (!Queue.empty())
    {
        pair<int, int> CurrentPos = Queue.front();
        Queue.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int NextX = dx[i] + CurrentPos.first;
            int NextY = dy[i] + CurrentPos.second;
            
            if (0 <= NextX && NextX < 250 && 0 <= NextY && NextY < 250 && !Visited[NextX][NextY] && Yard[NextX][NextY] != '#')
            {
                Queue.push({NextX, NextY});
                Visited[NextX][NextY] = true;
                
                if (Yard[NextX][NextY] == 'o')
                {
                    Sheep++;
                }
                else if (Yard[NextX][NextY] == 'v')
                {
                    Wolf++;
                }
            }
        }
    }
    return (Sheep > Wolf) ? make_pair(Sheep, 0) : make_pair(0, Wolf);
}

int main()
{
    int R, C;
    cin >> R >> C;
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> Yard[i][j];
        }
    }
    
    int Sheep = 0;
    int Wolf = 0;
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (Visited[i][j]) continue;
            
            pair<int, int> AnimalCount = FindAnimal(i, j);
            Sheep += AnimalCount.first;
            Wolf += AnimalCount.second;
        }
    }
    
    printf("%d %d", Sheep, Wolf);

    return 0;
}