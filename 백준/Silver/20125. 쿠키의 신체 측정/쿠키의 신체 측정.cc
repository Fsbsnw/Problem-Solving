#include <iostream>
#include <vector>

using namespace std;

int N;
int hx = 0, hy = 0;
vector<vector<char>> CookieMap;

bool IsBody(int x, int y)
{
    return (0 <= x && x < N && 0 <= y && y < N && CookieMap[x][y] == '*');
}

int main()
{
    cin >> N;
    
    CookieMap.assign(N, vector<char>(N));
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> CookieMap[i][j];
            
            if (i > 0 && j > 0 && (CookieMap[i - 1][j] == '*' && CookieMap[i][j - 1] == '*') && hx == 0 && hy == 0)
            {
                hx = i; hy = j;
            }
        }
    }
    
    int tx = hx - 1, ty = hy, tc = 0;
    
    while (IsBody(tx, ty))
    {
        ++tc;
        --tx;
    }
    
    int lax = hx, lay = hy - 1, lac = 0;
    
    while (IsBody(lax, lay))
    {
        ++lac;
        --lay;
    }
    
    int rax = hx, ray = hy + 1, rac = 0;
    
    while (IsBody(rax, ray))
    {
        ++rac;
        ++ray;
    }
    
    int dwx = hx + 1, dwy = hy, dwc = 0;
    
    while (IsBody(dwx, dwy))
    {
        ++dwc;
        ++dwx;
    }
    
    int llx = dwx, lly = hy - 1, llc = 0;
    
    while (IsBody(llx, lly))
    {
        ++llc;
        ++llx;
    }
    
    int rlx = dwx, rly = hy + 1, rlc = 0;
    
    while (IsBody(rlx, rly))
    {
        ++rlc;
        ++rlx;
    }
    
    cout << hx + 1 << ' ' << hy + 1 << '\n';
    cout << lac << ' ' << rac << ' ' << dwc << ' ' << llc << ' ' << rlc;
    return 0;
}