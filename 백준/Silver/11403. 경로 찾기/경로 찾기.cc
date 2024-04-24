#include <iostream>

using namespace std;

int n;
int v[101][101];

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
        }
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (v[i][k] && v[k][j])
                {
                    v[i][j] = 1;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
