#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> Tree[40001];
int DP[40001];
int Depths[40001];
int Parents[40001];
bool Visited[40001];

void InitDepth(int Node, int Depth, int Parent)
{
    Parents[Node] = Parent;
    Depths[Node] = Depth;
    Visited[Node] = true;
    
    int CurrDist = DP[Node];
    
    for (const pair<int, int>& Pair : Tree[Node])
    {
        int Child = Pair.first;
        int Cost = Pair.second;
        if (Visited[Child]) continue;
        DP[Child] = CurrDist + Cost;
        InitDepth(Child, Depth + 1, Node);
    }
}

void LCA(int A, int B)
{
    int a = A;
    int b = B;
    
    while (A != B)
    {
        if (Depths[A] == Depths[B])
        {
            A = Parents[A];
            B = Parents[B];
        }
        else if (Depths[A] < Depths[B])
        {
            B = Parents[B];
        }
        else
        {
            A = Parents[A];            
        }
    }
    
    cout << DP[a] + DP[b] - 2 * DP[A] << '\n';
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
    
    InitDepth(1, 0, 0);
    
    int M;
    cin >> M;
    
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        
        LCA(a, b);
    }
    return 0;
}