#include <iostream>
#include <vector>

using namespace std;

vector<int> Tree[100001];
int DP[100001];

void Accumulate(int Node, int Depth)
{
    for (int Child : Tree[Node])
    {
        DP[Child] += DP[Node];
        Accumulate(Child, Depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i)
    {
        int c;
        cin >> c;
        
        if (c != -1) Tree[c].push_back(i);
    }
    
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        
        DP[a] += b;
    }
    
    Accumulate(1, 0);
    for (int i = 1; i <= n; ++i) cout << DP[i] << ' ';

    return 0;
}