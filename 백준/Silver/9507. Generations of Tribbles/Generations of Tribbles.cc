#include <iostream>

using namespace std;

long long DP[68];

int main()
{
    int T;
    cin >> T;
    
    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    
    for (int i = 4; i <= 67; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3] + DP[i - 4];
    }
    
    for (int i = 0; i < T; i++)
    {
        int Num;
        cin >> Num;
        
        cout << DP[Num] << '\n';
    }

    return 0;
}