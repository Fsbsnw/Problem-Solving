#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++)
    {
        int S, K;
        cin >> S >> K;
        
        vector<int> Arr(S);
        for (int i = 0; i < S; i++)
        {
            cin >> Arr[i];
        }
        
        sort(Arr.begin(), Arr.end());
        
        int MIN = 200000001;
        int Count = 0;
        int LP = 0;
        int RP = S - 1;

        while (LP < RP)
        {
            int Sum = Arr[LP] + Arr[RP];
            int Diff = abs(K - Sum);

            if (Diff < MIN)
            {
                MIN = Diff;
                Count = 1;
            }
            else if (Diff == MIN)
            {
                Count++;
            }

            if (Sum < K)
            {
                LP++;
            }
            else if (Sum > K)
            {
                RP--;
            }
            else
            {
                LP++;
                RP--;
            }
        }
        
        cout << Count << '\n';
    }

    return 0;
}