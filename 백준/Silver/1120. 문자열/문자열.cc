#include <iostream>

using namespace std;

string n, m;

int main()
{
    cin >> n >> m;
    
    int cnt = 50;
    for (int i = 0; i < m.size(); i++)
    {
        if (i + n.size() > m.size()) break;
        
        int temp = 0;
        for (int j = 0; j < n.size(); j++)
        {
            if (m[j + i] != n[j]) temp++;
        }
        
        cnt = min(cnt, temp);
    }
    
    cout << cnt;

    return 0;
}