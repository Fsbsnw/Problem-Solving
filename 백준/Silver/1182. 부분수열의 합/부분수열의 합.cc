#include <iostream>
#include <vector>
using namespace std;

int N, S;
int Count = 0;
vector<int> Arr;

void DFS(int Index, int Sum)
{
    if (Index == N)
    {
        if (Sum == S) Count++;
        return;
    }
    
    DFS(Index + 1, Sum + Arr[Index]);
    DFS(Index + 1, Sum);
}

int main()
{
    cin >> N >> S;
    
    Arr.resize(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
    
    DFS(0, 0);
    
    if (S == 0) Count--;
    
    cout << Count;

    return 0;
}