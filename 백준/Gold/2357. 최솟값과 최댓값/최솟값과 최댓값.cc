#include <iostream>

using namespace std;

using ll = long long;

ll Arr[100001];
ll SegMax[400001];
ll SegMin[400001];

ll InitMin(int Node, int Left, int Right)
{
    if (Left == Right) return SegMin[Node] = Arr[Left];
    int Mid = (Left + Right) / 2;
    return SegMin[Node] = min(InitMin(Node * 2, Left, Mid), InitMin(Node * 2 + 1, Mid + 1, Right));
}

ll InitMax(int Node, int Left, int Right)
{
    if (Left == Right) return SegMax[Node] = Arr[Left];
    int Mid = (Left + Right) / 2;
    return SegMax[Node] = max(InitMax(Node * 2, Left, Mid), InitMax(Node * 2 + 1, Mid + 1, Right));
}

ll GetMin(int Node, int Left, int Right, int Start, int End)
{
    if (End < Left || Right < Start) return 1000000001;
    if (Start <= Left && Right <= End) return SegMin[Node];
    int Mid = (Left + Right) / 2;
    return min(GetMin(Node * 2, Left, Mid, Start, End), GetMin(Node * 2 + 1, Mid + 1, Right, Start, End));
}

ll GetMax(int Node, int Left, int Right, int Start, int End)
{
    if (End < Left || Right < Start) return 0;
    if (Start <= Left && Right <= End) return SegMax[Node];
    int Mid = (Left + Right) / 2;
    return max(GetMax(Node * 2, Left, Mid, Start, End), GetMax(Node * 2 + 1, Mid + 1, Right, Start, End));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 0; i <= 400000; ++i) SegMin[i] = 1000000001;
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) cin >> Arr[i];
    
    InitMin(1, 1, N);
    InitMax(1, 1, N);
    
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << GetMin(1, 1, N, a, b) << ' ' << GetMax(1, 1, N, a, b) << '\n';
    }

    return 0;
}