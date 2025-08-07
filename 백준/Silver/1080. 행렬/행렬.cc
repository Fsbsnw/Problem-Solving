#include <iostream>
#include <vector>

using namespace std;

void Reverse(int& Value)
{
    Value = (Value == 0) ? 1 : 0;
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> InitialMatrix(N, vector<int>(M));
    vector<vector<int>> TargetMatrix(N, vector<int>(M));
    string line;

    for (int i = 0; i < N; i++)
    {
        cin >> line;
        for (int j = 0; j < M; j++)
        {
            InitialMatrix[i][j] = line[j] - '0';
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        cin >> line;
        for (int j = 0; j < M; j++)
        {
            TargetMatrix[i][j] = line[j] - '0';
        }
    }
    
    int CalcCount = 0;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < M - 2; j++)
        {
            if (InitialMatrix[i][j] == TargetMatrix[i][j]) continue;
            
            for (int x = i; x < i + 3; x++)
            {
                for (int y = j; y < j + 3; y++)
                {
                    Reverse(InitialMatrix[x][y]);
                }
            }
            CalcCount++;
        }
    }
    
    bool bSame = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (InitialMatrix[i][j] != TargetMatrix[i][j])
            {
                bSame = false;
                break;
            }
        }
        if (!bSame) break;
    }
    
    int Result = (bSame) ? CalcCount : -1;
    cout << Result;

    return 0;
}