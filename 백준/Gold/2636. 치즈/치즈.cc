#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int Row, Col;
vector<vector<int>> Cheese(101, vector<int>(101, 0));
int PrefixRemovedCheese[101];
int CheeseCount = 0;

void FindCheeseToRemove(int x, int y, int TimeSpent, vector<vector<bool>>& Visited)
{
    int CheeseToRemove = 0;
    queue<pair<int, int>> Queue;
    Queue.push({x, y});
    Visited[x][y] = true;
    
    while (!Queue.empty())
    {
        pair<int, int> CurrentPos = Queue.front();
        Queue.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = CurrentPos.first + dx[i];
            int ny = CurrentPos.second + dy[i];
            
            if (0 <= nx && nx < Row && 0 <= ny && ny < Col && !Visited[nx][ny])
            {
                Visited[nx][ny] = true;
                
                if (Cheese[nx][ny])
                {
                    CheeseToRemove++;
                    Cheese[nx][ny] = 0;
                }
                else
                {
                    Queue.push({nx, ny});
                }
            }
        }
    }
    PrefixRemovedCheese[TimeSpent] = PrefixRemovedCheese[TimeSpent - 1] + CheeseToRemove;
}

int main()
{
    cin >> Row >> Col;

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cin >> Cheese[i][j];
            CheeseCount += Cheese[i][j];
        }
    }
    
    int Time = 1;
    while (Time < 101 && PrefixRemovedCheese[Time - 1] < CheeseCount)
    {
        vector<vector<bool>> TempVisited(101, vector<bool>(101, false));
        FindCheeseToRemove(0, 0, Time, TempVisited);
        
        Time++;
    }
    printf("%d\n%d", Time - 1, CheeseCount - PrefixRemovedCheese[Time - 2]);

    return 0;
}