#include <iostream>

using namespace std;

bool IsContain(int num)
{
    string temp = to_string(num);
    
    for (int i = 0; i <= temp.size() - 3; i++)
    {
        if (temp[i] == '6' && temp[i + 1] == '6' && temp[i + 2] == '6') return true;
    }
    return false;
}

int main()
{
    int n; cin >> n;
    
    int num = 666;
    int cnt = 0;
    while (cnt < n)
    {
        if (IsContain(num)) 
        {
            cnt++;
        }
        num++;
    }
    cout << num - 1;

    return 0;
}
