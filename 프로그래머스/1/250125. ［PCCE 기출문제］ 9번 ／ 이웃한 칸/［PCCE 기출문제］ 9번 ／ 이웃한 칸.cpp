#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int cnt = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    for (int i = 0; i < 4; i ++)
    {
        int nx = h + dx[i];
        int ny = w + dy[i];
        
        if (0 <= nx && nx < board.size() && board[h][w] == board[nx][ny])
        {
            cnt++;
        }
    }
    
    return cnt;
}