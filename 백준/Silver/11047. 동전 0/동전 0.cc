#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K; cin >> N >> K;
    vector<int> Coins(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> Coins[i];
    }
    
    int Count = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        int Coin = Coins[i];
        if (Coin <= K)
        {
            Count += (K / Coin);
            K %= Coin;
        }
    }
    
    cout << Count;

    return 0;
}