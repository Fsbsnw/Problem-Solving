#include <iostream>
#include <queue>

using namespace std;

int diff[6][3] =
{
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3}
};

struct DIFF
{
    int a, b, c;
};

int n;
int scv[3];
int visited[61][61][61];

int dfs(int a, int b, int c)
{
    queue<DIFF> q;
    visited[a][b][c] = 1;
    q.push({a, b, c});
    
    while (!q.empty())
    {
        int first = q.front().a;
        int second = q.front().b;
        int third = q.front().c;
        q.pop();
        
        if (visited[0][0][0]) break;
        
        for (int i = 0; i < 6; i++)
        {
            int nfirst = max(0, first - diff[i][0]);
            int nsecond = max(0, second - diff[i][1]);
            int nthird = max(0, third - diff[i][2]);
            
            if (visited[nfirst][nsecond][nthird]) continue;
            
            visited[nfirst][nsecond][nthird] = visited[first][second][third] + 1;
            q.push({nfirst, nsecond, nthird});
        }
    }
    
    return visited[0][0][0] - 1;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> scv[i];
    
    cout << dfs(scv[0], scv[1], scv[2]);
    
    return 0;
}