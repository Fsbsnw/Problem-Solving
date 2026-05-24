#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {   
    unordered_map<string, int> partmap;
    
    for (const string& name : participant)
    {
        partmap[name] += 1;
    }
    for (const string& name : completion)
    {
        partmap[name] -= 1;
        if (partmap[name] <= 0)
        {
            partmap.erase(name);
        }
    }
    return partmap.begin()->first;;
}