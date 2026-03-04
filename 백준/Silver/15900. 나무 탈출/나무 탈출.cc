#include <iostream>
#include <vector>

using namespace std;

int Depth = 0;
vector<int> Tree[500001];

void DFSLeaf(int Node, int Parent, int Dep)
{
    bool bHasChild = false;
    
    for (int Child : Tree[Node])
    {
        if (Child == Parent) continue;
        bHasChild = true;
        
        DFSLeaf(Child, Node, Dep + 1);
    }
    
    if (!bHasChild) Depth += Dep;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    
    DFSLeaf(1, -1, 0);
    
    string Result = (Depth % 2 == 0) ? "No" : "Yes";
    cout << Result;

    return 0;
}