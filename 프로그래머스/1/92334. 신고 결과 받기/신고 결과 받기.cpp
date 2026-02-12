#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct ReportList
{
    set<string> Others;
    int SelfCount = 0;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, ReportList> ReportMap;
    set<string> ReportedUsers;
    
    for (string s : report)
    {
        stringstream ss(s);
        string from, to;
        
        ss >> from >> to;
        
        if (ReportMap[from].Others.count(to) == 0)
        {
            ReportMap[from].Others.insert(to);
            ReportMap[to].SelfCount++;
            if (ReportMap[to].SelfCount >= k)
                ReportedUsers.insert(to);
        }
    }
    
    vector<int> answer;
    
    for (string s : id_list)
    {
        int Count = 0;
        for (string Target : ReportMap[s].Others)
        {
            if (ReportedUsers.count(Target) == 1) Count++;
        }
        answer.push_back(Count);
    }
    
    return answer;
}