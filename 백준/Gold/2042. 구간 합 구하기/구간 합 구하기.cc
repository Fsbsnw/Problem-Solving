#include <iostream>
#include<vector>
#include<cmath>

using namespace std;

int n, m, k;
vector<long long> arr;
vector<long long> tree;

long long makeTree(int node, int start, int end)
{
    if (start == end) return tree[node] = arr[start];
    
    int mid = (start + end) / 2;
    
    return tree[node] = makeTree(node * 2, start, mid) + makeTree(node * 2 + 1, mid + 1, end);
}

long long sumTree(int node, int start, int end, int left, int right)
{
    if (right < start || left > end) return 0;
    if (left <= start && right >= end) return tree[node];
    
    int mid = (start + end) / 2;
    return sumTree(node * 2, start, mid, left, right) + sumTree(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff)
{
    if (idx < start || idx > end) return;
    
    tree[node] += diff;
    if (start == end) return;
    
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, diff);
    update(node * 2 + 1, mid + 1, end, idx, diff);
}

int main()
{
    cin >> n >> m >> k;
    int h = (int)ceil(log2(n));
    int size = (1 << (h + 1));
    tree.resize(size);

    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    makeTree(1, 0, n - 1);
    
    for (int i = 0; i < m + k; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        
        if (a == 1)
        {
            long long differVal = c - arr[b - 1];
            arr[b - 1] = c;
            update(1, 0, n - 1, b - 1, differVal);
        }
        else if (a == 2)
        {
            cout << sumTree(1, 0, n - 1, b - 1, c - 1) << endl;
        }
    }
    return 0;
}
