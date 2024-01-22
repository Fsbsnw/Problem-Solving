#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string s = to_string(n);
    for (char c : s)
    {
        answer += int(c - '0');
    }
    return answer;
}