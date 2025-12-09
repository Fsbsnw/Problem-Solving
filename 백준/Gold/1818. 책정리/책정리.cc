#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> temp;
    
    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        
        int l = 0, r = temp.size() - 1;
        
        while (l <= r)
        {
            int m = (l + r) / 2;
            
            if (temp[m] < a)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        
        if (temp.empty() || l == temp.size())
        {
            temp.push_back(a);
        }
        else
        {
            temp[l] = a;
        }
    }
    
    cout << n - temp.size();

    return 0;
}