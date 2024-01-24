#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long nnum = num;
    int cnt = 0;
    while (nnum != 1)
    {
        if (nnum % 2 == 0)
        {
            nnum /= 2;
        }
        else
        {
            nnum = nnum * 3 + 1;
        }
        cnt++;
        if (cnt >= 500)
        {
            return -1;
        }
    }
    return cnt;
}