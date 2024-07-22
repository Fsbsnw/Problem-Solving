#include <iostream>
#include <vector>

using namespace std;

int N, result = 0;
vector<pair<int, int>> v;

void bt(int n) 
{
    if (n == N) 
    {
        int tmp = 0;
        for (int i = 0; i < N; i++) 
        {
            if (v[i].first <= 0) tmp++;
        }
        
        result = max(result, tmp);
        return;
    }
    if (v[n].first <= 0) {
        bt(n + 1);
        return;
    }

    bool tf = false;
    for (int i = 0; i < N; i++) {
        if (n == i) continue;
        if (v[i].first <= 0) continue;

        tf = true;
        v[i].first -= v[n].second;
        v[n].first -= v[i].second;
        bt(n + 1);
        v[i].first += v[n].second;
        v[n].first += v[i].second;
    }

    if (!tf) bt(n + 1);
}

int main() 
{
    cin >> N;

    int S, W;
    for (int i = 0; i < N; i++) 
    {
        cin >> S >> W;
        v.push_back({ S,W });
    }

    bt(0);
    
    cout << result;

    return 0;
}