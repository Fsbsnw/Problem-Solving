#include <iostream>

using namespace std;

int main()
{
    int E, S, M;
    cin >> E >> S >> M;
    
    int Count = 1;
    int Earth = 1;
    int Sun = 1;
    int Moon = 1;
    
    while (!(Earth == E && Sun == S && Moon == M))
    {
        Earth = (Earth + 1 > 15) ? 1 : Earth + 1;
        Sun = (Sun + 1 > 28) ? 1 : Sun + 1;
        Moon = (Moon + 1 > 19) ? 1 : Moon + 1;
        Count++;
    }
    
    cout << Count;

    return 0;
}