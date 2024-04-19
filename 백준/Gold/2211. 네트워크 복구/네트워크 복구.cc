#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> connects;
int parents[1001];
int dist[1001];

void dij(int x)
{
    priority_queue<pair<int, int>> q;
    
    dist[x] = 0;
    q.push(make_pair(x, parents[x]));
    
    while (!q.empty())
    {
        int now = q.top().first;
        int cost = q.top().second;
        q.pop();
        
        for (int i = 0; i < connects[now].size(); i++)
        {
            int next = connects[now][i].first;
            int ncost = connects[now][i].second + cost;
            
            if (dist[next] > ncost)
            {
                dist[next] = ncost;
                parents[next] = now;
                q.push(make_pair(next, ncost));
            }
        }
    }
    
    cout << n - 1 << endl;
    for (int i = 2; i <= n; i++)
    {
        cout << parents[i] << ' ' << i << endl;
    }
}

int main()
{
    cin >> n >> m;
    connects.resize(n + 1);
    fill(dist, dist + 1001, 1000);
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        connects[a].push_back(make_pair(b, c));
        connects[b].push_back(make_pair(a, c));
    }
    
    dij(1);

    return 0;
}
