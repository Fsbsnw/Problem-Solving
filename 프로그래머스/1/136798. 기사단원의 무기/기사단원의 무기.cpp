#include <string>
#include <vector>

using namespace std;

int divisor(int num) {
    int cnt = 1;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            cnt++;
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++) {
        int temp = divisor(i);
        if (temp > limit) {
            temp = power;
        }
        answer += temp;
    }
    return answer;
}