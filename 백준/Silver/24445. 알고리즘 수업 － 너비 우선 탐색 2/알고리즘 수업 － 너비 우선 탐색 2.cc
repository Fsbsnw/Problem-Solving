#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, R;
    cin >> N >> M >> R;
    
    vector<int> Visited(N + 1);
    vector<vector<int>> Connections(N + 1, vector<int>());
    for (int i = 0; i < M; i++)
    {
        int V1, V2;
        cin >> V1 >> V2;
        
        Connections[V1].push_back(V2);
        Connections[V2].push_back(V1);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(Connections[i].rbegin(), Connections[i].rend());
    }
    
    int MoveCount = 1;
    deque<int> DQ;
    DQ.push_back(R);
    Visited[R] = MoveCount;
    
    while (!DQ.empty())
    {
        int CurrentPos = DQ.front();
        DQ.pop_front();
        
        for (int NextPos : Connections[CurrentPos])
        {
            if (!Visited[NextPos])
            {
                DQ.push_back(NextPos);
                Visited[NextPos] = ++MoveCount;
            }
        }
    }
    
    for (int i = 1; i <= N; i++)
    {
        cout << Visited[i] << '\n';
    }

    return 0;
}