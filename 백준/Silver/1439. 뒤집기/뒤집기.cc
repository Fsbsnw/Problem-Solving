#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int cnt0 = 0, cnt1 = 0;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[i + 1])
        {
            if (s[i] == '1') cnt1++;
            else cnt0++;
        }
    }

    cout << min(cnt0, cnt1);
    return 0;
}