#include <iostream>
#include <algorithm>

using namespace std;

bool comp(char a, char b)
{
    if (a > b) return true;
    return false;
}

int main()
{
    string s; cin >> s;
    
    sort(s.begin(), s.end(), comp);
    
    cout << s;

    return 0;
}