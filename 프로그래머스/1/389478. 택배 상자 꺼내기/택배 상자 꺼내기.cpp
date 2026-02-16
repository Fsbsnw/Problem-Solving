#include <string>
#include <vector>

using namespace std;

int GetColumn(int target, int w)
{
    int row = (target - 1) / w;
    int result = (target - 1) % w;
    if (row % 2 == 1) result = (w - 1) - result;
    
    return result;
}

int solution(int n, int w, int num) {
    int cnt = 0;
    int col = GetColumn(num, w);
    
    for (; num <= n; ++num)
    {
        if (GetColumn(num, w) == col) ++cnt;
    }
    
    return cnt;
}