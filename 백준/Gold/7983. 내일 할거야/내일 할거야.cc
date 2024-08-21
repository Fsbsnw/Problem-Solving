#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> arr;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int period, date; 
        cin >> period >> date;
        arr.push_back({period, date});
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    int right = arr[0].second;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].second < right) right = arr[i].second;
        right -= arr[i].first;
    }
    
    cout << (right < 0 ? 0 : right);

    return 0;
}