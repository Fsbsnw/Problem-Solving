#include <string>
#include <vector>

using namespace std;

int LogToTime(int Log)
{
    int result = Log;
    if (result % 100 >= 60)
    {
        result += 100;
        result -= 60;
    }
    return result;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int num = schedules.size();
    
    for (int Case = 0; Case < num; Case++)
    {
        vector<int> currlog = timelogs[Case];   
        int temp = startday - 1;
        bool winner = true;        
        
        for (int i = 0; i < 7; i++)
        {
            temp++;
            if (temp > 7) temp %= 7;
            if (temp >= 6) 
            {
                continue;
            }
            if (LogToTime(currlog[i]) > LogToTime(schedules[Case] + 10))
            {
                winner = false;
                break;
            }
        }
        if (winner) answer++;
    }
    
    return answer;
}