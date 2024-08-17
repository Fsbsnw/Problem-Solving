#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    string A, B;
    cin >> A >> B;

    int lenA = A.length();
    int lenB = B.length();

    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1, 0));

    for (int i = 0; i <= lenA; i++) dp[i][0] = i;  
    for (int j = 0; j <= lenB; j++) dp[0][j] = j;  

    for (int i = 1; i <= lenA; i++) 
    {
        for (int j = 1; j <= lenB; j++) 
        {
            if (A[i - 1] == B[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1]; 
            } 
            else 
            {
                dp[i][j] = min({dp[i - 1][j] + 1,   
                                dp[i][j - 1] + 1,   
                                dp[i - 1][j - 1] + 1});  
            }
        }
    }

    cout << dp[lenA][lenB] << endl;

    return 0;
}
