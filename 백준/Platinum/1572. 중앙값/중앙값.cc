#include <iostream>

using namespace std;

int N, K;
int Arr[250000];
int Tree[250000];
long long Result = 0;

void PlusTree(int Node, int Left, int Right, int Num)
{
    if (Num < Left || Num > Right) return;
    
    ++Tree[Node];
    
    if (Left != Right)
    {
        int Mid = (Left + Right) / 2;
        PlusTree(Node * 2, Left, Mid, Num);
        PlusTree(Node * 2 + 1, Mid + 1, Right, Num);
    }
}

void MinusTree(int Node, int Left, int Right, int Num)
{
    if (Num < Left || Num > Right) return;
    
    --Tree[Node];
    
    if (Left != Right)
    {
        int Mid = (Left + Right) / 2;
        MinusTree(Node * 2, Left, Mid, Num);
        MinusTree(Node * 2 + 1, Mid + 1, Right, Num);
    }
}

void SumMiddleNum(int Node, int Left, int Right, int Count)
{
    if (Left == Right)
    {
        Result += Left;
        return;
    }
    
    int Mid = (Left + Right) / 2;
    
    if (Tree[Node * 2] >= Count)
    {
        SumMiddleNum(Node * 2, Left, Mid, Count);
    }
    else
    {
        SumMiddleNum(Node * 2 + 1, Mid + 1, Right, Count - Tree[Node * 2]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int MAX = 0, MIN = 66666;
    
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> Arr[i];
        MAX = max(MAX, Arr[i]);
        MIN = min(MIN, Arr[i]);
    }
    
    for (int i = 0; i < K; ++i) PlusTree(1, MIN, MAX, Arr[i]);
    SumMiddleNum(1, MIN, MAX, (K + 1) / 2);
    
    for (int i = K; i < N; ++i)
    {
        PlusTree(1, MIN, MAX, Arr[i]);
        MinusTree(1, MIN, MAX, Arr[i - K]);
        SumMiddleNum(1, MIN, MAX, (K + 1) / 2);
    }
    
    cout << Result;
}