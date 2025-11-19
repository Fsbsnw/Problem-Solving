#include <bits/stdc++.h>
using namespace std;

int N, C, M;
int capacityLeft[2001];

struct Package {
    int from, to, amount;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C >> M;

    vector<Package> arr(M);

    for (int i = 0; i < M; ++i) 
    {
        cin >> arr[i].from >> arr[i].to >> arr[i].amount;
    }

    sort(arr.begin(), arr.end(), 
        [](const Package& A, const Package& B) 
        {
            if (A.to == B.to) return A.from < B.from;
            return A.to < B.to;
        }
    );

    for (int i = 1; i <= N; ++i) {
        capacityLeft[i] = C;
    }

    int answer = 0;

    for (auto& p : arr) 
    {
        int from = p.from;
        int to = p.to;
        int amount = p.amount;

        // from → to-1 구간 중 최소 여유 용량 찾기
        int possible = amount;
        for (int i = from; i < to; ++i) 
        {
            possible = min(possible, capacityLeft[i]);
        }
        
        if (possible <= 0) continue;

        // 싣기
        for (int i = from; i < to; ++i) 
        {
            capacityLeft[i] -= possible;
        }

        answer += possible;
    }

    cout << answer;
    return 0;
}
