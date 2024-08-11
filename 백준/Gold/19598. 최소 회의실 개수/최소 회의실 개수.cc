#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 987654321

struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first; 
    }
};

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start, end; cin >> start >> end;
        pq.push({start, end});
    }
    
    priority_queue<int, vector<int>, greater<int>> rooms;
    
    while (!pq.empty())
    {
        int start_time = pq.top().first;
        int end_time = pq.top().second;
        pq.pop();
        
        if (rooms.empty() || rooms.top() > start_time)
        {
            rooms.push(end_time);
        }
        else
        {
            rooms.pop();
            rooms.push(end_time);
        }
    }

    cout << rooms.size();

    return 0;
}