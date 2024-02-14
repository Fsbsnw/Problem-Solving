#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> counting = {{'R', 0}, {'T', 0}, {'C', 0}, {'F', 0}, {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0}};
    
    for (int i = 0; i < choices.size(); i++)
    {
        char first = survey[i][0];
        char second = survey[i][1];
        
        switch (choices[i])
        {
            case 1:
                counting[first] += 3;
                break;
            case 2:
                counting[first] += 2;
                break;
            case 3:
                counting[first] += 1;
                break;
            case 5:
                counting[second] += 1;
                break;
            case 6:
                counting[second] += 2;
                break;
            case 7:
                counting[second] += 3;
                break;
            default:
                break;
        }
    }
    
    (counting['R'] < counting['T']) ? answer += 'T' : answer += 'R';
    (counting['C'] < counting['F']) ? answer += 'F' : answer += 'C';
    (counting['J'] < counting['M']) ? answer += 'M' : answer += 'J';
    (counting['A'] < counting['N']) ? answer += 'N' : answer += 'A';
         
    return answer;
}