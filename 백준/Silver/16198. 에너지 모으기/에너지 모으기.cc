#include <iostream>

using namespace std;

int n;
bool visited[11];
int energy[11];
int answer = 0;

void bt(int cnt, int result)
{
    if (cnt == n - 2) return;
    
    for (int i = 1; i < n - 1; i++)
    {
        if (visited[i]) continue;
        
        int left = i - 1, right = i + 1;
        while (left >= 0 && visited[left]) left--;
        while (right < n && visited[right]) right++;
        
        int temp = result + (energy[left] * energy[right]);
        answer = max(answer, temp);
        
        visited[i] = true;
        bt(cnt + 1, temp);
        visited[i] = false;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> energy[i];

    bt(0, 0);
    
    cout << answer;
    
    return 0;
}