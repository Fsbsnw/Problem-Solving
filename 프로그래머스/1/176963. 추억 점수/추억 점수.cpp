#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> h;
    for (int i = 0; i < name.size(); i++) {
        h[name[i]] = yearning[i];
    }
    
    for (vector<string> list : photo) {
        int sum = 0;
        for (string s : list) {
            if (h.find(s) != h.end()) {
                sum += h[s];
            }
        }
        answer.push_back(sum);
    }
    
    return answer;
}