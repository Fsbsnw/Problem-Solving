#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> CheckPoint(N);
    
    for (int i = 0; i < N; ++i)
    {
        cin >> CheckPoint[i];
    }
    
    long long l = 1;
    long long r = 1LL * (*min_element(CheckPoint.begin(), CheckPoint.end())) * M;
    
    while (l <= r)
    {
        long long m = (l + r) / 2;
        long long k = 0;
        
        for (int i = 0; i < CheckPoint.size(); ++i)
        {
            k += m / CheckPoint[i];
            if (k >= M) break;
        }
        
        if (k < M)
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