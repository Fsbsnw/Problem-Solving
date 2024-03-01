#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> musics;
    unordered_map<string, vector<pair<int, int>>> musicIdx;
    vector<pair<int, string>> mv;
    
    for (int i = 0; i < genres.size(); i++)
    {
        musics[genres[i]] += plays[i];
        musicIdx[genres[i]].push_back(make_pair(plays[i], i));
    }
    
    for (auto& s : musics)
    {
        mv.push_back(make_pair(s.second, s.first));
    }
    
    for (auto& c : musicIdx)
    {
        sort(c.second.begin(), c.second.end(), compare);
    }
    
    sort(mv.begin(), mv.end(), greater<pair<int, string>>());
    
    for (int i = 0; i < mv.size(); i++)
    {
        for (int j = 0; j < 2 && j < musicIdx[mv[i].second].size(); j++)
        {
            answer.push_back(musicIdx[mv[i].second][j].second);
        }
    }
    
    return answer;
}