#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LowerBound(vector<int>& Cards, int Target)
{
    int Left = 0;
    int Right = Cards.size() - 1;
    
    while (Left <= Right)
    {
        int Mid = (Left + Right) / 2;
        
        if (Target <= Cards[Mid])
        {
            Right = Mid - 1;
        }
        else
        {
            Left = Mid + 1;
        }
    }
    return Left;
}

int UpperBound(vector<int>& Cards, int Target)
{
    int Left = 0;
    int Right = Cards.size() - 1;
    
    while (Left <= Right)
    {
        int Mid = (Left + Right) / 2;
        
        if (Target >= Cards[Mid])
        {
            Left = Mid + 1;
        }
        else
        {
            Right = Mid - 1;
        }
    }
    return Left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N; 
    cin >> N;
    vector<int> Cards(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Cards[i];
    }
    
    sort(Cards.begin(), Cards.end());
    
    int M;
    cin >> M;
    vector<int> CardsToFind(M);
    for (int i = 0; i < M; i++)
    {
        cin >> CardsToFind[i];
        
        int Lower = LowerBound(Cards, CardsToFind[i]);
        int Upper = UpperBound(Cards, CardsToFind[i]);
        
        cout << Upper - Lower << ' ';
    }

    return 0;
}