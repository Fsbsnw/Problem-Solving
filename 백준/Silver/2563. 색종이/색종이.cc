#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Paper[101][101];
    int n; cin >> n;
    
    int BlackPaper = 0;
    
    for (int Case = 0; Case < n; Case++)
    {
        int x, y; cin >> x >> y;
        for (int i = x; i < x + 10; i++)
        {
            for (int j = y; j < y + 10; j++)
            {
                if (Paper[i][j] != 1) 
                {
                    BlackPaper++;
                    Paper[i][j] = 1;
                }
            }
        }
    }
    
    cout << BlackPaper;

    return 0;
}