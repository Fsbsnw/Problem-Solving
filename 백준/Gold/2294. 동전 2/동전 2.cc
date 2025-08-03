#include <iostream>
#include <set>
#include <vector>

#define MAX 10001

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    
    set<int> CoinSet;
    
    for (int Case = 0; Case < N; Case++)
    {
        int Coin;
        cin >> Coin;
    
        CoinSet.insert(Coin);
    }
    
    int CoinNum = CoinSet.size();
    vector<int> DP(K + 1, MAX);
    DP[0] = 0;
    
    for (int Coin : CoinSet)
    {
        for (int i = Coin; i <= K; i++)
        {
            DP[i] = min(DP[i - Coin] + 1, DP[i]);
        }
    }
    
    int Result = (DP[K] == MAX) ? -1 : DP[K];
    
    cout << Result;

    return 0;
}