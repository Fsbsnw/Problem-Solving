#include <string>
#include <vector>
#include <set>

using namespace std;

bool IsPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}

set<int> SetNum;
vector<bool> Used;

void FindPrime(string s, string numbers)
{
    if (!s.empty())
    {
        int n = stoi(s);
        if (IsPrime(n)) SetNum.insert(n);
    }
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (Used[i]) continue;
        
        Used[i] = true;
        FindPrime(s + numbers[i], numbers);
        Used[i] = false;
    }
}

int solution(string numbers) {
    Used.resize(numbers.size());
    
    FindPrime("", numbers);
    
    int answer = SetNum.size();
    return answer;
}