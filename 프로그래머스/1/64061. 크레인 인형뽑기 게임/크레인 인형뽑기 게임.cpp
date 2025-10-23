#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int len = board.size();
    
    // 인덱스 저장
    vector<int> Tops(len);
    
    for (int j = 0; j < len; ++j)
    {
        for (int i = 0; i < len; ++i)
        {
            if (board[i][j])
            {
                Tops[j] = i;
                break;
            }
        }
    }
    
    vector<int> s;
    
    for (int i : moves)
    {
        int Row = Tops[i - 1];
        int Doll = board[Row][i - 1];
        
        if (Doll <= 0) continue;
        
        if (s.empty() || s.back() != Doll)
        {
            s.push_back(Doll);
        }
        else
        {
            s.pop_back();
            answer += 2;
        }
        board[Row][i - 1] = 0;
        Tops[i - 1] = min(Tops[i - 1] + 1, len - 1);
    }
    
    return answer;
}