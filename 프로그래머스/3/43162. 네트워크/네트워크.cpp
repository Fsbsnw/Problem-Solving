#include <string>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& net, int idx)
{
    if (!net[idx][idx]) return false;
    
    net[idx][idx] = 0;
    
    for (int i = 0; i < net.size(); i++)
    {
        if (net[idx][i])
        {
            dfs(net, i);
        }
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (computers[i][i] && dfs(computers, i))
        {
            answer++;
        }
    }
    
    return answer;
}