#include <iostream>
#include <vector>

using namespace std;

int parent[100001];

int findParent(int a)
{
    if (a == parent[a]) return a;
    return parent[a] = findParent(parent[a]);
}

void unionBoth(int a, int b)
{
    int tempa = findParent(a);
    int tempb = findParent(b);
    
    parent[tempa] = tempb;
}

int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        
        unionBoth(a, b);
    }
    
    vector<int> lectures;
    for (int i = 0; i < n; i++)
    {
        int lecture;
        cin >> lecture;
        lectures.push_back(lecture);
    }
    
    for (int i = 0; i < lectures.size() - 1; i++)
    {
        if (findParent(lectures[i]) != findParent(lectures[i + 1]))
        {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
