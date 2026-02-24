#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string GetBinary(int num)
{
    string s = "";
    while (num > 0)
    {
        s += to_string(num % 2);
        num /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

vector<int> GetCountZero(string s)
{
    int zero = 0, count = 0;
    
    while (s.size() > 1)
    {
        string temp = "";
        for (char c : s)
        {
            if (c == '1')
            {
                temp += '1';
            }
            else ++zero;
        }
        s = GetBinary(temp.size());
        ++count;
    }
    return {count, zero};
}

vector<int> solution(string s) {
    return GetCountZero(s);
}