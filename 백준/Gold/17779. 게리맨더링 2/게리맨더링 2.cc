#include <iostream>
#include <vector>

using namespace std;

int N, Total = 0, Min = 987654321;
vector<vector<int>> Map, Boundary;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    Map.assign(N + 1, vector<int>(N + 1, 0));
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> Map[i][j];
            Total += Map[i][j];
        }
    }
    for (int x = 1; x <= N; ++x)
    {
        for (int y = 1; y <= N; ++y)
        {
            for (int dl = 1; dl < N; ++dl)
            {
                for (int dr = 1; dr < N; ++dr)
                {
                    if (x + dl + dr > N) break;
                    if (y - dl < 1 || y + dr > N) break;
                    
                    Boundary.assign(N + 1, vector<int>(N + 1, 0));
                    int TempMin = 987654321, TempMax = 0;
                    int LT = 0, RT = 0, LD = 0, RD = 0, CT = 0;
                    
                    // Boundary
                    for (int i = 0; i <= dl; ++i)
                        Boundary[x + i][y - i] = 5;
                        
                    for (int i = 0; i <= dr; ++i)
                        Boundary[x + i][y + i] = 5;
                        
                    for (int i = 0; i <= dr; ++i)
                        Boundary[x + dl + i][y - dl + i] = 5;
                        
                    for (int i = 0; i <= dl; ++i)
                        Boundary[x + dr + i][y + dr - i] = 5;
                    
                    
                    // Summary
                    for (int i = 1; i < x + dl; ++i)
                    {
                        for (int j = 1; j <= y; ++j)
                        {
                            if (Boundary[i][j] == 5) break;
                            LT += Map[i][j]; 
                        }
                    }
                            
                    for (int i = 1; i <= x + dr; ++i)
                    {
                        for (int j = N; j > y; --j)
                        {
                            if (Boundary[i][j] == 5) break;
                            RT += Map[i][j]; 
                        }
                    }
                    
                    for (int i = x + dl; i <= N; ++i)
                    {
                        for (int j = 1; j < y - dl + dr; ++j)
                        {
                            if (Boundary[i][j] == 5) break;
                            LD += Map[i][j]; 
                        }
                    }
                    
                    for (int i = x + dr + 1; i <= N; ++i)
                    {
                        for (int j = N; j >= y - dl + dr; --j)
                        {
                            if (Boundary[i][j] == 5) break;
                            RD += Map[i][j]; 
                        }
                    }
                    
                    CT = Total - LT - LD - RT - RD;
                    TempMax = max(max(max(max(CT, LT), LD), RT), RD);
                    TempMin = min(min(min(min(CT, LT), LD), RT), RD);
                    
                    Min = min(Min, TempMax - TempMin);
                }
            }
        }
    }
    
    cout << Min;

    return 0;
}