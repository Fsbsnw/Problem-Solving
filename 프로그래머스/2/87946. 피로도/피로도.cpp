#include <string>
#include <vector>

using namespace std;

int n, result = 0;
vector<bool> visited(8);
vector<vector<int>> dungeon;

void brute(int num, int depth)
{
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] || num < dungeon[i][0]) continue;
        
        visited[i] = true;
        brute(num - dungeon[i][1], depth + 1);
        visited[i] = false;
    }
    
    result = max(result, depth);
}

int solution(int k, vector<vector<int>> dungeons) {
    n = dungeons.size();
    dungeon = dungeons;
    
    brute(k, 0);
    
    return result;
}