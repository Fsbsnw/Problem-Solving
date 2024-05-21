#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 100000000;
int n, m;
vector<int> dist;
vector<vector<pair<int, int>>> graph;
vector<int> parent;

void FindMinCost(int start, int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    vector<int> result = {start};
    dist[start] = 0;
    
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (cost > dist[now]) continue;
        
        for (int i = 0; i < graph[now].size(); i++)
        {
            int ncost = graph[now][i].first + cost;
            int next = graph[now][i].second;
            
            if (ncost < dist[next])
            {
                dist[next] = ncost;
                parent[next] = now;
                pq.push({ncost, next});
            }
        }
    }
    cout << dist[end] << '\n';
}

void FindMinPath(int start, int end)
{
    int idx = end;
    vector<int> result = {end};
    
    while (idx != start)
    {
        result.push_back(parent[idx]);
        idx = parent[idx];
    }
    
    cout << result.size() << '\n';
    for (int i = result.size() - 1; i >= 0; i--) cout << result[i] << ' ';
}

int main()
{
    cin >> n >> m;
    graph.resize(n + 1);
    dist.resize(n + 1, INF);
    parent.resize(n + 1);
    
    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        graph[a].push_back({c, b});
    }
    
    int start, end; 
    cin >> start >> end;
    
    FindMinCost(start, end);
    FindMinPath(start, end);

    return 0;
}
