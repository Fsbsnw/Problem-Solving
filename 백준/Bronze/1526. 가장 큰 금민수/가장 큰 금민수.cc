#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    for (int i = N; i >= 1; i--)
    {
        string SNum = to_string(i);
        
        bool bFound = true;
        for (int j = 0; j < SNum.size(); j++)
        {
            if (!(SNum[j] == '4' || SNum[j] == '7'))
            {
                bFound = false;
                break;
            }
        }
        if (bFound) 
        {
            cout << i;
            break;
        }
    }

    return 0;
}