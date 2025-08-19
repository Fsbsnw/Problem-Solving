#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int DP[1001][1001];
    
    string First, Second;
    cin >> First >> Second;
    
    First.insert(0, " ");
    Second.insert(0, " ");
    
    for (int i = 1; i < First.size(); i++)
    {
        for (int j = 1; j < Second.size(); j++)
        {
            if (First[i] == Second[j])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
            }
        }
    }
    
    string Result;
    int i = First.size() - 1;
    int j = Second.size() - 1;
    
    while (i > 0 && j > 0)
    {
        if (First[i] == Second[j])
        {
            Result += First[i];
            i--; 
            j--;
        }
        else if (DP[i-1][j] > DP[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    
    reverse(Result.begin(), Result.end());
    
    cout << DP[First.size() - 1][Second.size() - 1] << '\n' << Result;

    return 0;
}