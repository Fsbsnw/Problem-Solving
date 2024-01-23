#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int cntP = 0, cntY = 0;
    for (char c : s)
    {
        char temp = toupper(c);
        if (temp == 'P')
        {
            cntP++;
        }
        else if (temp == 'Y')
        {
            cntY++;
        }
    }
    bool answer = (cntP == cntY) ? true : false;

    return answer;
}