#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
bool visited[100001];

int dij(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (visited[now]) continue;
        visited[now] = true;
        
        if (now == k) return cost;
        
        if (now + 1 <= 100000) 
        {
            pq.push(make_pair(-(cost + 1), now + 1));
        }
        if (now - 1 >= 0)
        {
            pq.push(make_pair(-(cost + 1), now - 1));
        }
        
        if (now * 2 <= 100000) 
        {
            pq.push(make_pair(-cost, now * 2));
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> n >> k;
    fill(visited, visited + k + 1, false);
    
    cout << dij(n);
    
    return 0;
}
