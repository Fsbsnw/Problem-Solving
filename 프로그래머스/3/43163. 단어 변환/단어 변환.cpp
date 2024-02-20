#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {        
    if (find(words.begin(), words.end(), target) == words.end()) return 0;
    
    vector<int> visited(words.size(), 0);
    queue<pair<string, int>> arr;
    int answer = 50;
    
    arr.push(make_pair(begin, 0));
    
    while (!arr.empty())
    {
        string now = arr.front().first;
        int nowCnt = arr.front().second;
        arr.pop();
        
        for (int j = 0; j < words.size(); j++)
        {
            if (visited[j]) continue;
            
            int difCnt = 0;
            for (int i = 0; i < words[j].size(); i++)
            {
                if (words[j][i] != now[i]) difCnt++;
            }
            
            if (difCnt == 1)
            {
                if (words[j] == target) 
                {
                    answer = min(answer, nowCnt + 1);
                }
                else
                {
                    arr.push(make_pair(words[j], nowCnt + 1));
                    visited[j] = 1;
                }
            }
        }
    }
    
    return answer;
}