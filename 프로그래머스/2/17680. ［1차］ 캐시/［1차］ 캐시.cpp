#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void ToLower(vector<string>& Cities)
{
    for (string& s : Cities)
        for (char& c : s)
            c = tolower(c);
}

int IsCacheHit(const deque<string>& Cache, string Target)
{
    for (int i = 0; i < Cache.size(); ++i)
    {
        if (Target == Cache[i]) return i;
    }
    return -1;
}

int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0;
    
    ToLower(cities);
    
    deque<string> Cache;
    
    for (string s : cities)
    {
        int CacheIndex = IsCacheHit(Cache, s);
        // 찾은 경우, 사용 순서 재할당
        if (CacheIndex != -1)
        {
            Cache.erase(Cache.begin() + CacheIndex);
            Cache.push_back(s);
            answer += 1;
        }
        // 못 찾은 경우
        else
        {
            // 캐시 공간 여유 없음
            if (Cache.size() >= cacheSize && !Cache.empty()) Cache.pop_front();
            if (cacheSize > 0) Cache.push_back(s);
            answer += 5;
        }
    }
    
    return answer;
}