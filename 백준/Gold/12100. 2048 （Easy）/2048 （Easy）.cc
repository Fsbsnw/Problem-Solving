#include <iostream>
#include <vector>

using namespace std;

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

int N;
int MAX = 0;
vector<vector<int>> Map;

void MoveUp()
{
    for (int i = 0; i < N; i++)
    {
        vector<int> TempValues;
        vector<int> FinalValues;
        
        for (int j = 0; j < N; j++)
        {
            if (Map[j][i] == 0) continue;
            
            TempValues.push_back(Map[j][i]);
        }
        
        if (TempValues.empty()) continue;
        
        int Current = 0;
        
        // 1차 합치기
        for (int k = 0; k < TempValues.size(); ++k)
        {
            if (Current == 0)
            {
                Current = TempValues[k];
            }
            else if (Current == TempValues[k])
            {
                Current *= 2;
                FinalValues.push_back(Current);
                Current = 0;
            }
            else
            {
                FinalValues.push_back(Current);
                Current = TempValues[k];
            }
            if (k == TempValues.size() - 1 && Current != 0) FinalValues.push_back(Current);
        }
        
        for (int k = 0; k < N; ++k) 
        {
            if (k < FinalValues.size()) 
            {
                Map[k][i] = FinalValues[k];
                MAX = max(MAX, FinalValues[k]);
            }
            else Map[k][i] = 0;
        }
    }
}

void MoveDown()
{
    for (int i = 0; i < N; i++)
    {
        vector<int> TempValues;
        vector<int> FinalValues;
        
        for (int j = N - 1; j >= 0; --j)
        {
            if (Map[j][i] == 0) continue;
            
            TempValues.push_back(Map[j][i]);
        }
        
        if (TempValues.empty()) continue;
        
        int Current = 0;
        
        // 1차 합치기
        for (int k = 0; k < TempValues.size(); ++k)
        {
            if (Current == 0)
            {
                Current = TempValues[k];
            }
            else if (Current == TempValues[k])
            {
                Current *= 2;
                FinalValues.push_back(Current);
                Current = 0;
            }
            else
            {
                FinalValues.push_back(Current);
                Current = TempValues[k];
            }
            if (k == TempValues.size() - 1 && Current != 0) FinalValues.push_back(Current);
        }
        
        for (int k = 0; k < N; ++k)
        {
            if (k < FinalValues.size()) 
            {
                Map[N - 1 - k][i] = FinalValues[k];
                MAX = max(MAX, FinalValues[k]);
            }
            else Map[N - 1 - k][i] = 0;
        }
    }
}

void MoveLeft()
{
    for (int i = 0; i < N; i++)
    {
        vector<int> TempValues;
        vector<int> FinalValues;
        
        for (int j = 0; j < N; j++)
        {
            if (Map[i][j] == 0) continue;
            
            TempValues.push_back(Map[i][j]);
        }
        
        if (TempValues.empty()) continue;
        
        int Current = 0;
        
        // 1차 합치기
        for (int k = 0; k < TempValues.size(); ++k)
        {
            if (Current == 0)
            {
                Current = TempValues[k];
            }
            else if (Current == TempValues[k])
            {
                Current *= 2;
                FinalValues.push_back(Current);
                Current = 0;
            }
            else
            {
                FinalValues.push_back(Current);
                Current = TempValues[k];
            }
            if (k == TempValues.size() - 1 && Current != 0) FinalValues.push_back(Current);
        }
        
        for (int k = 0; k < N; ++k) 
        {
            if (k < FinalValues.size()) 
            {
                Map[i][k] = FinalValues[k];
                MAX = max(MAX, FinalValues[k]);
            }
            else Map[i][k] = 0;
        }
    }
}

void MoveRight()
{
    for (int i = 0; i < N; i++)
    {
        vector<int> TempValues;
        vector<int> FinalValues;
        
        for (int j = N - 1; j >= 0; --j)
        {
            if (Map[i][j] == 0) continue;
            
            TempValues.push_back(Map[i][j]);
        }
        
        if (TempValues.empty()) continue;
        
        int Current = 0;
        
        // 1차 합치기
        for (int k = 0; k < TempValues.size(); ++k)
        {
            if (Current == 0)
            {
                Current = TempValues[k];
            }
            else if (Current == TempValues[k])
            {
                Current *= 2;
                FinalValues.push_back(Current);
                Current = 0;
            }
            else
            {
                FinalValues.push_back(Current);
                Current = TempValues[k];
            }
            if (k == TempValues.size() - 1 && Current != 0) FinalValues.push_back(Current);
        }
        
        for (int k = 0; k < N; ++k)
        {
            if (k < FinalValues.size()) 
            {
                Map[i][N - 1 - k] = FinalValues[k];
                MAX = max(MAX, FinalValues[k]);
            }
            else Map[i][N - 1 - k] = 0;
        }
    }
}

void Move(int Direction)
{
    switch (Direction)
    {
        case UP:    MoveUp(); break;
        case DOWN:  MoveDown(); break;
        case LEFT:  MoveLeft(); break;
        case RIGHT: MoveRight(); break;
    }
}

void DFS(int Depth)
{
    if (Depth == 5)
    {
        return;
    }
    
    for (int Dir = 0; Dir < 4; ++Dir)
    {
        vector<vector<int>> TempMap = Map;
        
        Move(Dir);
        DFS(Depth + 1);
        
        Map = TempMap;
    }
}

int main()
{
    cin >> N;
    
    Map.resize(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Map[i][j];
        }
    }
    
    DFS(0);
    
    cout << MAX;

    return 0;
}