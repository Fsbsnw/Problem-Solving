#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long prime(long long num) {
    for (long long i = 1; i < sqrt(num) + 1; i++)
    {
        if (i * i == num)
        {
            return (i + 1) * (i + 1);
        }
    }
    return -1;
}

long long solution(long long n) {
    long long answer = prime(n);
    return answer;
}