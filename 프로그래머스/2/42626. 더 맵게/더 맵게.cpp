#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int score : scoville) pq.push(score);
    
    int answer = 0;
    while (pq.top() < K && pq.size() >= 2)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();
        
        pq.push(a + b * 2);
        ++answer;
    }
    
    if (pq.top() < K) answer = -1;
    
    return answer;
}