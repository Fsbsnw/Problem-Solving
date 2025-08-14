#include <iostream>

using namespace std;

string A, B;
int MAX = 0;
int DP[4001][4001];

int main()
{
    cin >> A >> B;
        
    for (int i = 1; i <= A.size(); i++) 
    {
        for (int j = 1; j <= B.size(); j++) 
        {
            if (A[i - 1] == B[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
                MAX = max(MAX, DP[i][j]);
            }
        }
    }
    
    cout << MAX;

    return 0;
}