#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer, result;
    for (int i = 0; i < score.size(); i++) {
        result.push_back(score[i]);
        sort(result.begin(), result.end(), greater<>());
        
        if (result.size() > k) {
            result.pop_back();
        }
        
        answer.push_back(result[result.size() - 1]);
    }
    return answer;
}