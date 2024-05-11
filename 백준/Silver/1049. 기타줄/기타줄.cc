#include <iostream>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    
    int mp = 1000, mc = 1000;
    
    for (int i = 0; i < m; i++)
    {
        int p, c;
        cin >> p >> c;
        
        if (p < mp) mp = p;
        if (c < mc) mc = c;
    }
    
    int result = 0;
    while (n > 0)
    {
        if (n >= 6) 
        {
            if (6 * mc < mp) result += 6 * mc;
            else result += mp;

            n -= 6;
        }
        else if (n < 6)
        {
            if (n * mc < mp) result += n * mc;
            else result += mp;
            
            n -= n;
        }
    }

    cout << result;
    return 0;
}
