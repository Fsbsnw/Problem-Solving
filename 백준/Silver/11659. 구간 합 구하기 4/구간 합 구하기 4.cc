#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    
    vector<int> Numbers(N + 1);
    vector<int> DP(N + 1);
    
    for (int i = 1; i <= N; i++)
    {
        cin >> Numbers[i];
        DP[i] = DP[i - 1] + Numbers[i];
    }
    
    for (int Case = 0; Case < M; Case++)
    {
        int I, J; cin >> I >> J;
        
        cout << DP[J] - DP[I - 1] << '\n';
    }

    return 0;
}