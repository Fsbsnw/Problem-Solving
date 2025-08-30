#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int C, N;
    cin >> C >> N;
    
    vector<pair<int, int>> CostPerCustomer(N);
    vector<int> DP(1101, 100000);
    DP[0] = 0;
    
    for (int i = 0; i < N; i++)
    {
        cin >> CostPerCustomer[i].first >> CostPerCustomer[i].second;
    }
    
    int MIN = 100000;
    for (int i = 1; i <= 1100; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int Cost = CostPerCustomer[j].first;
            int Customers = CostPerCustomer[j].second;
            if (i - Customers >= 0)
            {
                DP[i] = min(DP[i - Customers] + Cost, DP[i]);
            }
        }
        if (i >= C) MIN = min(MIN, DP[i]);
    }
    
    cout << MIN;

    return 0;
}