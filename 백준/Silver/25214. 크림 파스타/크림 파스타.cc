#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    
    int mmin = 0, prevMax = 0;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        
        if (i == 0)
        {
            mmin = temp;
        }
        else
        {
            if (mmin > temp) 
            {
                mmin = temp;
            }
            prevMax = (temp - mmin > prevMax) ? temp - mmin : prevMax;
        }
        
        cout << prevMax << ' ';
    }

    return 0;
}