#include <iostream>

using namespace std;

typedef long long ll;

ll Arr[1000001];
ll Tree[4000001];

ll Init(int Left, int Right, int Node)
{
    if (Left == Right) return Tree[Node] = Arr[Left];
    
    int Mid = (Left + Right) / 2;
    
    return Tree[Node] = Init(Left, Mid, Node * 2) + Init(Mid + 1, Right, Node * 2 + 1);
}

void Update(int Left, int Right, int Node, int Index, ll Diff)
{
    if (Index < Left || Right < Index) return;
    
    Tree[Node] += Diff;
    
    if (Left == Right) return;
    
    int Mid = (Left + Right) / 2;
    
    Update(Left, Mid, Node * 2, Index, Diff);
    Update(Mid + 1, Right, Node * 2 + 1, Index, Diff);
}

ll Sum(int Left, int Right, int Start, int End, int Node)
{
    if (End < Left || Right < Start) return 0;
    if (Start <= Left && Right <= End) return Tree[Node];
    
    int Mid = (Left + Right) / 2;
    return Sum(Left, Mid, Start, End, Node * 2) + Sum(Mid + 1, Right, Start, End, Node * 2 + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll N, M, K;
    cin >> N >> M >> K;
    
    for (int i = 1; i <= N; ++i) 
    {
        cin >> Arr[i];
    }
    
    Init(1, N, 1);
    
    for (int i = 0; i < M + K; ++i)
    {
        int c, a;
        ll b;
        cin >> c >> a >> b;
        
        if (c == 1)
        {
            ll Diff = b - Arr[a];
            Arr[a] = b;
            Update(1, N, 1, a, Diff);
        }
        else
        {
            cout << Sum(1, N, a, b, 1) << '\n';
        }
    }

    return 0;
}