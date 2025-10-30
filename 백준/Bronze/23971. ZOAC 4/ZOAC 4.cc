#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    
    int MaxCol = ceil(float(h) / float(n + 1));
    int MaxRow = ceil(float(w) / float(m + 1));
    
    cout << MaxCol * MaxRow;

    return 0;
}