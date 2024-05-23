#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> path;
vector<int> parent;

int Find(int a)
{
    if (a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
    int A = Find(a);
    int B = Find(b);
    
    if (A < B) parent[B] = A;
    else parent[A] = B;
}

int main()
{
    cin >> n >> m;
    graph.resize(n + 1, vector<int>(n + 1, 0));
    parent.resize(n + 1);
    
    for (int i = 1; i <= n; i++) parent[i] = i;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
            
            if (graph[i][j]) Union(i, j);
        }
    }
    
    for (int i = 1; i <= m; i++) 
    {
        int temp;
        cin >> temp;
        path.push_back(temp);
    }
    
    for (int i = 0; i < path.size() - 1; i++)
    {
        int x = path[i];
        int y = path[i + 1];
        
        if (parent[x] != parent[y])
        {
            cout << "NO";
            exit(0);
        }
    }

    cout << "YES";
    
    return 0;
}
