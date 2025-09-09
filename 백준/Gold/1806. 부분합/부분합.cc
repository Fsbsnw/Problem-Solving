#include <iostream>
#include <vector>

using namespace std;

#define MAX_RANGE 100000

int main()
{
    int N, S;
    cin >> N >> S;
    
    vector<int> Arr(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
    
    int Left = 0, Right = 0;
    int Sum = Arr[0];
    int MIN = MAX_RANGE;
    
    while (Right < N)
    {
        if (Sum >= S) 
        {
            MIN = min(MIN, Right - Left + 1);
            Sum -= Arr[Left];
            Left++;
        }
        else 
        {
            Right++;
            if (Right < N) Sum += Arr[Right];
        }
    }
    
    cout << (MIN == MAX_RANGE ? 0 : MIN);

    return 0;
}