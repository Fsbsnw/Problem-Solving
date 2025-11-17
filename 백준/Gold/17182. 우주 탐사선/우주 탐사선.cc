#include <iostream>
#include <vector>

using namespace std;

int N, K, MinCost = 100000;
vector<bool> Visited;
vector<vector<int>> Map, FMap;

void Explore(int Cost, int Prev, int Depth)
{
    if (Depth == N)
    {
        MinCost = min(MinCost, Cost);
        return;
    }
    
    for (int i = 0; i < N; ++i)
    {
        if (Visited[i] || Prev == i) continue;
        
        Visited[i] = true;
        Explore(Cost + FMap[Prev][i], i, Depth + 1);
        Visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    
    Map.assign(N, vector<int>(N));
    FMap.assign(N, vector<int>(N));
    Visited.assign(N, false);
    Visited[K] = true;
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Map[i][j];
            FMap[i][j] = Map[i][j];
        }
    }
    
    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                FMap[i][j] = min(FMap[i][j], FMap[i][k] + FMap[k][j]);
            }
        }
    }
    
    Explore(0, K, 1);
    
    cout << MinCost;

    return 0;
}