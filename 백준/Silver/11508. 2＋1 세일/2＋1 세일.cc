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
    
    int result = 0;
    while (pq.size() >= 3)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.pop();
        
        result += a + b;
    }
    
    while (!pq.empty())
    {
        int a = pq.top();
        pq.pop();
        
        result += a;
    }
    
    cout << result;

    return 0;
}