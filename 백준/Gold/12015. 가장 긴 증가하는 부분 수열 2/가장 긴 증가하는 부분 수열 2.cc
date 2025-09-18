#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> Arr(N);
    vector<int> LIS;
    
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
        
        if (LIS.empty() || LIS.back() < Arr[i]) LIS.push_back(Arr[i]);
        else
        {
            int Left = 0;
            int Right = LIS.size() - 1;
            
            while (Left <= Right)
            {
                int Mid = (Left + Right) / 2;
                
                if (LIS[Mid] < Arr[i])
                {
                    Left = Mid + 1;
                }
                else
                {
                    Right = Mid - 1;
                }
            }
            
            LIS[Left] = Arr[i];
        }
    }
    
    cout << LIS.size();

    return 0;
}