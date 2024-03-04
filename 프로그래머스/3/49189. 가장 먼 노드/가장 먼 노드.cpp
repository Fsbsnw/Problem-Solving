#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> arr(n + 1, vector<int>());
    vector<int> visited(n + 1, 0);
    queue<pair<int, int>> bfs;
    vector<int> max_edge;
    
    bfs.push(make_pair(1, 0));
    visited[1] = 1;
    
    for (vector<int> i : edge)
    {
        arr[i[0]].push_back(i[1]);
        arr[i[1]].push_back(i[0]);
    }
    
    while (!bfs.empty())
    {
        pair<int, int> now = bfs.front();
        bfs.pop();
        bool found = false;
        
        for (int i = 0; i < arr[now.first].size(); i++)
        {
            if (!visited[arr[now.first][i]])
            {
                bfs.push(make_pair(arr[now.first][i], now.second + 1));
                visited[arr[now.first][i]] = 1;
                found = true;
            }
        }
        if (!found)
        {
            max_edge.push_back(now.second);
        }
    }
    
    int maxVal = *max_element(max_edge.begin(), max_edge.end());
    
    return count(max_edge.begin(), max_edge.end(), maxVal);;
}