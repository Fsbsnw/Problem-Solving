#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> visited(n, 0);
    sort(costs.begin(), costs.end(), cmp);

    visited[costs[0][0]] = 1;
    visited[costs[0][1]] = 1;
    answer += costs[0][2];
    int count = 2;
    
    while (count != n)
    {
        for (int i = 1; i < costs.size(); i++)
        {
            if (visited[costs[i][0]] != visited[costs[i][1]]) 
            {
                visited[costs[i][0]] = 1;
                visited[costs[i][1]] = 1;
                answer += costs[i][2];
                count++;
                break;
            }
        }
    }
    
    return answer;
}