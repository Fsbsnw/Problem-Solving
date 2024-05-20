#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, e, v1, v2;
int INF = 800000;

int FindMinCost(vector<vector<pair<int, int>>>& edge, int start, int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    pq.push({0, start});
    
    vector<int> Distance(n + 1, INF);
    Distance[start] = 0;
    
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < edge[now].size(); i++)
        {
            int ncost = edge[now][i].first + cost;
            int next = edge[now][i].second;
            
            if (ncost < Distance[next])
            {
                Distance[next] = ncost;
                pq.push({ncost, next});
            }
        }
    }
    
    return (Distance[end] == INF) ? -INF : Distance[end];
}

int main()
{
    cin >> n >> e;
    vector<vector<pair<int, int>>> edge(n + 1);
    
    for (int i = 1; i <= e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        edge[a].push_back({c, b});
        edge[b].push_back({c, a});
    }
    
    cin >> v1 >> v2;
    
    int costA = FindMinCost(edge, 1, v1) + FindMinCost(edge, v1, v2) + FindMinCost(edge, v2, n);
    int costB = FindMinCost(edge, 1, v2) + FindMinCost(edge, v2, v1) + FindMinCost(edge, v1, n);
    
    int result = min(costA, costB);
    cout << ((result < 0) ? -1 : result);

    return 0;
}
