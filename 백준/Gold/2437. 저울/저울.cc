#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> Weights(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> Weights[i];
    }
    
    sort(Weights.begin(), Weights.end());

    int MAX = 0;
    for (int i = 0; i < N; i++)
    {
        if (Weights[i] > MAX + 1) break;
        
        MAX += Weights[i];
    }
    
    cout << MAX + 1;
    
    return 0;
}