#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task
{
    int Day;
    int Penalty;
    int Index;
};

bool Compare(const Task& A, const Task& B)
{
    int LeftValue = A.Day * B.Penalty;
    int RightValue = A.Penalty * B.Day;
    
    if (LeftValue == RightValue)
    {
        return A.Index < B.Index;
    }
    return LeftValue < RightValue;
}

int main()
{
    int n;
    cin >> n;
    
    vector<Task> Tasks(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> Tasks[i].Day >> Tasks[i].Penalty;
        Tasks[i].Index = i + 1;
    }
    
    sort(Tasks.begin(), Tasks.end(), Compare);
    
    for (const Task& CurrentTask : Tasks)
    {
        printf("%d ", CurrentTask.Index);
    }

    return 0;
}