#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    
    for (vector<int> i : results)
    {
        arr[i[0]][i[1]] = 1;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (arr[j][i] && arr[i][k])
                {
                    arr[j][k] = 1;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] || arr[j][i]) temp++;
        }
        
        if (temp == n - 1) answer++;
    }
    
    return answer;
}