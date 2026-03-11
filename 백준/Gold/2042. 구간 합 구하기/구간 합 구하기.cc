#include <iostream>

using namespace std;

typedef long long ll;

ll Arr[1000001];
ll Seg[4000001];

ll Init(int Node, int Left, int Right)
{
    if (Left == Right) return Seg[Node] = Arr[Left];
    
    int Mid = (Left + Right) / 2;
    return Seg[Node] = Init(Node * 2, Left, Mid) + Init(Node * 2 + 1, Mid + 1, Right);
}

ll Sum(int Node, int Left, int Right, int Start, int End)
{
    if (End < Left || Right < Start) return 0;
    if (Start <= Left && Right <= End) return Seg[Node];
    
    int Mid = (Left + Right) / 2;
    return Sum(Node * 2, Left, Mid, Start, End) + Sum(Node * 2 + 1, Mid + 1, Right, Start, End);
}

void Update(int Node, int Left, int Right, int Index, ll Diff)
{
    if (Index < Left || Right < Index) return;
    
    Seg[Node] += Diff;
    
    if (Left == Right) return;
    
    int Mid = (Left + Right) / 2;
    Update(Node * 2, Left, Mid, Index, Diff);
    Update(Node * 2 + 1, Mid + 1, Right, Index, Diff);
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    
    for (int i = 1; i <= N; ++i) cin >> Arr[i];
    
    Init(1, 1, N);
    
    for (int i = 0; i < M + K; ++i)
    {
        int c, a;
        ll b;
        cin >> c >> a >> b;
        
        if (c == 1)
        {
            ll Diff = b - Arr[a];
            Arr[a] = b;
            Update(1, 1, N, a, Diff);
        }
        else
        {
            cout << Sum(1, 1, N, a, b) << '\n';
        }
    }
    return 0;
}