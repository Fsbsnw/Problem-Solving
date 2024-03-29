#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> rank(n, 1);
    vector<pair<int, int>> arr;
    
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        
        arr.push_back(make_pair(x, y));
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            
            if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
            {
                rank[i]++;
            }
        }
        cout << rank[i] << ' ';
    }

    return 0;
}
