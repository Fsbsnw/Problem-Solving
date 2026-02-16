#include <string>
#include <vector>
#include <sstream>

using namespace std;

int GetIntTime(string Target)
{
    stringstream ss(Target);
    string Minute, Second;
    
    getline(ss, Minute, ':');
    getline(ss, Second);
    
    return stoi(Minute) * 60 + stoi(Second);
}

string GetStringTime(int Target)
{
    int Minute = Target / 60;
    int Second = Target % 60;
    string Result = "";
    
    Result += ((Minute < 10) ? "0" : "") + to_string(Minute);
    Result += ":";
    Result += ((Second < 10) ? "0" : "") + to_string(Second);
    
    return Result;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    
    if (op_start <= pos && pos <= op_end) pos = op_end;
    
    for (string Command : commands)
    {
        if (Command == "prev")
        {
            pos = GetStringTime(max(0, GetIntTime(pos) - 10));
        }
        else
        {
            int MAX_LEN = GetIntTime(video_len);
            pos = GetStringTime(min(MAX_LEN, GetIntTime(pos) + 10));
        }
        
        if (op_start <= pos && pos <= op_end) pos = op_end;
    }
    return pos;
}