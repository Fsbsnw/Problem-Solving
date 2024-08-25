#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int coin; cin >> coin;
        result += abs(coin);
    }
    
    for (int i = 0; i < n; i++)
    {
        int coin; cin >> coin;
        result += abs(coin);
    }
    cout << result;
    
    return 0;
}