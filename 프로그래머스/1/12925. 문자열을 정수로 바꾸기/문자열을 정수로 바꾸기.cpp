#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    if (s[0] == '-')
    {
        answer = -atoi(s.substr(1).c_str());
    }
    else
    {
        answer = atoi(s.c_str());
    }
    return answer;
}