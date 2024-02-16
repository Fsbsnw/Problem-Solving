#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minpq;
    priority_queue<int, vector<int>, less<int>> maxpq;
    int cnt = 0;
    
    for (string s : operations)
    {
        if (!cnt)
        {
            while (!minpq.empty())
            {
                minpq.pop();
            }
            while (!maxpq.empty())
            {
                maxpq.pop();
            }
        }
        
        if (s[0] == 'I')
        {
            maxpq.push(stoi(s.substr(2)));
            minpq.push(stoi(s.substr(2)));
            cnt++;
        }
        else
        {
            if (!maxpq.empty() && !minpq.empty())
            {
                if (s[2] == '1')
                {
                    maxpq.pop();
                    cnt--;
                }
                else
                {
                    minpq.pop();
                    cnt--;
                }
            }
        }
    }
    
    if (cnt) {
        answer.push_back(maxpq.top());
        answer.push_back(minpq.top());
    } else {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}