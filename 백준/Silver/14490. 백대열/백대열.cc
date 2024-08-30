#include <iostream>
#include <string>

using namespace std;

int gcd(int n,int m)
{
    if(n % m == 0) return m;
    else return gcd(m, n % m);
}

string s;
string temp;
int n,m;

int main()
{
    cin >> s;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ':')
        {
            temp = s.substr(0, i);
            n = stoi(temp);

            temp = s.substr(i + 1, s.length());
            m = stoi(temp);
            break;
        }
    }

    int num = gcd(n, m);
    cout << n / num << ":" << m / num; 
}