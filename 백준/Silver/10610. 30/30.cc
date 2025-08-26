#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string S;
    cin >> S;
    
    sort(S.begin(), S.end(), greater<int>());
    
    int Sum = 0;
    bool bZeroExist = false;
    for (int i = 0; i < S.size(); i++)
    {
        int Temp = S[i] - '0';
        Sum += Temp;
        if (Temp == 0)
        {
            bZeroExist = true;
        }
    }
    
    string Result = "-1";
    if (bZeroExist && Sum % 3 == 0)
    {
        Result = S;
    }
    
    cout << Result;

    return 0;
}