#include <iostream>
#include <set>
#include <queue>

using namespace std;

int Arr[5][5];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

set<string> UniqueNumbers;

void BFS(int startX, int startY)
{
    queue<pair<pair<int, int>, string>> q;
    q.push({{startX, startY}, to_string(Arr[startX][startY])});

    while (!q.empty())
    {
        auto [pos, number] = q.front();
        q.pop();

        if (number.size() == 6)
        {
            UniqueNumbers.insert(number);
            continue;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = pos.first + dx[dir];
            int ny = pos.second + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
            {
                q.push({{nx, ny}, number + to_string(Arr[nx][ny])});
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> Arr[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            BFS(i, j);

    cout << UniqueNumbers.size() << endl;

    return 0;
}
