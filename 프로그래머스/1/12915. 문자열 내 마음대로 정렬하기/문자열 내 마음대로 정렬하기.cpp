#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Target;

bool Compare(string a, string b)
{
    if (a[Target] == b[Target]) return a < b;
    return a[Target] < b[Target];
}

vector<string> solution(vector<string> strings, int n) {
    Target = n;
    
    sort(strings.begin(), strings.end(), Compare);
    
    return strings;
}