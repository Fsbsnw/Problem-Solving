#include <string>
#include <vector>
#include <cctype>

using namespace std;

void strip(string &s)
{
    if (!s.empty() && s[0] == '.')
    {
        s.erase(0, 1);
    }
    
    if (!s.empty() && s[s.size() - 1] == '.')
    {
        s.pop_back();
    }
}

string solution(string new_id) {
    string answer = "", temp = "", temp2 = "";
    
    // 소문자 치환 및 기타 문자 제거
    for (int i = 0; i < new_id.size(); i++)
    {
        char is = new_id[i];
        if (isalpha(is) || isdigit(is) || is == '-' || is == '_' || is == '.')
        {
            if (isalpha(is))
            {
                temp += tolower(is);
            }
            else if (is == '.')
            {
                if (i + 1 == new_id.size() - 1 || new_id[i + 1] != '.')
                {
                    temp += '.';
                }
            }
            else
            {
                temp += is;
            }
        }
    }
    
    // 마침표 중복 제거
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '.')
        {
            while (temp[i + 1] == '.')
            {
                i++;
            }
            temp2 += '.';
        }
        else
        {
            temp2 += temp[i];
        }
    }
    
    // 양 끝 마침표 제거
    strip(temp2);
    
    if (temp2.empty())
    {
        temp2 += 'a';
    }
    else if (temp2.size() >= 16)
    {
        for (int i = 0; i < 15; i++)
        {
            answer += temp2[i];
        }
        strip(answer);
        return answer;
    }
    
    while (temp2.size() <= 2)
    {
        temp2 += temp2[temp2.size() - 1];
    }
    
    return temp2;
}