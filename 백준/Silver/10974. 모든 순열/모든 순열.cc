#include <iostream>
#include <vector>

using namespace std;

int n;
bool visited[9];

void bt(int cnt, vector<int> result)
{
    if (cnt == n) 
    {
        for (int i = 0; i < n; i++)
        {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            result[cnt] = i;
            bt(cnt + 1, result);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    
    vector<int> result(n + 1, 0);
    bt(0, result);

    return 0;
}
