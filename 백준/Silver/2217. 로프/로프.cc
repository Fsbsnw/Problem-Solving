#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, mmax = 0;
    cin >> n;
    vector<int> arr;
    
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    for (int i = 0; i < arr.size(); i++)
    {
        mmax = max(mmax, arr[i] * (i + 1));
    }
    
    cout << mmax;
    
    return 0;
}
