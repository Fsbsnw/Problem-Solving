#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> arr;
vector<pair<int, int>> chick;
vector<pair<int, int>> house;
vector<bool> chickVisited;

int result = 1000000000;

int Calc(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void CalcMinPath()
{
    int temp = 0;
    for (pair<int, int> h : house)
    {
        int answer = 1000000000;
        for (int i = 0; i < chickVisited.size(); i++)
        {
            if (chickVisited[i])
            {
                answer = min(answer, Calc(chick[i], h));
            }
        }
        temp += answer;
    }
    result = min(result, temp);
}

void SelectChicken(int idx, int cnt)
{
    if (cnt == m) return CalcMinPath();
    if (idx == chick.size()) return;
    
    for (int i = idx; i < chick.size(); i++)
    {
        chickVisited[i] = true;
        SelectChicken(i + 1, cnt + 1);
        chickVisited[i] = false;
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            
            if (a == 1)
            {
                house.push_back(make_pair(i, j));
                temp.push_back(100);
            }
            else if (a == 2)
            {
                chick.push_back(make_pair(i, j));
                chickVisited.push_back(false);
                temp.push_back(a);
            }
            else
            {
                temp.push_back(a);
            }
        }
        arr.push_back(temp);
    }
    
    SelectChicken(0, 0);
    
    cout << result;
    
    return 0;
}
