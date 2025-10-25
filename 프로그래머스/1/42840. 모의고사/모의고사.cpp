#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> Base1 = {1, 2, 3, 4, 5};
    vector<int> Base2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> Base3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int Count1 = 0, Count2 = 0, Count3 = 0;
    
    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == Base1[i % 5]) ++Count1;
        if (answers[i] == Base2[i % 8]) ++Count2;
        if (answers[i] == Base3[i % 10]) ++Count3;
    }
    
    vector<int> answer;
    
    int MaxCount = max({Count1, Count2, Count3});
    
    if (Count1 == MaxCount) answer.push_back(1);
    if (Count2 == MaxCount) answer.push_back(2);
    if (Count3 == MaxCount) answer.push_back(3);    
    
    return answer;
}