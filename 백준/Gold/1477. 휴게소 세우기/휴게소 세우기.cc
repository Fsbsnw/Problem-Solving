#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, L;
    cin >> N >> M >> L;
    
    vector<int> Rest(N);
    
    for (int i = 0; i < N; ++i)
    {
        cin >> Rest[i];
    }
    
    Rest.push_back(0);
    Rest.push_back(L);
    
    sort(Rest.begin(), Rest.end());
    
    int l = 1, r = L - 1;
    
    while (l <= r)
    {
        int m = (l + r) / 2;
        int k = 0;
        
        for (int i = 1; i < Rest.size(); ++i)
        {
            int dist = Rest[i] - Rest[i - 1];
            
            k += ((dist % m) == 0) ? (dist / m - 1) : (dist / m);
        }
        
        if (k > M)
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