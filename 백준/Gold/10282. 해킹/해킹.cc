#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


#define MAX (10001)
#define INF (987654321)

using namespace std;

int T, N, D, C;
int dp[MAX];

void dijkstra(vector<pair<int, int>> edge[]) {
	dp[C] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,C });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curTime = pq.top().first;
		pq.pop();
		
		if (dp[cur] < curTime)
			continue;

		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].first;
			int nextTime = curTime + edge[cur][i].second;

			if (nextTime < dp[next]) {
				dp[next] = nextTime;
				pq.push({ nextTime, next });
			}
		}
	}
	
	int cnt=0,ans = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[i] != INF) {
			cnt++;
			ans = max(ans, dp[i]);
		}
	}
	cout << cnt << ' ' << ans<< '\n';

}

int main() {
	cin >> T;
	
	while (T--) {
		vector<pair<int, int>> edge[MAX];
		cin >> N >> D >> C;
		int a, b, s;
		for (int i = 0; i < D; i++) {
			cin >> a >> b >> s;
			edge[b].push_back({ a,s });
		}
		fill_n(dp, MAX, INF);
		dijkstra(edge);
	}

	return 0;
}