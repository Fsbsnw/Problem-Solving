#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<int> Members(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> Members[i];
    }
    
    sort(Members.begin(), Members.end());
    
    int Start = 0;
    int End = Members.size() - 1;
    int TeamCount = 0;
    
    while (Start < End)
    {
        if (Members[Start] + Members[End] >= M)
        {
            TeamCount++;
            Start++;
            End--;
        }
        else
        {
            Start++;
        }
    }
    
    cout << TeamCount;

    return 0;
}