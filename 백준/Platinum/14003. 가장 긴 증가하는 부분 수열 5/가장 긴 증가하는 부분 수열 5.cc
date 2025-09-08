#include <iostream>
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
    
    vector<int> LIS;
    vector<int> Position(N, -1);
    
    for (int i = 0; i < N; i++)
    {
        int Target = Arr[i];
        
        if (LIS.empty() || LIS.back() < Target)
        {
            LIS.push_back(Target);
            Position[i] = LIS.size() - 1;
        }
        else
        {
            int Left = 0;
            int Right = LIS.size() - 1;
            
            while (Left <= Right)
            {
                int Mid = (Left + Right) / 2;
                
                if (LIS[Mid] < Target)
                {
                    Left = Mid + 1;
                }
                else
                {
                    Right = Mid - 1;
                }
            }
            
            LIS[Left] = Target;
            Position[i] = Left;
        }
    }
    
    int CurrentIndex = LIS.size() - 1;
    vector<int> Temp;
    
    for (int i = N - 1; i >= 0; i--)
    {
        if (Position[i] == CurrentIndex)
        {
            Temp.push_back(Arr[i]);
            CurrentIndex--;
        }
    }
    
    cout << Temp.size() << '\n';
    for (int i = Temp.size() - 1; i >= 0; i--)
    {
        cout << Temp[i] << ' ';
    }

    return 0;
}