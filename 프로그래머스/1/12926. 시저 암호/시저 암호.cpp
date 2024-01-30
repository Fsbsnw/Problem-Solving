#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            if (isupper(s[i])) {
                s[i] = toupper(alpha[(s[i] - 65 + n) % alpha.size()]);
            } else {
                s[i] = alpha[(s[i] - 97 + n) % alpha.size()];
            }
        }
    }
    return s;
}