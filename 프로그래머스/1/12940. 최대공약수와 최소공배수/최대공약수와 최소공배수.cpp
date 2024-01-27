#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd = n;
    int ngcd = m;

    while (ngcd > 0) {
        int temp = gcd;
        gcd = ngcd;
        ngcd = temp % ngcd;        
    }
    
    answer.push_back(gcd);
    answer.push_back(gcd * (n / gcd) * (m / gcd));
    
    return answer;
}