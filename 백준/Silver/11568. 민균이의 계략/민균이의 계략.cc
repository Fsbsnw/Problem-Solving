#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> dp;
    for (int i = 0; i < n; i++)
    {
        auto idx = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (idx == dp.end())
        {
            dp.push_back(arr[i]);
        }
        else
        {
            *idx = arr[i];
        }
    }
    
    cout << dp.size();

    return 0;
}