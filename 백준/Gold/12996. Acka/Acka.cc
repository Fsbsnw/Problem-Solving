#include <iostream>
#include <cstring>

#define MOD 1000000007
typedef long long ll;
using namespace std;

int S, A, B, C;
ll dp[51][51][51][51];

int Album(int s, int a, int b, int c)
{
    if (s == 0)
    {
        if (a == 0 && b == 0 && c == 0) return 1;
        return 0;
    }
    
    ll& result = dp[s][a][b][c];
    if (result != -1) return result;
    
    result = 0;
    
    result += Album(s - 1, a - 1, b, c);
    result += Album(s - 1, a, b - 1, c);
    result += Album(s - 1, a, b, c - 1);
    result += Album(s - 1, a - 1, b - 1, c);
    result += Album(s - 1, a - 1, b, c - 1);
    result += Album(s - 1, a, b - 1, c - 1);
    result += Album(s - 1, a - 1, b - 1, c - 1);
    result %= MOD;
    
    return result;
}

int main ()
{
    memset(dp, -1, sizeof(dp));
    cin >> S >> A >> B >> C;
    cout << Album(S, A, B, C);
    
    return 0;
}