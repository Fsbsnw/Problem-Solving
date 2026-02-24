#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s)
{
    vector<char> stack;
    
    for (char c : s)
    {
        if (c == '(')
        {
            stack.push_back(c);
        }
        else
        {
            if (!stack.empty() && stack.back() == '(') stack.pop_back();
            else stack.push_back(c);
        }
    }
    
    return stack.empty() ? true : false;
}