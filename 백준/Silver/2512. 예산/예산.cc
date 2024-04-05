#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> cost;

int findMaxBudget(int threshold)
{
    int result = 0;
    
    for (int i : cost)
    {
        if (i >= threshold)
        {
            result += threshold;
        }
        else
        {
            result += i;
        }
    }
    
    return result;
}

void binary(int mmax)
{
    int left = 0, right = mmax, result = 0;
    
    while (left <= right)
    {
        int mid = (left + right) / 2;
        
        if (findMaxBudget(mid) <= mmax)
        {
            left = mid + 1;
            result = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    int temp = accumulate(cost.begin(), cost.end(), 0);
    result = (mmax >= temp) ? *max_element(cost.begin(), cost.end()) : result;
    cout << result;
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cost.push_back(temp);
    }
    
    int budget;
    cin >> budget;
    
    binary(budget);

    return 0;
}
