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
    
    int mmax = pq.top();
    pq.pop();
    
    int result = 0;
    while (!pq.empty())
    {
        int num = pq.top();
        pq.pop();
        
        result += mmax + num;
    }
    
    cout << result;

    return 0;
}