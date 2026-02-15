#include <string>
#include <sstream>
#include <iostream>
#include <vector>

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
    if (Minute < 10) Result += "0";
    Result += to_string(Minute);
    Result += ":";
    if (Second < 10) Result += "0";
    Result += to_string(Second);
        
    return Result;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    
    if (op_start <= pos && pos <= op_end) pos = op_end;
    
    for (string Command : commands)
    {
        int IntTime = GetIntTime(pos);
        if (Command == "prev")
        {
            pos = GetStringTime(max(0, IntTime - 10));
        }
        else
        {
            int MAX_LEN = GetIntTime(video_len);
            pos = GetStringTime(min(MAX_LEN, IntTime + 10));
        }
        
        if (op_start <= pos && pos <= op_end) pos = op_end;
    }
    return pos;
}