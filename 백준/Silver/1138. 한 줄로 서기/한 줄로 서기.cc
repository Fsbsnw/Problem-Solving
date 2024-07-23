#include <iostream>

using namespace std;

int n;
int lines[10];
int orders[10];

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> lines[i];
        
        int cnt = 0;
        int idx = 0;
        for (int j = 0; j < n; j++)
        {
            if (orders[j] == 0) cnt++;
            if (cnt == lines[i] + 1) 
            {
                idx = j;
                break;
            }
        }
        orders[idx] = i + 1;
    }
    
    for (int i = 0; i < n; i++) cout << orders[i] << ' ';

    return 0;
}