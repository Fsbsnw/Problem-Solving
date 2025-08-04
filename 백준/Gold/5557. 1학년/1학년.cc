#include <iostream>

using namespace std;

int Numbers[101];
long long DP[101][21];

int main()
{
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        cin >> Numbers[i];
    }
    
    DP[1][Numbers[1]] = 1;
    
    for (int i = 1; i < N; i++)
    {
        for (int Sum = 0; Sum <= 20; Sum++)
        {
            int CurrentNum = Numbers[i];
            if (Sum - CurrentNum >= 0)
            {
                DP[i][Sum] += DP[i - 1][Sum - CurrentNum];
            }
            if (Sum + CurrentNum <= 20)
            {
                DP[i][Sum] += DP[i - 1][Sum + CurrentNum];
            }
        }
    }
    
    cout << DP[N - 1][Numbers[N]];
    
    return 0;
}