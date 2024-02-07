#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int cnt = 0;
    stack<int> stack;
    
    for (int i : ingredient) 
    {
        if (i == 1)
        {
            if (!stack.empty() && stack.top() == 3)
            {
                stack.pop();
                stack.pop();
                stack.pop();
                cnt++;
            }
            else
            {
                stack.push(i);
            }
        }
        else
        {
            if (!stack.empty())
            {
                if (stack.top() == i - 1)
                {
                    stack.push(i);
                }
                else
                {
                    stack.push(0);
                }
            }
        }
    }
    
    return cnt;
}