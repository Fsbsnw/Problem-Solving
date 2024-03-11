#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    vector<int> remain(a.size(), 0);
    int mmin;
    
    for (int i = 0; i < a.size(); i++)
    {
        if (i == 0) 
        {
            mmin = a[i];
            remain[i] = 1;
            continue;
        }
        if (a[i] < mmin)
        {
            mmin = a[i];
            remain[i] = 1;
        }
    }
    
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (i == a.size() - 1) 
        {
            mmin = a[i];
            remain[i] = 1;
            continue;
        }
        if (a[i] < mmin)
        {
            mmin = a[i];
            remain[i] = 1;
        }
    }
    
    return count(remain.begin(), remain.end(), 1);
}