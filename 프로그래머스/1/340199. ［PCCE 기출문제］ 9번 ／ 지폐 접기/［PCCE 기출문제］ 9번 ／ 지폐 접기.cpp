#include <string>
#include <vector>

using namespace std;

bool case_1(vector<int> wallet, vector<int> bill)
{
    return (wallet[0] >= bill[0] && wallet[1] >= bill[1]);
}
bool case_2(vector<int> wallet, vector<int> bill)
{
    return (wallet[0] >= bill[1] && wallet[1] >= bill[0]);
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    while (!case_1(wallet, bill) && !case_2(wallet, bill))
    {
        if (bill[0] > bill[1]) bill[0] /= 2;
        else bill[1] /= 2;
        
        answer++;
    }
    
    return answer;
}