#include <iostream>

using namespace std;

typedef long long ll;

int N, M, K;
ll Arr[1000001];
ll Tree[1000000 * 4];

void TreeInsert(int Node, int Left, int Right, int Index)
{
    if (Index < Left || Right < Index) return;
    
    Tree[Node] += Arr[Index];
    
    if (Left != Right)
    {
        int Mid = (Left + Right) / 2;
        TreeInsert(Node * 2, Left, Mid, Index);
        TreeInsert(Node * 2 + 1, Mid + 1, Right, Index);
    }
}

void TreeUpdate(int Node, int Left, int Right, int Index, ll Diff)
{
    if (Index < Left || Right < Index) return;
    
    Tree[Node] += Diff;
    
   if (Left != Right)
   {
        int Mid = (Left + Right) / 2;
        TreeUpdate(Node * 2, Left, Mid, Index, Diff);
        TreeUpdate(Node * 2 + 1, Mid + 1, Right, Index, Diff);
   }
}

ll TreeSum(int Node, int Left, int Right, int Start, int End)
{
    if (Right < Start || End < Left) return 0;
    if (Start <= Left && Right <= End) return Tree[Node];
    
    int Mid = (Left + Right) / 2;
    return TreeSum(Node * 2, Left, Mid, Start, End) + TreeSum(Node * 2 + 1, Mid + 1, Right, Start, End);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> Arr[i];
        
        TreeInsert(1, 0, N - 1, i);
    }
    
    for (int i = 0; i < M + K; ++i)
    {
        int a, b;
        ll c;
        
        cin >> a >> b >> c;
        
        if (a == 1)
        {
            ll Diff = c - Arr[b - 1];
            Arr[b - 1] = c;
            TreeUpdate(1, 0, N - 1, b - 1, Diff);
        }
        else
        {
            cout << TreeSum(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}