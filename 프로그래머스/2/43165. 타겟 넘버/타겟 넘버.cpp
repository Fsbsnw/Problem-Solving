#include <string>
#include <vector>

using namespace std;

int result = 0;
int targetSum = 0;

void DFS(vector<int>& numbers, int index, int sum)
{
    if (index >= numbers.size())
    {
        if (sum == targetSum) ++result;
        return;
    }
    DFS(numbers, index + 1, sum + numbers[index]);
    DFS(numbers, index + 1, sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    targetSum = target;
    
    DFS(numbers, 0, 0);
    
    return result;
}