#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    if (s.size() == 0) return 0;
    
    int answer = 0, left = 0, right = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        int temp = 0;
        
        if (i > 0 && i < s.size() - 1 && s[i - 1] == s[i + 1])
        {
            left = i - 1;
            right = i + 1;
            temp = 1;
            
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
                temp += 2;
            }
        }
        answer = max(answer, temp);
        
        if (i > 0 && s[i - 1] == s[i])
        {
            left = i - 1;
            right = i;
            temp = 0;
            while (left >= 0 && s[left] == s[right])
            {
                left--;
                right++;
                temp += 2;
            }
        }

        answer = max(answer, temp);
    }
    
    answer = (answer == 0) ? 1 : answer;
    return answer;
}