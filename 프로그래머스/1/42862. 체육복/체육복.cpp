#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<bool> students(n + 2, true);
    set<int> lostSet(lost.begin(), lost.end());
    set<int> reserveSet(reserve.begin(), reserve.end());
    
    for (int i : reserve)
    {
        lostSet.erase(i);
    }
    
    int result = n - lostSet.size();
    
    for (int i : lost)
    {
        reserveSet.erase(i);
    }
    
    for (int i : lostSet)
    {
        students[i] = false;
    }
    
    for (int i : reserveSet)
    {
        if (!students[i - 1])
        {
            students[i - 1] = true;
            ++result;
            continue;
        }
        
        if (!students[i + 1])
        {
            students[i + 1] = true;
            ++result;
            continue;
        }
    }
    return result;
}
