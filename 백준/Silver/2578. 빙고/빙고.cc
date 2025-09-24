#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    vector<vector<int>> Bingo(5, vector<int>(5));
    unordered_map<int, pair<int, int>> BingoMap;
    
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> Bingo[i][j];
            BingoMap[Bingo[i][j]] = make_pair(i, j);
        }
    }
    
    int Result = -1;
    
    for (int Count = 1; Count <= 25; ++Count)
    {
        int Num;
        cin >> Num;
        
        int x = BingoMap[Num].first;
        int y = BingoMap[Num].second;
        
        Bingo[x][y] = 0;
        int BingoCount = 0;
        
        // Row
        for (int i = 0; i < 5; ++i)
        {
            bool bBingo = true;
            for (int j = 0; j < 5; ++j)
            {
                if (Bingo[i][j] > 0)
                {
                    bBingo = false;
                    break;
                }
            }
            if (bBingo) ++BingoCount;
        }
        
        // Col
        for (int i = 0; i < 5; ++i)
        {
            bool bBingo = true;
            for (int j = 0; j < 5; ++j)
            {
                if (Bingo[j][i] > 0)
                {
                    bBingo = false;
                    break;
                }
            }
            if (bBingo) ++BingoCount;
        }
        
        // Diagonal1
        bool bBingoDiagonal1 = true;
        for (int i = 0; i < 5; ++i)
        {
            if (Bingo[i][i] > 0)
            {
                bBingoDiagonal1 = false;
                break;
            }
        }
        if (bBingoDiagonal1) ++BingoCount;
        
        // Diagonal2
        bool bBingoDiagonal2 = true;
        for (int i = 0; i < 5; ++i)
        {
            if (Bingo[i][4 - i] > 0)
            {
                bBingoDiagonal2 = false;
                break;
            }
        }
        if (bBingoDiagonal2) ++BingoCount;
        
        if (BingoCount >= 3) 
        {
            Result = Count;
            break;
        }
    }
    
    cout << Result;

    return 0;
}