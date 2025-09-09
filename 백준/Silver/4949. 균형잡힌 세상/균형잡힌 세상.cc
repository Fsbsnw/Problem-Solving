#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    string S;
    
    while (getline(cin, S)) 
    {
        if (S == ".") break;
        
        vector<char> Brackets;
        bool bPerfectNum = true;
        
        for (char c : S) 
        {
            if (c == '(' || c == '[') 
            {
                Brackets.push_back(c);
            } 
            else if (c == ')') 
            {
                if (Brackets.empty() || Brackets.back() != '(') 
                {
                    bPerfectNum = false;
                    break;
                }
                Brackets.pop_back();
            } 
            else if (c == ']') 
            {
                if (Brackets.empty() || Brackets.back() != '[') 
                {
                    bPerfectNum = false;
                    break;
                }
                Brackets.pop_back();
            }
        }
        
        if (!Brackets.empty()) bPerfectNum = false;
        cout << (bPerfectNum ? "yes" : "no") << '\n';
    }
    
    return 0;
}
