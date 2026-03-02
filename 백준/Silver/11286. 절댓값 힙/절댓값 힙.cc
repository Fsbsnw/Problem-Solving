#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Compare
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main()
{
    priority_queue<int, vector<int>, Compare> pq;
    
    int n;
    cin >> n;
    
    while (n--)
    {
        int com;
        cin >> com;
        
        if (com == 0)
        {
            if (pq.empty()) printf("0\n");
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(com);
        }
    }

    return 0;
}