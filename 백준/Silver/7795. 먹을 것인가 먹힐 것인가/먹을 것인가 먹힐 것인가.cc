#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary(int x, vector<int>& arr)
{
    int l = 0, r = arr.size() - 1, m = 0;
    while (l <= r)
    {
        m = (l + r) / 2;
        
        if (x <= arr[m])
        {
            r = m - 1;
        }
        else if (x > arr[m])
        {
            l = m + 1;
        }
    }
    return r + 1;
}

int main()
{
    int t, n, m;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        vector<int> arr1, arr2;
        
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            arr1.push_back(temp);
        }
        
        for (int k = 0; k < m; k++)
        {
            int temp;
            cin >> temp;
            arr2.push_back(temp);
        }
        
        sort(arr2.begin(), arr2.end());
        
        int answer = 0;
        
        for (int idx : arr1)
        {
            answer += binary(idx, arr2);
        }
        
        cout << answer << endl;
    }
    return 0;
}
