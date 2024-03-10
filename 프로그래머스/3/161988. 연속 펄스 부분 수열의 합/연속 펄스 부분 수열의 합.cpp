#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<long long> dp1(sequence.size(), 0);
    vector<long long> dp2(sequence.size(), 0);
    
    dp1[0] = sequence[0];
    dp2[0] = -sequence[0];
    answer = max(dp1[0], dp2[0]);
    for (int i = 1; i < sequence.size(); i++)
    {
        dp1[i] = max((long long)sequence[i], dp2[i - 1] + sequence[i]);
        dp2[i] = max((long long)-sequence[i], dp1[i - 1] - sequence[i]);
        answer = max(answer, dp1[i]);
        answer = max(answer, dp2[i]);
    }
    
    return answer;
}