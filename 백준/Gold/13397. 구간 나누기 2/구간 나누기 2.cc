#include <iostream>

using namespace std;

int n, m, mmax = 0;
int arr[5000];

int counting(int mid)
{
    int cnt = 1, minVal = arr[0], maxVal = arr[0];
    
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
        
        if (maxVal - minVal > mid) 
        {
            cnt++;
            minVal = arr[i];
            maxVal = arr[i];
        }
    }
    
    return cnt;
}

int binary()
{
    int left = 0, right = mmax, result = 0;
    
    while (left <= right)
    {
        int mid = (left + right) / 2;
        
        if (counting(mid) <= m)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return result;
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > mmax) mmax = arr[i];
    }
    
    cout << binary();
    
    return 0;
}
