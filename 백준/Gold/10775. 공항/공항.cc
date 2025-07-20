#include <iostream>
#include <vector>

using namespace std;

vector<int> Parent;

int Find(int A)
{
    if (Parent[A] == A)
    {
        return A;
    }
    return Parent[A] = Find(Parent[A]);
}

void Union(int A, int B)
{
    Parent[Find(A)] = Find(B);
}

int main()
{
    int G, P;
    cin >> G >> P;
    
    int MaxReceivableGates = 0;
    
    for (int i = 0; i <= G; i++)
    {
        Parent.push_back(i);
    }
    
    for (int i = 0; i < P; i++)
    {
        int GateIndex;
        cin >> GateIndex;
        
        int AvailableGate = Find(GateIndex);
        if (AvailableGate == 0) break;
        
        MaxReceivableGates++;
        Union(AvailableGate, AvailableGate - 1);
    }
    
    printf("%d", MaxReceivableGates);

    return 0;
}