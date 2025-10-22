#include <vector>
#include <iostream>
#define MAX 3001

using namespace std;

bool Prime[MAX];

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 2; i <= MAX; ++i) Prime[i] = true;
    
    for (int i = 2; i * i <= MAX; ++i)
    {
        if (!Prime[i]) continue;
        for (int j = i * i; j <= MAX; j += i) Prime[j] = false;
    }
    
    int n = nums.size();
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                int num = nums[i] + nums[j] + nums[k];
                if (Prime[num]) answer++;
            }
        }
    }

    return answer;
}