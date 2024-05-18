#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> lis;

int LowerBound(int num)
{
    int left = 0, right = lis.size() - 1;
    
    while (left <= right)
    {
        int mid = (left + right) / 2;
        
        if (lis[mid] <= num)
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

int LIS()
{
    lis.push_back(0);
    
    for (int i = 0; i < n; i++)
    {
        if (lis.back() < arr[i]) 
        {
            lis.push_back(arr[i]);
        }
        else
        {
            int idx = LowerBound(arr[i]);
            lis[idx] = arr[i];
        }
    }
    
    return lis.size() - 1;
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++) 
    {
        int temp; cin >> temp;
        arr.push_back(temp);
    }
    
    cout << n - LIS();
    
    return 0;
}
