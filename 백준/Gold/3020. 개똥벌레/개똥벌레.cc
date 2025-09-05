#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H;
vector<int> BottomObstacles;
vector<int> TopObstacles;

int Binary(const vector<int>& Obstacles, int Target)
{
    int Left = 0;
    int Right = Obstacles.size() - 1;
    while (Left <= Right)
    {
        int Mid = (Left + Right) / 2;
        if (Obstacles[Mid] >= Target)
        {
            Right = Mid - 1;
        }
        else
        {
            Left = Mid + 1;
        }
    }
    return Obstacles.size() - Left;
}

int main()
{
    cin >> N >> H;
    
    for (int i = 0; i < N; i++)
    {
        int Temp;
        cin >> Temp;
        
        if (i % 2 == 0)
        {
            BottomObstacles.push_back(Temp);
        }
        else
        {
            TopObstacles.push_back(Temp);
        }
    }
    
    sort(BottomObstacles.begin(), BottomObstacles.end());
    sort(TopObstacles.begin(), TopObstacles.end());
    
    int MinValue = N;
    int Count = 0;

    for (int h = 1; h <= H; h++)
    {
        int A = Binary(BottomObstacles, h);         
        int B = Binary(TopObstacles, H - h + 1);    
        int Total = A + B;
        
        if (Total < MinValue)
        {
            MinValue = Total;
            Count = 1;
        }
        else if (Total == MinValue)
        {
            Count++;
        }
    }
    
    cout << MinValue << " " << Count;

    return 0;
}