#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0, prev = 0, now = 0;
    
    for(int i = 0; i < dartResult.size(); i++) {
        if(isdigit(dartResult[i])) {
            prev = now;
            if(dartResult[i + 1] == '0') {
                now = 10;
                i++;
            } else {
                now = dartResult[i] - '0';
            }
        } else {
            if(dartResult[i] == 'D') {
                now = now * now;
            } else if(dartResult[i] == 'T') {
                now = now * now * now;
            }
            
            if(dartResult[i + 1] == '*') {
                answer -= prev;
                prev *= 2;
                now *= 2;
                answer += prev;
                i++;
            } else if(dartResult[i + 1] == '#') {
                now *= -1;
                i++;
            }
            answer += now;
        }
    }
    
    return answer;
}