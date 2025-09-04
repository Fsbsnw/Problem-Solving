#include <iostream>
#include <vector>
#include <algorithm>

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
    
    vector<int> BinaryArr;
    
    for (int i = 0; i < N; i++)
    {
        int Num = Arr[i];
        
        if (BinaryArr.empty())
        {
            BinaryArr.push_back(Num);
        }
        else
        {
            int Left = 0;
            int Right = BinaryArr.size() - 1;
            while (Left <= Right)
            {
                int Mid = (Left + Right) / 2;
                if (BinaryArr[Mid] < Num)
                {
                    Left = Mid + 1;
                }
                else
                {
                    Right = Mid - 1;
                }
            }
            
            if (Left == BinaryArr.size())
            {
                BinaryArr.push_back(Num);
            }
            else
            {
                BinaryArr[Left] = Num;
            }
        }
    }
    
    cout << BinaryArr.size();

    return 0;
}