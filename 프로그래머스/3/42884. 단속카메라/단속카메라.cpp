#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int temp = routes[0][1];
    
    sort(routes.begin(), routes.end());
    
    for (int i = 0; i < routes.size(); i++)
    {
        if (routes[i][0] > temp)
        {
            answer++;
            temp = routes[i][1];
        }
        
        if (routes[i][1] <= temp)
        {
            temp = routes[i][1];
        }
    }
    
    return answer;
}