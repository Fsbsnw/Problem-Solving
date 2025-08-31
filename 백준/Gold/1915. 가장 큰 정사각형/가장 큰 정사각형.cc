#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    string Map[1001];
    int DP[1001][1001] = { 0 };

    for (int i = 1; i <= N; i++)
    {
        string Temp;
        cin >> Temp;
        Temp.insert(0, " "); 
        Map[i] = Temp;
    }

    int MAX = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (Map[i][j] == '1')
            {
                DP[i][j] = min(min(DP[i - 1][j], DP[i][j - 1]), DP[i - 1][j - 1]) + 1;

                MAX = max(MAX, DP[i][j]);
            }
        }
    }

    cout << MAX * MAX;
    
    return 0;
}
