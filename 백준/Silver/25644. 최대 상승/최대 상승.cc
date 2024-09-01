#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int mmin = 1000000001;
    int mmax = 0;
    
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        
        if (temp < mmin)
        {
            mmin = temp;
        }
        else
        {
            mmax = max(mmax, temp - mmin);
        }
    }
    
    cout << mmax;

    return 0;
}