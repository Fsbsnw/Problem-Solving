#include <iostream>
#include <vector>

using namespace std;

int v[21][21];
int res[21][21];

int main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
            res[i][j] = v[i][j];
        }
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == k || j == k) continue;
                
                if (v[i][j] > v[i][k] + v[k][j]) 
                {
                    cout << -1;
                    return 0;
                }
                
                if (v[i][j] == v[i][k] + v[k][j]) 
                {
                    res[i][j] = 0;
                }
            }
        }
    }
    
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            result += res[i][j];
        }
    }
    
    cout << result / 2;
    return 0;
}
