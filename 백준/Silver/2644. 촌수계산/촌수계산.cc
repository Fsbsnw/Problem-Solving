#include <iostream>
#include <vector>

using namespace std;

int N, M;
int Person1, Person2;
vector<vector<int>> Family;
bool bFound = false;
bool Visited[101];

void FindKinship(int Now, int KinshipCount, int& OutResult)
{
    Visited[Now] = true;
    
    if (Now == Person2)
    {
        OutResult = KinshipCount;
        bFound = true;
        return;
    }
    
    for (int Next : Family[Now])
    {
        if (!Visited[Next])
        {
            FindKinship(Next, KinshipCount + 1, OutResult);
            if (bFound) return;
        }
    }
}

int main()
{
    cin >> N >> Person1 >> Person2 >> M;
    
    Family.resize(N + 1);
    
    for (int Case = 0; Case < M; Case++)
    {
        int Parent, Child;
        cin >> Parent >> Child;
        
        Family[Parent].push_back(Child);
        Family[Child].push_back(Parent);
    }
    
    int ResultKinship = -1;
    FindKinship(Person1, 0, ResultKinship);
    
    cout << ResultKinship;

    return 0;
}