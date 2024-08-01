#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n; cin >> n;
    priority_queue<int> pq;
    
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        pq.push(temp);
    }
    
    int t = 1;
    int result = 0;
    while (!pq.empty())
    {
        int day = pq.top();
        pq.pop();
        
        result = max(result, t + 1 + day);
        t++;
    }
    
    cout << result;

    return 0;
}