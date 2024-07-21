#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int t, c; cin >> t >> c;
        pq.push({t, c});
    }
    
    int timer = 0;
    while (!pq.empty())
    {
        int arrived = pq.top().first;
        int tcost = pq.top().second;
        pq.pop();
        
        if (timer < arrived) timer = arrived;
        timer += tcost;
    }
    
    cout << timer;

    return 0;
}