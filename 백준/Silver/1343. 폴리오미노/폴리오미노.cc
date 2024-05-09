#include <iostream>

using namespace std;

string s;

int main()
{
    cin >> s;
    
    for (int i = 0; i < s.size(); i++)
    {
        int cnt = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (s[j] == 'X') cnt++;
            else break;
        }
        
        if (cnt % 2 == 1)
        {
            cout << -1;
            exit(0);
        }
        
        if (cnt >= 4)
        {
            fill_n(s.begin() + i, 4, 'A');
            i += 3;
        }
        else if (cnt == 2)
        {
            fill_n(s.begin() + i, 2, 'B');
            i++;
        }
    }
    
    cout << s;

    return 0;
}
