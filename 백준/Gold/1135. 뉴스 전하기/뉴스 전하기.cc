#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 51;

vector<int> Tree[MAX];

int DFS(int Node)
{
    vector<int> Children;
    
    for (int Child : Tree[Node])
    {
        int ct = DFS(Child);
        Children.push_back(ct);
    }
    
    sort(Children.begin(), Children.end(), greater<int>());
    
    int t = 0;
    for (int i = 0; i < Children.size(); ++i)
    {
        t = max(t, Children[i] + i + 1);
    }
    return t;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int M;
        cin >> M;
        
        if (M != -1) Tree[M].push_back(i);
    }
    
    cout << DFS(0);

    return 0;
}