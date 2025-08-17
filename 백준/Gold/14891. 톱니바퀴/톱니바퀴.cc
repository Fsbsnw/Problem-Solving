#include <iostream>
#include <vector>

#define INIT_VALUE          2
#define WHEEL_CONTACT_LEFT  6
#define WHEEL_CONTACT_RIGHT 2

using namespace std;

string Wheels[5];

void RotateWheel(string& Wheel, int Direction)
{
    if (Direction == 1)
    {
        char Last = Wheel.back();
        Wheel.pop_back();
        Wheel.insert(0, 1, Last);
    }
    else if (Direction == -1)
    {
        char First = Wheel.front();
        Wheel.erase(0, 1);
        Wheel.push_back(First);
    }
}

bool IsSameMagneticPole(int FirstWheel, int SecondWheel)
{
    return Wheels[FirstWheel][WHEEL_CONTACT_RIGHT] == Wheels[SecondWheel][WHEEL_CONTACT_LEFT];
}

void PlanRotation(int WheelIndex, int Direction, vector<int>& RotationPlan)
{
    RotationPlan[WheelIndex] = Direction;
    
    int LeftWheel = WheelIndex - 1;
    int RightWheel = WheelIndex + 1;
    
    if (LeftWheel >= 1 && RotationPlan[LeftWheel] == INIT_VALUE)
    {
        if (!IsSameMagneticPole(LeftWheel, WheelIndex))
        {
            PlanRotation(LeftWheel, -Direction, RotationPlan);
        }
        else
        {
            RotationPlan[LeftWheel] = 0;
        }
    }
    if (RightWheel <= 4 && RotationPlan[RightWheel] == INIT_VALUE)
    {
        if (!IsSameMagneticPole(WheelIndex, RightWheel))
        {
            PlanRotation(RightWheel, -Direction, RotationPlan);
        }
        else
        {
            RotationPlan[RightWheel] = 0;
        }
    }
}

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        cin >> Wheels[i];
    }
    
    int TestCount;
    cin >> TestCount;
    
    for (int t = 0; t < TestCount; t++)
    {
        int WheelIndex, Direction;
        cin >> WheelIndex >> Direction;
        vector<int> RotationPlan(5, INIT_VALUE);
        
        PlanRotation(WheelIndex, Direction, RotationPlan);
        
        for (int i = 1; i <= 4; i++)
        {
            RotateWheel(Wheels[i], RotationPlan[i]);
        }
    }
    
    int Score = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (Wheels[i][0] == '1')
        {
            Score += (1 << (i - 1));
        }
    }
    
    cout << Score;
    return 0;
}
