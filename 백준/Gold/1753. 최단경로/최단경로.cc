#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e;
vector<vector<pair<int, int>>> connections;
int dis[20001];
int INF = 200000;

void dij(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dis[start] = 0;
    
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (dis[now] < cost) continue;
        
        for (int i = 0; i < connections[now].size(); i++)
        {
            int ncost = connections[now][i].first + cost;
            int next = connections[now][i].second;
            
            if (dis[next] > ncost)
            {
                dis[next] = ncost;
                pq.push(make_pair(-ncost, next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> v >> e;
    connections.resize(v + 1);
    for (int i = 1; i <= v; i++) dis[i] = INF;
    
    int s;
    cin >> s;
    
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        connections[a].push_back(make_pair(c, b));
    }
    
    dij(s);
    
    for (int i = 1; i <= v; i++)
    {
        if (dis[i] != INF)
        {
            cout << dis[i] << '\n';
        }
        else
        {
            cout << "INF" << '\n';
        }
    }

    return 0;
}
