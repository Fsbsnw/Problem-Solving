#include <iostream>

using namespace std;

int N;
int Cost[1000][3];
int DP[3];

int main()
{
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> Cost[i][0] >> Cost[i][1] >> Cost[i][2];
    }
    
    DP[0] = Cost[0][0];
    DP[1] = Cost[0][1];
    DP[2] = Cost[0][2];
    
    for (int i = 1; i < N; ++i)
    {
        int R = min(DP[1], DP[2]) + Cost[i][0];
        int G = min(DP[0], DP[2]) + Cost[i][1];
        int B = min(DP[0], DP[1]) + Cost[i][2];
        
        DP[0] = R;
        DP[1] = G;
        DP[2] = B;
    }
    
    cout << min(DP[0], min(DP[1], DP[2]));

    return 0;
}