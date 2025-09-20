#include <iostream>
#include <vector>

using namespace std;

#define INF 101

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> Graph(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i <= N; ++i) Graph[i][i] = 0;
    
    for (int i = 0; i < M; ++i)
    {
        int x, y;
        cin >> x >> y;
        
        Graph[x][y] = 1;
        Graph[y][x] = 1;
    }
    
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (Graph[i][k] < INF && Graph[k][j] < INF)
                    Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
            }
        }
    }
    
    int Result = INF * N;
    int Person = 0;
    for (int i = 1; i <= N; ++i)
    {
        int Temp = 0;
        for (int j = 1; j <= N; ++j)
        {
            if (i == j && Graph[i][j] == INF) continue;
            
            Temp += Graph[i][j];
        }
        if (Temp < Result)
        {
            Result = Temp;
            Person = i;
        }
    }
    
    cout << Person;

    return 0;
}