#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int idx = 1, cnt = 0;
    long long n, sum = 0;
    cin >> n;
    
    while (sum < n)
    {
        sum += idx;
        idx++;
        cnt++;
    }
    
    cnt = (sum > n) ? cnt - 1 : cnt;

    cout << cnt;
    
    return 0;
}
