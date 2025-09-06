#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, L;
    cin >> N >> M >> L;
    
    vector<int> Rests;
    
    for (int i = 0; i < N; i++)
    {
        int Temp;
        cin >> Temp;
        
        Rests.push_back(Temp);
    }
    
    Rests.push_back(0);
    Rests.push_back(L);
    
    sort(Rests.begin(), Rests.end());
    
    int Left = 1;
    int Right = L;
    int Answer = 0;
    
    while (Left <= Right)
    {
        int Mid = (Left + Right) / 2;
        int Count = 0;
        
        for (int i = 1; i < Rests.size(); i++)
        {
            int Diff = Rests[i] - Rests[i - 1];
            Count += (Diff - 1) / Mid;
        }
        
        if (Count > M)
        {
            Left = Mid + 1;
        }
        else
        {
            Right = Mid - 1;
            Answer = Mid;
        }
    }
    
    cout << Answer;
    
    return 0;
}