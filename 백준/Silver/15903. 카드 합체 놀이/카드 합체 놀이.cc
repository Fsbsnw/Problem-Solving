#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    
    int n, m;
    cin >> n >> m;
    
    ll result = 0;
    
    for (int i = 0; i < n; ++i)
    {
        int card;
        cin >> card;
        
        result += card;
        pq.push(card);
    }
    
    while (m--)
    {
        ll a = pq.top();
        pq.pop();
        
        ll b = pq.top();
        pq.pop();
        
        pq.push(a + b);
        pq.push(a + b);
        
        result += a + b;
    }
    
    printf("%lld", result);

    return 0;
}