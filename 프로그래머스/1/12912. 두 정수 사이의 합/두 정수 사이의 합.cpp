#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    int cntab = a - b + 1;
    long long answer = 0;
    if (cntab % 2 == 0)
    {
        answer = (long long)(a + b) * (long long)(cntab / 2);
    }
    else
    {
        answer = (long long)(a + b) * (long long)(cntab / 2) + (long long)(a + b) / 2;
    }
    return answer;
}