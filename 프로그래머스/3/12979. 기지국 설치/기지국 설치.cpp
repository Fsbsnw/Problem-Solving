#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, now = 1, idx = 0;

    while (now <= n)
    {
        if (now >= stations[idx] - w && now <= stations[idx] + w)
        {
            now = stations[idx] + w + 1;
            idx++;
        }
        else
        {
            now += 2 * w + 1;
            answer++;
        }
    }

    return answer;
}