#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lh = 10, rh = 12;
    
    for (int i : numbers)
    {
        if (i == 1 || i == 4 || i == 7)
        {
            answer += 'L';
            lh = i;
        } 
        else if (i == 3 || i == 6 || i == 9)
        {
            answer += 'R';
            rh = i;
        } 
        // 2, 5, 8, 0인 경우
        else
        {
            int cntl = 0, cntr = 0, temp = 0;
            if (i == 0)
            {
                temp = 11;
            }
            else
            {
                temp = i;
            }
            // 왼쪽 손 기준
            if ((lh + 1) % 3 == temp % 3)
            {
                cntl += 1 + abs(int(lh / 3) - int(temp / 3));
            } 
            else
            {
                cntl += abs(int(lh / 3) - int(temp / 3));
            }
            
            // 오른쪽 손 기준
            if ((rh - 1) % 3 == temp % 3)
            {
                cntr += 1 + abs(int((rh - 1) / 3) - int(temp / 3));
            } 
            else
            {
                cntr += abs(int((rh - 1) / 3) - int(temp / 3));
            }
            
            // 두 손과의 차이 비교
            if (cntl < cntr)
            {
                answer += 'L';
                lh = temp;
            } 
            else if (cntl > cntr)
            {
                answer += 'R';
                rh = temp;
            }
            else
            {
                if (hand == "right")
                {
                    answer += 'R';
                    rh = temp;
                }
                else
                {
                    answer += 'L';
                    lh = temp;
                }
            }
        }
    }
    
    return answer;
}