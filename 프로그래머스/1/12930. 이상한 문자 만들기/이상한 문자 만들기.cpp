#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            if (idx % 2 == 0) {
                s[i] = toupper(s[i]);
            } else {
                s[i] = tolower(s[i]);
            }
            idx++;
        } else {
            idx = 0;
        }
    }
    return s;
}