#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, k;
vector<int> cards;
set<string> numbers;
bool visited[10];

void search(string curNum, int cnt)
{
    if (cnt == k) 
    {
        numbers.insert(curNum);
        return;
    }
    
    for (int i = 0; i < cards.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            search(curNum + to_string(cards[i]), cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        cards.push_back(temp);
    }
    
    search("", 0);
    
    cout << numbers.size();

    return 0;
}