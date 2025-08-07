#include <iostream>
#include <vector>
#include <string>

using namespace std;

void InputMatrix(vector<vector<int>>& Matrix, int N, int M) 
{
    string Line;
    for (int i = 0; i < N; i++) 
    {
        cin >> Line;
        for (int j = 0; j < M; j++) 
        {
            Matrix[i][j] = Line[j] - '0';
        }
    }
}

bool IsSame(const vector<vector<int>>& A, const vector<vector<int>>& B, int N, int M) 
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}

int main() 
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> InitialMatrix(N, vector<int>(M));
    vector<vector<int>> TargetMatrix(N, vector<int>(M));

    InputMatrix(InitialMatrix, N, M);
    InputMatrix(TargetMatrix, N, M);

    int CalcCount = 0;
    for (int i = 0; i <= N - 3; i++) 
    {
        for (int j = 0; j <= M - 3; j++) 
        {
            if (InitialMatrix[i][j] != TargetMatrix[i][j]) 
            {
                for (int x = i; x < i + 3; x++)
                {
                    for (int y = j; y < j + 3; y++)
                    {
                        InitialMatrix[x][y] ^= 1;
                    }
                }
                CalcCount++;
            }
        }
    }

    cout << (IsSame(InitialMatrix, TargetMatrix, N, M) ? CalcCount : -1);
    return 0;
}
