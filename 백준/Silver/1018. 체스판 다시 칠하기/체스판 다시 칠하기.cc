#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<string> arr;
vector<string> compare;
vector<string> compare2;
int mmin = 2500;

void FindChanges(int x, int y)
{
    if (x + 8 > n || y + 8 > m) return;
    
    int cnt1 = 0, cnt2 = 0;
    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if (arr[i][j] != compare[i][j])
            {
                cnt1++;
            }
            if (arr[i][j] != compare2[i][j])
            {
                cnt2++;
            }
        }
    }
    mmin = min(min(cnt1, cnt2), mmin);
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        string temp, temp2;
        for (int j = 0; j < m; j++)
        {
            if ((j + i) % 2 == 0)
            {
                temp += "B";
                temp2 += "W";
            }
            else
            {
                temp += "W";
                temp2 += "B";
            }
        }
        compare.push_back(temp);
        compare2.push_back(temp2);
    }
    
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        arr.push_back(row);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            FindChanges(i, j);
        }
    }
    cout << mmin;
    
    return 0;
}
