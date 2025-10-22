#include <string>
#include <iostream>
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
        float Fail = float(Counts[i]) / float(Length);
        temp.push_back({-Fail, i});
        Length -= Counts[i];
    }
    
    sort(temp.begin(), temp.end());
    
    for (pair<int, int> Fails : temp)
    {
        answer.push_back(Fails.second);
    }
    
    return answer;
}