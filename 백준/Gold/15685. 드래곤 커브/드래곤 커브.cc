#include <iostream>
#include <vector>

using namespace std;

const int RIGHT = 0, UP = 1, LEFT = 2, DOWN = 3;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int N;
vector<vector<bool>> Map(101, vector<bool>(101, false));
pair<int, int> Pos;
vector<int> Dragon;

int CheckSquare()
{
    int Count = 0;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (Map[i][j] && Map[i + 1][j] && Map[i][j + 1] && Map[i + 1][j + 1]) ++Count;
        }
    }
    return Count;
}

void DrawCurve()
{
    for (int Index = Dragon.size() - 1; Index >= 0; --Index)
    {
        int Dir = (Dragon[Index] + 1) % 4;
        
        Pos.first += dx[Dir];
        Pos.second += dy[Dir];
        Map[Pos.first][Pos.second] = true;
        
        Dragon.push_back(Dir);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int x, y, d, g;
        cin >> y >> x >> d >> g;
        
        Dragon.clear();
        
        Pos.first = x + dx[d];
        Pos.second = y + dy[d];
        
        Map[x][y] = true;
        Map[Pos.first][Pos.second] = true;
        
        Dragon.push_back(d);
        
        for (int z = 0; z < g; ++z)
        {
            DrawCurve();
        }
    }
    
    cout << CheckSquare();

    return 0;
}