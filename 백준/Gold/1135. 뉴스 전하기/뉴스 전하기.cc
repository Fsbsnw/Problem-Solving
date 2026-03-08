#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Tree[51];

int DFS(int Node)
{
    vector<int> ChildTimes;
    
    for (int Child : Tree[Node])
    {
        int ChildTime = DFS(Child);
        ChildTimes.push_back(ChildTime);
    }
    
    sort(ChildTimes.begin(), ChildTimes.end(), greater<int>());
    
    int Time = 0;
    for (int i = 0; i < ChildTimes.size(); ++i)
    {
        Time = max(Time, ChildTimes[i] + i + 1);
    }
    return Time;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int M;
        cin >> M;
        
        if (M != -1) Tree[M].push_back(i);
    }
    
    cout << DFS(0);

    return 0;
}