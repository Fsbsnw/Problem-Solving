#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int>& command : commands)
    {
        int i = command[0];
        int j = command[1];
        int k = command[2];
        
        vector<int> copied(array.begin() + i - 1, array.begin() + j);
        sort(copied.begin(), copied.end());
        
        answer.push_back(copied[k - 1]);
    }
    
    return answer;
}