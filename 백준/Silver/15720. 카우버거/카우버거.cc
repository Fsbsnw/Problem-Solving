#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int b, c, d;
    cin >> b >> c >> d;
    
    priority_queue<int> pqB, pqC, pqD;
    
    for (int i = 0; i < b; i++)
    {
        int temp; cin >> temp;
        pqB.push(temp);
    }
    
    for (int i = 0; i < c; i++)
    {
        int temp; cin >> temp;
        pqC.push(temp);
    }
    
    for (int i = 0; i < d; i++)
    {
        int temp; cin >> temp;
        pqD.push(temp);
    }
    
    int result1 = 0;
    int result2 = 0;
    while (!pqB.empty() || !pqC.empty() || !pqD.empty())
    {
        int costb = 0, costc = 0, costd = 0;
        if (!pqB.empty()) 
        {
            costb = pqB.top();
            pqB.pop();
        }
        if (!pqC.empty()) 
        {
            costc = pqC.top();
            pqC.pop();
        }
        if (!pqD.empty()) 
        {
            costd = pqD.top();
            pqD.pop();
        }
        
        result1 += costb + costc + costd;
        
        if (costb > 0 && costc > 0 && costd > 0)
        {
            result2 += (costb + costc + costd) * 0.9;
        }
        else
        {
            result2 += costb + costc + costd;
        }
    }
    
    cout << result1 << '\n' << result2;

    return 0;
}