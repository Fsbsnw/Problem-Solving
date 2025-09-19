#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FWeightInfo
{
    int Weight;
    int First;
    int Second;
};

bool Compare(FWeightInfo InfoA, FWeightInfo InfoB)
{
    return InfoA.Weight < InfoB.Weight;
}

vector<int> Parent;

int Find(int A)
{
    if (A != Parent[A]) return Parent[A] = Find(Parent[A]);
    return A;
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);
    
    if (A != B) Parent[B] = A;
}

int main()
{
    // Input
    int V, E;
    cin >> V >> E;
    
    Parent.resize(V + 1);
    for (int i = 1; i <= V; ++i) 
        Parent[i] = i;
    
    vector<FWeightInfo> Weights;
    
    for (int i = 0; i < E; ++i)
    {
        FWeightInfo WeightInfo;
        cin >> WeightInfo.First >> WeightInfo.Second >> WeightInfo.Weight;
        
        Weights.push_back(WeightInfo);
    }
    
    sort(Weights.begin(), Weights.end(), Compare);
    
    
    // Solution
    int Result = 0;
    
    for (FWeightInfo Info : Weights)
    {
        if (Find(Info.First) != Find(Info.Second)) 
        {
            Union(Info.First, Info.Second);
            Result += Info.Weight;
        }
    }
    
    cout << Result;
    
    return 0;
}