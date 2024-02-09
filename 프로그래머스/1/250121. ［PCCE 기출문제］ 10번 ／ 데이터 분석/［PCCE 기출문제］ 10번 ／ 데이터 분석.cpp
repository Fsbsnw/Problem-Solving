#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    map<string, int> iext = {{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}};
    
    for (vector<int> i : data)
    {
        if (i[iext[ext]] < val_ext)
        {
            answer.push_back(i);
        }
    }
    
    sort(answer.begin(), answer.end(), [&ext, &iext, &sort_by](vector<int> &a, vector<int> &b){
        return a[iext[sort_by]] < b[iext[sort_by]];
    });
    
    return answer;
}