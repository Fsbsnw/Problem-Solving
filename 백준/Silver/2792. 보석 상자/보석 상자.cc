#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> Jewel(M);
    
    for (int i = 0; i < M; ++i)
    {
        cin >> Jewel[i];
    }
    
    int l = 1, r = *max_element(Jewel.begin(), Jewel.end());
    int Result = r;
    
    while (l <= r)
    {
        int m = (l + r) / 2;
        long long count = 0;
        
        for (int num : Jewel)
        {
            count += (num + m - 1) / m;
            if (count > N) break;
        }
        
        if (count > N)
        {
            l = m + 1;
        }
        else
        {
            Result = m;
            r = m - 1;
        }
    }
    
    cout << Result;

    return 0;
}