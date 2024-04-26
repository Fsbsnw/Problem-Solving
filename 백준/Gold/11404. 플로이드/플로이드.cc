#include <iostream>

using namespace std;

int INF = 987654321;
int v[101][101];

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) fill(v[i], v[i] + 101, INF);
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (v[a][b]) v[a][b] = min(v[a][b], c);
        else v[a][b] = c;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (k == i || k == j) continue;
                if (i == j) v[i][j] = 0;
                
                if (v[i][j] > v[i][k] + v[k][j])
                {
                    v[i][j] = v[i][k] + v[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (v[i][j] == INF) cout << 0 << ' ';
            else cout << v[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
