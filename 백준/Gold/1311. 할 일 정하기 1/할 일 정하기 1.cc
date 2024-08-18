#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;  // 큰 값으로 초기화 (무한대)

int main() {
    int N;
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(N));  // 비용 행렬
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cost[i][j];
        }
    }

    vector<int> dp(1 << N, INF);  // 모든 상태의 비용을 무한대로 초기화
    dp[0] = 0;  // 시작 상태 (아무 일도 배정되지 않은 상태)의 비용은 0

    // 모든 가능한 상태를 고려
    for (int mask = 0; mask < (1 << N); ++mask) {
        int x = __builtin_popcount(mask);  // 현재 마스크에서 할당된 사람의 수
        for (int j = 0; j < N; ++j) {
            if (!(mask & (1 << j))) {  // 아직 j번 일이 배정되지 않았다면
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[x][j]);
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;  // 모든 일을 배정한 상태의 최소 비용 출력

    return 0;
}
