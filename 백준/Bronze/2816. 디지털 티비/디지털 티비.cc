#include <iostream>
#include <vector>

using namespace std;

int N;
int Pos = 0;
vector<string> Channel;

bool IsKBS1Top()
{
    return Channel[0] == "KBS1";
}
bool IsKBS2Second()
{
    return Channel[1] == "KBS2";
}

bool IsValidRange(int NewPos)
{
    return 0 <= NewPos && NewPos < N;
}

void Func1()
{
    if (!IsValidRange(Pos + 1)) return;
    ++Pos;
    
    cout << 1;
}

void Func2()
{
    if (!IsValidRange(Pos - 1)) return;
    --Pos;
    
    cout << 2;
}

void Func3()
{
    if (!IsValidRange(Pos + 1)) return;
    
    swap(Channel[Pos], Channel[Pos + 1]);
    ++Pos;
    
    cout << 3;
}

void Func4()
{
    if (!IsValidRange(Pos - 1)) return;
    
    swap(Channel[Pos], Channel[Pos - 1]);
    --Pos;
    
    cout << 4;
}

int main()
{
    cin >> N;
    
    Channel.assign(N, "");
    
    for (int i = 0; i < N; ++i)
    {
        cin >> Channel[i];
    }
    
    while (!IsKBS1Top())
    {
        if (Channel[Pos] != "KBS1") 
        {
            Func1();
        }
        else Func4();
    }
        
    while (!IsKBS2Second())
    {
        if (Channel[Pos] != "KBS2") 
        {
            Func1();
        }
        else Func4();
    }

    return 0;
}