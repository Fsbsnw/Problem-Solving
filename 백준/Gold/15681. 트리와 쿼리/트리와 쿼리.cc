#include <iostream>
#include <vector>

using namespace std;

vector<int> node[100001];
bool visited[100001];
int dp[100001];
int n, r, q;

int dfs(int now)
{
    if (dp[now] != 0) return dp[now];
    
    visited[now] = true;
    int temp = 1;
    for (int i : node[now])
    {
        if (visited[i]) continue;
        temp += dfs(i);
    }
    dp[now] = temp;
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r >> q;
    
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    
    dfs(r);
    
    for (int i = 0; i < q; i++)
    {
        int query;
        cin >> query;
        
        cout << dp[query] << '\n';
    }
    return 0;
}