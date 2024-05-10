#include <iostream>
#include <algorithm>

using namespace std;
int alpha[26];

bool cmp(int &a, int &b) {
	return a > b;
}
int main() {
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		
		int weight = 1;
		for (int j = s.length()-1; j >= 0; j--) {
			alpha[s[j]-'A'] += weight;
			weight *= 10;
		}
	}

	sort(alpha, alpha + 26, cmp);

	int num = 9;
	int answer = 0;
	for (int i = 0; i < 26; i++) {
	    if (alpha[i] == 0) break;
	    
		answer += alpha[i] * num;
		num--;
	}
	cout << answer;
	
	return 0;
}