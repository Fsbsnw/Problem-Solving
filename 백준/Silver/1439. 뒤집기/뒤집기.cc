#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int len, zero = 0, one = 0;
    len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] != s[i+1]) {
            if (s[i] == '0') { zero++; }
            else if (s[i] == '1') { one++; }
        }
    }
    cout << min(zero, one);
}
