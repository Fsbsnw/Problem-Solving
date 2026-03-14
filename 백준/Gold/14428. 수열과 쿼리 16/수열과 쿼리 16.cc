#include <iostream>

using namespace std;

const int MAX = 100001;

int Arr[MAX];
pair<int, int> Seg[MAX * 4];

pair<int, int> Init(int Node, int Left, int Right)
{
    if (Left == Right) return Seg[Node] = make_pair(Arr[Left], Left);
    
    int Mid = (Left + Right) / 2;
    pair<int, int> LeftPair = Init(Node * 2, Left, Mid);
    pair<int, int> RightPair = Init(Node * 2 + 1, Mid + 1, Right);
    
    if (LeftPair.first > RightPair.first) swap(LeftPair, RightPair);
    
    return Seg[Node] = LeftPair;
}

pair<int, int> Update(int Node, int Left, int Right, int Index, int Value)
{
    if (Index < Left || Right < Index) return Seg[Node];
    if (Left == Right) return Seg[Node] = make_pair(Value, Index);
    
    int Mid = (Left + Right) / 2;
    pair<int, int> LeftPair = Update(Node * 2, Left, Mid, Index, Value);
    pair<int, int> RightPair = Update(Node * 2 + 1, Mid + 1, Right, Index, Value);
    if (LeftPair.first > RightPair.first) swap(LeftPair, RightPair);
    
    return Seg[Node] = LeftPair;
}

pair<int, int> Print(int Node, int Left, int Right, int Start, int End)
{
    if (Right < Start || End < Left) return make_pair(1000000001, 100001);
    if (Start <= Left && Right <= End) return Seg[Node];
    if (Left == Right) return Seg[Node];
    
    int Mid = (Left + Right) / 2;
    pair<int, int> LeftPair = Print(Node * 2, Left, Mid, Start, End);
    pair<int, int> RightPair = Print(Node * 2 + 1, Mid + 1, Right, Start, End);
    
    if (LeftPair.first > RightPair.first) swap(LeftPair, RightPair);
    
    return LeftPair;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; ++i) cin >> Arr[i];
    
    Init(1, 1, N);
    
    int M;
    cin >> M;
    
    for (int i = 1; i <= M; ++i)
    {
        int c, a, b;
        cin >> c >> a >> b;
        
        if (c == 1)
        {
            Update(1, 1, N, a, b);
        }
        else
        {
            cout << Print(1, 1, N, a, b).second << '\n';
        }
    }

    return 0;
}