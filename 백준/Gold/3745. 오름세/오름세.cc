#include <iostream>
#include <vector>

using namespace std;

int binary(vector<int>& lis, int num)
{
    int left = 0, right = lis.size() - 1;
    
    while (left <= right)
    {
        int mid = (left + right) / 2;
        
        if (lis[mid] < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    return left;
}

void LIS(int n, vector<int>& arr, vector<int>& lis)
{
    for (int i = 0; i < n; i++)
    {
        if (lis.empty() || lis.back() < arr[i])
        {
            lis.push_back(arr[i]);
        }
        else
        {
            int idx = binary(lis, arr[i]);
            lis[idx] = arr[i];
        }
    }
    cout << lis.size() << '\n';
}

int main()
{
    while (true)    
    {
        int n;

        if (!(cin >> n)) break;
        
        vector<int> arr(n, 0);
        vector<int> lis;
        
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        LIS(n, arr, lis);
    }

    return 0;
}
