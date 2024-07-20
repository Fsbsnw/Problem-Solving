#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long

int t;

int main()
{
    cin >> t;
    
    for (int Case = 0; Case < t; Case++)
    {
        int k; cin >> k;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        
        for (int i = 0; i < k; i++)
        {
            int temp; cin >> temp;
            pq.push(temp);
        }
        
        ll result = 0;
        while (pq.size() >= 2)
        {
            ll first = pq.top();
            pq.pop();
            ll second = pq.top();
            pq.pop();
            
            pq.push(first + second);
            result += first + second;
        }
        
        cout << result << '\n';
    }

    return 0;
}