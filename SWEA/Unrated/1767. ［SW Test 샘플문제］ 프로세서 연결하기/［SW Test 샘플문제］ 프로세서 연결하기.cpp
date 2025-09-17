#include<iostream>
#include<vector>

using namespace std;

#define TOP 0
#define BOTTOM 1
#define LEFT 2
#define RIGHT 3

int DirX[4] = {-1, 1, 0, 0};
int DirY[4] = {0, 0, -1, 1};

int N;
int MaxCore = 0;
int MinWire = 145;
vector<vector<int>> Map;
vector<pair<int, int>> Cores;

bool IsConnectedValidDirection(int x, int y, int Direction, int& ConnectedCore, vector<pair<int, int>>& Path)
{
    int StartX = x;
    int StartY = y;
    
    while (true)
    {
        x += DirX[Direction];
        y += DirY[Direction];
        
        if (0 <= x && x < N && 0 <= y && y < N)
        {
            if (Map[x][y] >= 1) return false;
        }
        // 막힌 곳이 없는 경우
        else
        {
            ConnectedCore++;
            return true;
        }
        Path.push_back({x, y});
    }
}

void ConnectWire(int Index, int ConnectedCore, int ConnectedWire)
{
    if (Index == Cores.size())
    {
        if (ConnectedCore > MaxCore)
        {
            MinWire = ConnectedWire;
            MaxCore = ConnectedCore;
        }
        else if (ConnectedCore == MaxCore)
        {
            MinWire = min(MinWire, ConnectedWire);
        }
        return;
    }
    
    for (int Dir = 0; Dir < 4; Dir++)
    {
        vector<pair<int, int>> Path;
        int TempCore = ConnectedCore;
        
        if (IsConnectedValidDirection(Cores[Index].first, Cores[Index].second, Dir, ConnectedCore, Path))
        {
            for (auto& Pos : Path) Map[Pos.first][Pos.second] = 2;
            ConnectedWire += Path.size();
            ConnectWire(Index + 1, ConnectedCore, ConnectedWire);
            for (auto& Pos : Path) Map[Pos.first][Pos.second] = 0;
            ConnectedWire -= Path.size();
        }
        
        ConnectedCore = TempCore;
    }
    
    ConnectWire(Index + 1, ConnectedCore, ConnectedWire);
}

bool IsOnBoundary(int x, int y)
{
    return (x == 0 || x == N - 1 || y == 0 || y == N - 1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        // 입력 초기화
        cin >> N;
        
        MinWire = 145;
        MaxCore = 0;
        Map = vector<vector<int>>(N, vector<int>(N, 0));
        Cores.clear();
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> Map[i][j];
                
                if (Map[i][j] == 1 && !IsOnBoundary(i, j)) Cores.push_back({i, j});
            }
        }
        
        // DFS 탐색, 백트래킹
        ConnectWire(0, 0, 0);
        
        cout << '#' << test_case << ' ' << MinWire << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}