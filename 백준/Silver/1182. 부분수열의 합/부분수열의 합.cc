#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, S;
    cin >> N >> S;
    
    vector<int> Arr(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
    
    int Count = 0;
    
    for (int i = 1; i < (1 << N); i++)
    {
        int Sum = 0;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                Sum += Arr[j];
            }
        }
        if (Sum == S) Count++;
    }
    
    cout << Count;

    return 0;
}