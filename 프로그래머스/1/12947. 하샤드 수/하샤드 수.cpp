#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int temp = x, result = 0;
    
    while (temp > 0)
    {
        result += temp % 10;
        temp /= 10;
    }
    return x % result == 0;
}