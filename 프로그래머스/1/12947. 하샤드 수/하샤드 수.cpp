#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int temp = x, result = 0;
    bool answer = true;
    
    while (temp > 0)
    {
        result += temp % 10;
        temp /= 10;
    }
    if (x % result != 0)
    {
        answer = false;
    }    
    return answer;
}