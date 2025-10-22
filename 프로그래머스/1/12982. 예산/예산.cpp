#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    
    for (int cost : d)
    {
        if (cost > budget) break;
        
        ++answer;
        budget -= cost;
    }
    
    return answer;
}