#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> cards, check;
map<int, int> h;

int binary(int x)
{
    int l = 0, r = cards.size() - 1, m = 0, cnt = 0;
    
    while (l <= r)
    {
        m = (l + r) / 2;
        
        if (x < cards[m])
        {
            r = m - 1;
        }
        else if (x > cards[m])
        {
            l = m + 1;
        }
        else
        {
            l = m;
            cnt++;
            break;
        }
    }
    
    if (l > r) return cnt;
    
    l = m - 1;
    r = m + 1;
    
    while (l >= 0 && cards[l] == x)
    {
        cnt++;
        l--;
    }
    while (r < cards.size() && cards[r] == x)
    {
        cnt++;
        r++;
    }
    
    h[x] = cnt;
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cards.push_back(temp);
    }
    
    sort(cards.begin(), cards.end());
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        check.push_back(temp);
    }
    
    for (int i = 0; i < check.size(); i++)
    {
        if (h[check[i]])
        {
            cout << h[check[i]] << ' ';
        }
        else
        {
            cout << binary(check[i]) << ' ';
        }
    }
    
    return 0;
}
