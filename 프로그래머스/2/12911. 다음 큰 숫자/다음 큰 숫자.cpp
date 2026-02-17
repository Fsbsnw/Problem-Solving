#include <string>
#include <vector>

using namespace std;

int binary_zerocount(int Num)
{
    int Result = 0;
    while (Num)
    {
        if (Num % 2 == 1) ++Result;
        Num /= 2;
    }
    return Result;
}

int solution(int n) {
    int answer = 0;
    int cnt = binary_zerocount(n);
    
    for (int i = n + 1; i <= 1000000; ++i)
    {
        if (binary_zerocount(i) == cnt)
        {
            answer = i;
            break;
        }
    }
    return answer;
}