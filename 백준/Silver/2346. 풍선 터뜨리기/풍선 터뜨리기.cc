#include <iostream>
#include <deque>

using namespace std;

void RotateDeque(deque<pair<int, int>>& Deque, int Value)
{
    if (Value > 0)
    {
        for (int Count = 0; Count < Value - 1; Count++)
        {
            Deque.push_back(Deque.front());
            Deque.pop_front();
        }
    }
    else
    {
        for (int Count = 0; Count < (-Value); Count++)
        {
            Deque.push_front(Deque.back());
            Deque.pop_back();
        }
    }
}

int main()
{
    int BalloonNum; cin >> BalloonNum;
    deque<pair<int, int>> Balloon(BalloonNum);
    
    for (int Num = 0; Num < BalloonNum; Num++)
    {
        int Value; cin >> Value;
        Balloon[Num].first = Num + 1;
        Balloon[Num].second = Value;
    }
    
    while (!Balloon.empty())
    {
        int BalloonNumber = Balloon.front().first;
        int MoveValue = Balloon.front().second;
        
        cout << BalloonNumber << ' ';
        
        Balloon.pop_front();
        if (!Balloon.empty())
        {
            RotateDeque(Balloon, MoveValue);
        }
    }
    
    return 0;
}