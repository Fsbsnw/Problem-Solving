#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int value[31][31];

int main()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> value[i][j];
        }
    }
    
    int result = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            for (int k = j + 1; k <= m; k++)
            {
                int temp = 0;
                for (int x = 1; x <= n; x++)
                {
                   temp += max({value[x][i], value[x][j], value[x][k]});
                }
                result = max(result, temp);
            }
        }
    }
    
    cout << result;

    return 0;
}