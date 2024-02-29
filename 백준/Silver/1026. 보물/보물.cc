#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> a;
    vector<int> b;
    int N, num;
    int answer = 0;
    
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		b.push_back(num);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());
    
	for (int i = 0; i < N; i++) {
		answer += a[i] * b[i];
	}
	cout << answer;
}