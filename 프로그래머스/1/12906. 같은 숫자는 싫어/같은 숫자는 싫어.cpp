#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for (int n : arr)
    {
        if (answer.empty() || answer[answer.size() - 1] != n)
        {
            answer.push_back(n);
        }
    }
    
    return answer;
}