#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int cnt = 0;
    while (true)
    {
        bool IsZero = true;
        for (int i = 0; i < n; i++)
        {
            if (!arr[i]) continue;
            
            if (arr[i] % 2 == 1)
            {
                arr[i]--;
                cnt++;
            }
            if (arr[i]) IsZero = false;
        }
        
        if (IsZero) break;
        
        for (int i = 0; i < n; i++)
        {
            if (arr[i]) arr[i] /= 2;
        }
        cnt++;
    }
    
    cout << cnt;

    return 0;
}