#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    int T;
    cin >> T;
    
    int Left = 1;
    int Right = M;
    int Count = 0;
    
    for (int i = 0; i < T; i++)
    {
        int Apple;
        cin >> Apple;
        
        if (Right < Apple)
        {
            int Temp = Apple - Right;
            Left += Temp;
            Right += Temp;
            Count += Temp;
        }
        else if (Left > Apple)
        {
            int Temp = Left - Apple;
            Left -= Temp;
            Right -= Temp;
            Count += Temp;
        }
    }
    
    cout << Count;

    return 0;
}