#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n; cin >> n;
    string student[1001];
    
    for (int i = 0; i < n; i++)
    {
        cin >> student[i];
    }
    
    int len = student[0].size();
    int cnt = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        set<string> numbers;
        
        for (int k = 0; k < n; k++)
        {
            string cur = "";
            for (int j = i; j < len; j++)
            {
                cur += student[k][j];
            }
            if (numbers.find(cur) == numbers.end())
            {
                numbers.insert(cur);
            }
            else
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;

    return 0;
}