#include <iostream>

using namespace std;

int Stickers[100001][2];
int DP[100001][2];

int main()
{
    int T;
    cin >> T;
    
    for (int Case = 0; Case < T; Case++)
    {
        int N;
        cin >> N;
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> Stickers[j][i];
            }
        }
        
        DP[1][0] = Stickers[1][0];
        DP[1][1] = Stickers[1][1];
        DP[2][0] = Stickers[1][1] + Stickers[2][0];
        DP[2][1] = Stickers[1][0] + Stickers[2][1];
        
        for (int j = 3; j <= N; j++)
        {
            DP[j][0] = max(
                DP[j - 1][1] + Stickers[j][0],
                DP[j - 2][1] + Stickers[j][0]
            );
            DP[j][1] = max(
                DP[j - 1][0] + Stickers[j][1],
                DP[j - 2][0] + Stickers[j][1]
            );
        }
        
        cout << max(DP[N][0], DP[N][1]) << '\n';
    }

    return 0;
}