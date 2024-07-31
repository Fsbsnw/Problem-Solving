#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> arr;
vector<bool> visited(1001, false);

bool compare(pair<int, int>& a, pair<int, int>& b)
{
    return a.first > b.first;
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int d, w; 
        cin >> d >> w;
        
        arr.push_back({w, d});
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    int result = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].second; j >= 1; j--)
        {
            if (!visited[j]) 
            {
                visited[j] = true;
                result += arr[i].first; 
                break;
            }
        }
    }
    
    cout << result;

    return 0;
}
