#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[51];
bool truth[51];

int findParent(int x)
{
    if (parent[x] == x) return x;
    return findParent(parent[x]);
}

void unionBoth(int a, int b)
{
    int A = findParent(a);
    int B = findParent(b);
    parent[A] = B;
    if (truth[A] || truth[B])
    {
        truth[A] = true;
        truth[B] = true;
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    
    int p;
    cin >> p;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    
    for (int i = 0; i < p; i++)
    {
        int know;
        cin >> know;
        truth[know] = true;
    }
    
    int cnt = 0;
    vector<vector<int>> arr;
    for (int i = 0; i < m; i++)
    {
        int people;
        cin >> people;
        
        vector<int> check;
        for (int j = 0; j < people; j++)
        {
            int person;
            cin >> person;
            check.push_back(person);
        }
        
        arr.push_back(check);
        
        for (int k = 0; k < check.size() - 1; k++)
        {
            unionBoth(check[k], check[k + 1]);
        }
    }
    
    for (vector<int> i : arr)
    {
        bool canLie = true;
        if (i.size() == 1) 
        {
            if (!truth[findParent(i[0])])
            {
                cnt++;
            }
        }
        else
        {
            for (int k = 0; k < i.size() - 1; k++)
            {
                if (truth[findParent(i[k])] || truth[findParent(i[k + 1])]) 
                {
                    canLie = false;
                }
            }
            if (canLie) 
            {
                cnt++;
            }
        }
    }
    cout << cnt;
    
    return 0;
}
