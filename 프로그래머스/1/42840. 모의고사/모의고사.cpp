#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> arr3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int a = 0, b = 0, c = 0;
    
    for (int i = 0; i < answers.size(); ++i)
    {
        int num = answers[i];
        
        if (num == arr1[i % arr1.size()])
        {
            ++a;
        }
        if (num == arr2[i % arr2.size()])
        {
            ++b;
        }
        if (num == arr3[i % arr3.size()])
        {
            ++c;
        }
    }
    
    vector<pair<int, int>> temp = {{a, 1}, {b, 2}, {c, 3}};
    sort(temp.begin(), temp.end(), greater<pair<int, int>>());
    
    int max_value = temp[0].first;
    for (auto pair : temp)
    {
        if (answer.empty() || max_value == pair.first)
        {
            answer.push_back(pair.second);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}