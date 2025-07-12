#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M; cin >> N >> M;
    
    vector<int> Numbers(N + 1);
    vector<int> DP(N + 1);
    
    for (int i = 1; i <= N; i++)
    {
        cin >> Numbers[i];
        DP[i] = DP[i - 1] + Numbers[i];
    }
    
    int MaxTemper = -100 * 100000;
    for (int i = M; i <= N; i++)
    {
        int PrefixSum = DP[i] - DP[i - M];
        if (PrefixSum > MaxTemper) MaxTemper = PrefixSum;
    }
    
    cout << MaxTemper;
    
    return 0;
}