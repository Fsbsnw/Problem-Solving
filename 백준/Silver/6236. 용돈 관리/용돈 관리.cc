#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    int l = 0, r = 0;
    vector<int> Arr(N);
    
    for (int i = 0; i < N; ++i)
    {
        cin >> Arr[i];
        
        l = max(l, Arr[i]);
        r += Arr[i];
    }
    
    while (l <= r)
    {
        int count = 1;
        int m = (l + r) / 2;
        int k = m;
        
        for (int i = 0; i < N; ++i)
        {
            if (Arr[i] <= k) k -= Arr[i];
            else 
            {
                k = m - Arr[i];
                ++count;
            }
        }
        
        if (count > M)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    
    cout << l;

    return 0;
}