#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int cnt = 0;
    for (int i = 0; i < t.size() - p.size() + 1; i++) {
        string temp_str = t.substr(i, p.size());
        long long temp1 = stoll(temp_str);
        long long temp2 = stoll(p);
        if (temp1 <= temp2) {
            cnt++;
        }
    }
    return cnt;
}