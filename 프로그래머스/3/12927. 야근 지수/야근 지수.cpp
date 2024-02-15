#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0, len = works.size();
    
    priority_queue<int> pq(works.begin(), works.end());
    
    for (int i = 0; i < n; i++)
    {
        if (pq.top() > 0)
        {
            int temp = pq.top();
            pq.pop();
            pq.push(temp - 1);
        }
    }
    
    while (!pq.empty())
    {
        answer += (long long)pq.top() * (long long)pq.top();
        pq.pop();
    }
    
    return answer;
}