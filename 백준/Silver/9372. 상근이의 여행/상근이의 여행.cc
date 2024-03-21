#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        
        for (int j = 0; j < m; j++)
        {
            int x, y;
            cin >> x >> y;
        }
        
        cout << n - 1 << endl;
    }

    return 0;
}
