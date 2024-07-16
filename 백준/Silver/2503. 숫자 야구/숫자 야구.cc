#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> possibleNumbers(1000, true);

    for (int i = 123; i <= 987; i++) {
        string numStr = to_string(i);
        
        if (numStr[0] == numStr[1] || numStr[1] == numStr[2] || numStr[0] == numStr[2]) {
            possibleNumbers[i] = false;
        }
        if (numStr[0] == '0' || numStr[1] == '0' || numStr[2] == '0') {
            possibleNumbers[i] = false;
        }
    }

    for (int q = 0; q < n; q++) {
        int guessedNumber, strikeCount, ballCount;
        cin >> guessedNumber >> strikeCount >> ballCount;

        for (int i = 123; i <= 987; i++) {
            if (!possibleNumbers[i]) continue;

            string actualStr = to_string(i);
            string guessStr = to_string(guessedNumber);

            int strikes = 0, balls = 0;

            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    if (a == b && guessStr[a] == actualStr[b]) strikes++;
                    if (a != b && guessStr[a] == actualStr[b]) balls++;
                }
            }

            if (strikes != strikeCount || balls != ballCount) {
                possibleNumbers[i] = false;
            }
        }
    }

    int possibleCount = 0;
    for (int i = 123; i <= 987; i++) {
        if (possibleNumbers[i]) possibleCount++;
    }

    cout << possibleCount;

    return 0;
}