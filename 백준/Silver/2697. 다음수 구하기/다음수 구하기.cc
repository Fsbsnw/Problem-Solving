#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int t = 0; t < n; t++) {
        string snum;
        cin >> snum;

        int i = snum.size() - 2;
        
        while (i >= 0 && snum[i] >= snum[i + 1]) {
            i--;
        }

        if (i == -1) {
            cout << "BIGGEST" << '\n';
        } else {
            int j = snum.size() - 1;
            while (snum[j] <= snum[i]) {
                j--;
            }
            swap(snum[i], snum[j]);

            reverse(snum.begin() + i + 1, snum.end());

            cout << snum << '\n';
        }
    }

    return 0;
}