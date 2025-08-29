#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int Dasom;
    cin >> Dasom;
    
    priority_queue<int> PQ;
    
    for (int i = 0; i < N - 1; i++)
    {
        int Temp;
        cin >> Temp;
        PQ.push(Temp);
    }
    
    int Count = 0;
    while (!PQ.empty() && PQ.top() >= Dasom)
    {
        int Top = PQ.top();
        PQ.pop();
        PQ.push(Top - 1);
        Dasom++;
        Count++;
    }
    
    cout << Count;

    return 0;
}