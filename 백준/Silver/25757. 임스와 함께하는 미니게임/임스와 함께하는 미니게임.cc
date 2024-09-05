#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<string> Player;
    int n;
    char c;
    cin >> n >> c;
    
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        Player.insert(s);
    }
    
    int result = 0;
    if (c == 'Y') 
    {
        result = Player.size(); 
    } 
    else if (c == 'F') 
    {
        result = Player.size() / 2; 
    } 
    else if (c == 'O') 
    {
        result = Player.size() / 3; 
    }
    cout << result;

    return 0;
}