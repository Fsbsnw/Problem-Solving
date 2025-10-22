#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<int> Counts(N + 2);
    
    for (int Stage : stages)
    {
        Counts[Stage]++;
    }
    
    vector<pair<float, int>> temp;
    
    int Length = stages.size();
    for (int i = 1; i <= N; ++i)
    {
        float Fail = (Length == 0) ? 0.f : float(Counts[i]) / float(Length);
        temp.push_back({Fail, i});
        Length -= Counts[i];
    }
    
    sort(temp.begin(), temp.end(), 
        [](const pair<float, int>& a, const pair<float, int>& b)
         {
             return (a.first == b.first) ? a.second < b.second : a.first > b.first;
         }
    );
    
    for (pair<float, int> Fails : temp)
    {
        answer.push_back(Fails.second);
    }
    
    return answer;
}