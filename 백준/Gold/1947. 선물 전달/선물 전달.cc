#include <iostream>

using namespace std;

#define MOD 1000000000

int main()
{
    int n; cin >> n;
    
    long long prev1 = 0, prev2 = 1, cur = 0;
    
    for (int i = 1; i <= n; i++)
    {
        cur = (prev1 + prev2) * (i - 1) % MOD;
        prev1 = prev2;
        prev2 = cur;
    }
    
    cout << cur;

    return 0;
}