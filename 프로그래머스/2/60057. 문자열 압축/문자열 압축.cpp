#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.size();
    vector<int> arr;
    
    if (s.size() == 1) return 1;
    
    for (int i = 1; i <= len / 2; i++)
    {
        string sen = "";
        int cnt = 1;
        for (int j = 0; j < len; j++)        
        {
            if (j + i >= s.size())
            {
                if (cnt > 1)
                {
                    sen += to_string(cnt) + s.substr(j, i);  
                }
                else
                {
                    sen += s.substr(j);
                }
                break;
            }
            if (j + i < len && s.substr(j, i) == s.substr(j + i, i))
            {
                j += i - 1;
                cnt++;
            }
            else
            {
                if (cnt > 1)
                {
                    sen += to_string(cnt) + s.substr(j, i);    
                }
                else
                {
                    sen += s.substr(j, i);   
                }
                
                cnt = 1;
                j += i - 1;
            }
        }
        arr.push_back(sen.size());
    }
    
    return *min_element(arr.begin(), arr.end());
}
