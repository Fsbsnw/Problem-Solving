#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int n, m, x;
int INF = 1000000;
vector<pair<int, int>> graph[1001]; 
vector<int> dist;
int resdist[1001];
 
void dij(int s){
    dist.assign(n + 1, INF);
    dist[s] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i].second;
            int ncost = graph[now][i].first + cost;
            
            if(dist[next] > ncost){
                dist[next] = ncost;
                pq.push({ncost, next});
            }
        }
    }
}
 
int main(){
    cin >> n >> m >> x;
    
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(c, b));
    }
    
    for(int i = 1; i <= n; i++){
        dij(i);
        resdist[i] = dist[x];
    }
    
    dij(x);
    
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, resdist[i] + dist[i]);
    }
    
    cout << res;
    
    return 0;
}
