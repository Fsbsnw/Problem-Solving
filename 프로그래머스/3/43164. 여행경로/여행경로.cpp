#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool cmp(vector<string> &a, vector<string> &b)
{
    return (a[1] < b[1]);
}

vector<string> dfs(vector<string> &now, vector<vector<string>> &list, vector<string> answer, vector<int> visited)
{
    answer.push_back(now[0]);
    if (answer.size() == list.size())
    {
        answer.push_back(now[1]);
        
        return answer;
    }
    
    for (int i = 0; i < list.size(); i++)
    {
        if (now[1] == list[i][0] && !visited[i])
        {
            visited[i] = 1;
            vector<string> result = dfs(list[i], list, answer, visited);
            if (!result.empty()) return result;
            visited[i] = 0;
        }
    }
    
    return {};
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), cmp);
    vector<int> visit(tickets.size(), 0);
    
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] == "ICN")
        {
            visit[i] = 1;
            vector<string> answer2 = dfs(tickets[i], tickets, {}, visit);
            if (!answer2.empty()) return answer2;
            visit[i] = 0;
        }
    }
}