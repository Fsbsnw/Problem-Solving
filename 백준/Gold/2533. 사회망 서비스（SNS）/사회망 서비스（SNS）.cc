#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int DP[1000001][2];
vector<int> Tree[1000001];

void DFS(int Node, int Parent)
{
    DP[Node][0] = 0;
    DP[Node][1] = 1;
    
    for (int Child : Tree[Node])
    {
        if (Child == Parent) continue;
        
        DFS(Child, Node);
        int Child0 = DP[Child][0];
        int Child1 = DP[Child][1];
        DP[Node][0] += Child1;
        DP[Node][1] += min(Child0, Child1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    
    DFS(1, -1);
    
    cout << min(DP[1][0], DP[1][1]);

    return 0;
}