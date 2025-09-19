#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 100000 * 101

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);     

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> Graph(N + 1, vector<int>(N + 1, INF));
    
    for (int i = 1; i <= N; ++i) Graph[i][i] = 0;
    
    for (int i = 0; i < M; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        
        Graph[x][y] = min(Graph[x][y], w);
    }
    
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (Graph[i][j] == INF) cout << "0 ";
            else cout << Graph[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}