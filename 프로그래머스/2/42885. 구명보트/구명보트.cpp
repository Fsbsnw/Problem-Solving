#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) 
{
    vector<bool> rescued(people.size());
    
    sort(people.begin(), people.end());
    
    int answer = 0;
    
    int li = 0, ri = people.size() - 1;
    
    while (li <= ri)
    {
        if (li == ri)
        {
            ++answer;
            break;
        }
        if (people[li] + people[ri] <= limit)
        {
            ++li;
        }
        --ri;
        ++answer;
    }
    
    
    return answer;
}