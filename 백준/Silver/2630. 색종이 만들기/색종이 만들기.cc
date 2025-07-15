#include <iostream>
#include <vector>

using namespace std;

int WhiteColor = 0;
int BlueColor = 0;

bool CheckSameColor(vector<vector<int>>& Paper, int StartX, int StartY, int EndX, int EndY)
{
    int Color = Paper[StartX][StartY];
    
    for (int i = StartX; i <= EndX; i++)
    {
        for (int j = StartY; j <= EndY; j++)
        {
            if (Paper[i][j] != Color) return false;
        }
    }
    return true;
}

void DividePaper(vector<vector<int>>& Paper, int StartX, int StartY, int EndX, int EndY)
{
    if (CheckSameColor(Paper, StartX, StartY, EndX, EndY))
    {
        if (Paper[StartX][StartY]) BlueColor++;
        else WhiteColor++;
        return;
    }
    
    int MidX = (StartX + EndX) / 2;
    int MidY = (StartY + EndY) / 2;

    DividePaper(Paper, StartX, StartY, MidX, MidY);
    DividePaper(Paper, StartX, MidY + 1, MidX, EndY);
    DividePaper(Paper, MidX + 1, StartY, EndX, MidY);
    DividePaper(Paper, MidX + 1, MidY + 1, EndX, EndY);
}

int main()
{
    int n; cin >> n;
    vector<vector<int>> Paper(n, vector<int>(n));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> Paper[i][j];
        }
    }
    
    DividePaper(Paper, 0, 0, n - 1, n - 1);
    
    cout << WhiteColor << '\n' << BlueColor;

    return 0;
}