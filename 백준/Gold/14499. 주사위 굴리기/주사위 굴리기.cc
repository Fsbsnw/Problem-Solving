#include <iostream>
#include <vector>

using namespace std;

const int RIGHT = 1, LEFT = 2, UP = 3, DOWN = 4;

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int N, M, K;
pair<int, int> Dice = {0, 0};
vector<vector<int>> Map;
vector<vector<int>> DiceInfo(4, vector<int>(3, 0));

bool IsValidMove(const pair<int, int>& DicePos)
{
    return (0 <= DicePos.first && DicePos.first < N && 
            0 <= DicePos.second && DicePos.second < M);
}

void MoveDice(int Direction)
{
    pair<int, int> TempDice = Dice;
    
    TempDice.first += dx[Direction];
    TempDice.second += dy[Direction];
    
    if (!IsValidMove(TempDice)) return;
    
    Dice = TempDice;
    
    switch (Direction)
    {
        case RIGHT:
            {
                int One = DiceInfo[1][0];
                int Two = DiceInfo[1][1];
                int Three = DiceInfo[1][2];
                int Four = DiceInfo[3][1];
                
                DiceInfo[1][0] = Two;
                DiceInfo[1][1] = Three;
                DiceInfo[1][2] = Four;
                DiceInfo[3][1] = One;
            }
            break;
            
        case LEFT:
            {
                int One = DiceInfo[1][0];
                int Two = DiceInfo[1][1];
                int Three = DiceInfo[1][2];
                int Four = DiceInfo[3][1];
                
                DiceInfo[1][0] = Four;
                DiceInfo[1][1] = One;
                DiceInfo[1][2] = Two;
                DiceInfo[3][1] = Three;
            }
            break;
            
        case UP:
            {
                int One = DiceInfo[0][1];
                int Two = DiceInfo[1][1];
                int Three = DiceInfo[2][1];
                int Four = DiceInfo[3][1];
                
                DiceInfo[0][1] = Four;
                DiceInfo[1][1] = One;
                DiceInfo[2][1] = Two;
                DiceInfo[3][1] = Three;
            }
            break;
            
        case DOWN:
            {
                int One = DiceInfo[0][1];
                int Two = DiceInfo[1][1];
                int Three = DiceInfo[2][1];
                int Four = DiceInfo[3][1];
                
                DiceInfo[0][1] = Two;
                DiceInfo[1][1] = Three;
                DiceInfo[2][1] = Four;
                DiceInfo[3][1] = One;
            }
            break;
    }
    
    if (Map[Dice.first][Dice.second] != 0) 
    {
        DiceInfo[1][1] = Map[Dice.first][Dice.second];
        Map[Dice.first][Dice.second] = 0;
    }
    else Map[Dice.first][Dice.second] = DiceInfo[1][1];
    
    cout << DiceInfo[3][1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> Dice.first >> Dice.second >> K;
    
    Map.assign(N, vector<int>(M, 0));
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Map[i][j];
        }
    }
    
    for (int i = 0; i < K; ++i)
    {
        int Direction;
        cin >> Direction;
        
        MoveDice(Direction);
    }
    
    return 0;
}