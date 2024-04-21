#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 500000;
int n, m, s, t;
vector<vector<pair<int, int>>> v;
int dist[5001];

void dij(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < v[now].size(); i++)
        {
            int ncost = v[now][i].first + cost;
            int next = v[now][i].second;
            
            if (dist[next] > ncost)
            {
                dist[next] = ncost;
                pq.push(make_pair(ncost, next));
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    v.resize(n + 1);
    fill(dist, dist + 5001, INF);
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        v[a].push_back(make_pair(c, b));
        v[b].push_back(make_pair(c, a));
    }

    cin >> s >> t;
    
    dij(s);
    cout << dist[t];
    
    return 0;
}
