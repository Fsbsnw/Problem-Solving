#include <iostream>
#include <vector>

using namespace std;

int N;
int MIN = 987654321;
int Stats[21][21];
bool Used[21];

void FindDiff(const vector<int>& StartTeam)
{
    vector<int> LinkTeam;
    
    for (int i = 1; i <= N; i++) 
    {
        if (!Used[i]) LinkTeam.push_back(i);
    }
    
    int StartSum = 0;
    int LinkSum = 0;
    
    int Length = StartTeam.size();
    for (int i = 0; i < Length; i++)
    {
        for (int j = i + 1; j < Length; j++)
        {
            int SIndexI = StartTeam[i];
            int SIndexJ = StartTeam[j];
            StartSum += Stats[SIndexI][SIndexJ] + Stats[SIndexJ][SIndexI];
            
            int LIndexI = LinkTeam[i];
            int LIndexJ = LinkTeam[j];
            LinkSum += Stats[LIndexI][LIndexJ] + Stats[LIndexJ][LIndexI];
        }
    }
    
    int DIFF = abs(StartSum - LinkSum);
    if (DIFF < MIN) MIN = DIFF;
}

void BackTracking(int Idx, vector<int>& Team) 
{
    if (Team.size() == N / 2) 
    {
        FindDiff(Team);
        return;
    }

    for (int i = Idx; i <= N; i++) 
    {
        if (!Used[i]) {
            Used[i] = true;
            Team.push_back(i);
            BackTracking(i + 1, Team);
            Team.pop_back();
            Used[i] = false;
        }
    }
}

int main()
{
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> Stats[i][j];
        }
    }
    
    vector<int> Team;
    BackTracking(1, Team);

    cout << MIN;

    return 0;
}