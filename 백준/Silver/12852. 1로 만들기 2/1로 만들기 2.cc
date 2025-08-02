#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int Prev[1000001];
    int DP[1000001];
    
    memset(Prev, -1, sizeof(Prev));
    
    for (int i = 2; i <= N; i++)
    {
        DP[i] = DP[i - 1] + 1;
        Prev[i] = i - 1;
        
        if (i % 3 == 0 && DP[i / 3] + 1 < DP[i])
        {
            DP[i] = DP[i / 3] + 1;
            Prev[i] = i / 3;
        }
        if (i % 2 == 0 && DP[i / 2] + 1 < DP[i])
        {
            DP[i] = DP[i / 2] + 1;
            Prev[i] = i / 2;
        }
    }
    
    cout << DP[N] << '\n';
    
    int Idx = N;
    while (Idx != -1)
    {
        cout << Idx << ' ';
        Idx = Prev[Idx];
    }

    return 0;
}