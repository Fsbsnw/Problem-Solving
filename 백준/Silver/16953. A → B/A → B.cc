#include <iostream>

using namespace std;

int main()
{
    int a, b, cnt = 1;
    cin >> a >> b;
    
    while (b > a)
    {
        if (b % 10 == 1)
        {
            b = (b - 1) / 10;
            cnt++;
        }
        else
        {
            if (b % 2 != 0)
            {
                cout << -1;
                return 0;
            }
            b /= 2;
            cnt++;
        }
    }
    
    cnt = (b == a) ? cnt : -1;
    cout << cnt;
    return 0;
}
