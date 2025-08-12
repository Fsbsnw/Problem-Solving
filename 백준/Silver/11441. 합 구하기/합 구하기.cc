#include <iostream>

using namespace std;

int Number[100001];
int PrefixSum[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        cin >> Number[i];
        PrefixSum[i] = PrefixSum[i - 1] + Number[i];
    }
    
    int Case;
    cin >> Case;
    
    for (int t = 0; t < Case; t++)
    {
        int Start, End;
        cin >> Start >> End;
        
        cout << PrefixSum[End] - PrefixSum[Start - 1] << '\n';
    }

    return 0;
}