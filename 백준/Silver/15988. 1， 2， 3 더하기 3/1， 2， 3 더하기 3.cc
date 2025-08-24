#include <iostream>

using namespace std;

#define MAX 1000000
#define MOD 1000000009

long long DP[1000001];

int main()
{
    int N;
    cin >> N;
    
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    
    for (int i = 4; i <= MAX; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 3]) % MOD;
    }
    
    for (int Case = 0; Case < N; Case++)
    {
        int T;
        cin >> T;
        
        cout << DP[T] << '\n';
    }

    return 0;
}