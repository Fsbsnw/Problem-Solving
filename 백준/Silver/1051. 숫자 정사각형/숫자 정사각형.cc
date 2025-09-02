#include <iostream>

using namespace std;

string Square[50];

int main()
{
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
    {
        cin >> Square[i];
    }
    
    int MAX = 1;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int Range = min(N - i, M - j) - 1;
            
            for (int l = Range; l >= 0; l--)
            {
                if (
                    Square[i][j] == Square[i][j + l] &&
                    Square[i][j + l] == Square[i + l][j] &&
                    Square[i + l][j] == Square[i + l][j + l]
                    )
                {
                    MAX = max(MAX, l + 1);
                }
            }
        }
    }
    
    cout << MAX * MAX;

    return 0;
}
