#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CheckSpace(int x, int y, vector<vector<string>>& park)
{
    bool bStop = false;
    int MaxHeight = park.size();
    int MaxWidth = park[0].size();
    int SpaceSize = 0;
    
    for (int Length = 1; x + Length <= MaxHeight && y + Length <= MaxWidth; Length++) 
    {
        for (int i = x; i < x + Length; i++) 
        {
            for (int j = y; j < y + Length; j++) 
            {
                if (park[i][j] != "-1") 
                {
                    bStop = true;
                    break;
                }
            }
            if (bStop) break;
        }
        
        if (bStop) 
        {
            break;
        }
        SpaceSize = Length;
    }
    return SpaceSize;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int MaxLength = -1;
    int Height = park.size();
    int Width = park[0].size();
    
    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            int FoundSpace = CheckSpace(i, j, park);
            if (FoundSpace > MaxLength) MaxLength = FoundSpace;
        }
    }
    
    sort(mats.begin(), mats.end());
    
    int answer = -1;
    for (int n : mats)
    {
        if (n <= MaxLength) answer = n;
    }
    
    return answer;
}