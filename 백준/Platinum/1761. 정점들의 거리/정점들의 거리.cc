#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> Tree[40001];
int DP[40001];
int Depths[40001];
int Parents[40001][17];
bool Visited[40001];

void InitTree(int Node, int Depth, int Parent)
{
    Parents[Node][0] = Parent;
    Depths[Node] = Depth;
    Visited[Node] = true;
    
    int CurrDist = DP[Node];
    
    for (const pair<int, int>& Pair : Tree[Node])
    {
        int Child = Pair.first;
        int Cost = Pair.second;
        if (Visited[Child]) continue;
        DP[Child] = CurrDist + Cost;
        InitTree(Child, Depth + 1, Node);
    }
}

int LCA(int A, int B)
{
    if (Depths[A] < Depths[B]) swap(A, B);
    
    int Diff = Depths[A] - Depths[B];
    
    for (int i = 0; i < 17; ++i)
    {
        if (Diff & (1 << i)) A = Parents[A][i];
    }
    
    if (A == B) return A;
    
    for (int i = 16; i >= 0; --i)
    {
        if (Parents[A][i] != Parents[B][i])
        {
            A = Parents[A][i];
            B = Parents[B][i];
        }
    }
    return Parents[A][0];
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
        int a, b, c;
        cin >> a >> b >> c;
        
        Tree[a].push_back({b, c});
        Tree[b].push_back({a, c});
    }
    
    InitTree(1, 0, 0);
    
    for (int i = 1; i < 17; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            Parents[j][i] = Parents[Parents[j][i - 1]][i - 1];
        }
    }
    
    int M;
    cin >> M;
    
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        
        cout << DP[a] + DP[b] - 2 * DP[LCA(a, b)] << '\n';
    }
    return 0;
}