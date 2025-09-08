#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> Arr(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
    
    sort(Arr.begin(), Arr.end());
    
    int Count = 0;
    
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (i == j) continue;
            
            int Left = 0;
            int Right = N - 1;
            int Target = Arr[j] - Arr[i];
            
            while (Left <= Right)
            {
                int Mid = (Left + Right) / 2;
                
                if (Arr[Mid] < Target)
                {
                    Left = Mid + 1;
                }
                else
                {
                    Right = Mid - 1;
                }
            }
                
            int k = Left;
            bool bFound = false;
            
            while (k < N && Arr[k] == Target)
            {
                if (k != i && k != j)
                {
                    Count++;
                    bFound = true;
                    break; 
                }
                k++; 
            }
            
            if (bFound)
            {
                break; 
            }
        }
    }

    cout << Count;

    return 0;
}