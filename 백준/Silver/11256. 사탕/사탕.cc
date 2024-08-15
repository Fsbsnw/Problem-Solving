#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t; cin >> t;
    
    for (int Case = 0; Case < t; Case++)
    {
        int candy, box; cin >> candy >> box;
        priority_queue<int> pq;
        
        for (int i = 0; i < box; i++)
        {
            int r, c; cin >> r >> c;
            
            pq.push(r * c);
        }
        
        int result = 0;
        while (!pq.empty() && candy > 0)
        {
            int curBox = pq.top();
            pq.pop();
            
            candy -= curBox;
            result++;
        }
        
        cout << result << '\n';
    }

    return 0;
}