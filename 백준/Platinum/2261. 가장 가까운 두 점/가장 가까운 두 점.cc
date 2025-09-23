#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

using ll = long long;

int N;
vector<pair<int, int>> Points;
    
ll Dist(const pair<int, int>& A, const pair<int, int>& B) 
{
    ll dx = A.first - B.first;
    ll dy = A.second - B.second;
    return dx * dx + dy * dy;
}

bool CompareY(const pair<int, int>& A, const pair<int, int>& B)
{
    return (A.second < B.second);
}

ll Divide(int Left, int Right)
{
    int Num = Right - Left + 1;
    if (Num <= 3)
    {
        ll Distance = LLONG_MAX;
        for (int i = Left; i <= Right - 1; ++i)
        {
            for (int j = i + 1; j <= Right; ++j)
            {
                Distance = min(Distance, Dist(Points[i], Points[j]));
            }
        }
        return Distance;
    }
    
    int Mid = (Left + Right) / 2;
    ll MinDist = Divide(Left, Mid);
    ll RightDist = Divide(Mid + 1, Right);
    
    if (MinDist > RightDist)
    {
        MinDist = RightDist;
    }
    
    vector<pair<int, int>> Temp;
    
    for (int i = Left; i <= Right; ++i)
    {
        ll dx = Points[i].first - Points[Mid].first;
        if (dx * dx < MinDist) Temp.push_back(Points[i]);
    }
    
    sort(Temp.begin(), Temp.end(), CompareY);
    
    for (int i = 0; i < Temp.size() - 1; ++i)
    {
        for (int j = i + 1; j < Temp.size(); ++j)
        {
            ll dy = Temp[j].second - Temp[i].second;
            if (dy * dy >= MinDist) break;
            
            MinDist = min(MinDist, Dist(Temp[i], Temp[j]));
        }
    }
    
    return MinDist;
}

int main()
{
    cin >> N;
    Points.resize(N);
    
    for (int T = 0; T < N; ++T)
    {
        cin >> Points[T].first >> Points[T].second;
    }
    
    sort(Points.begin(), Points.end());
    
    if (Points[0] == Points[1]) cout << 0;
    else cout << Divide(0, N - 1);

    return 0;
}