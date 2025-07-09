#include <iostream>
#include <vector>

using namespace std;

void LogSequenceToString(vector<int> Sequence)
{
    for (int Num : Sequence)
    {
        cout << Num << ' ';
    }
    cout << '\n';
}

void CalcSequence(int TargetNumber, int TargetLength, vector<int> Sequence)
{
    if (Sequence.size() == TargetLength)
    {
        LogSequenceToString(Sequence);
        return;
    }
    for (int CheckNum = 1; CheckNum <= TargetNumber; CheckNum++)
    {
        if (Sequence.empty() || CheckNum >= Sequence.back())
        {
            Sequence.push_back(CheckNum);
            CalcSequence(TargetNumber, TargetLength, Sequence);
            Sequence.pop_back();
        }
    }
}

int main()
{
    int N, M; cin >> N >> M;
    
    CalcSequence(N, M, vector<int>());
    
    return 0;
}