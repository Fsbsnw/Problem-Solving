#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int board[10][10];
bool visited[10][10];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int ans = 1e9;

bool check(int x, int y) {
    if (visited[x][y]) return false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visited[nx][ny]) return false;
    }
    return true;
}

int cost(int x, int y) {
    int sum = board[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        sum += board[nx][ny];
    }
    return sum;
}

void plant(int count, int totalCost) {
    if (count == 3) {
        ans = min(ans, totalCost);
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (check(i, j)) {
                visited[i][j] = true;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    visited[nx][ny] = true;
                }

                plant(count + 1, totalCost + cost(i, j));

                visited[i][j] = false;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    visited[nx][ny] = false;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    plant(0, 0);
    cout << ans << endl;

    return 0;
}
