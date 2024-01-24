#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Calculation {
public:
    virtual bool divide(int num, int divisor) = 0;
};

class Calculator : public Calculation {
public:
    bool divide(int num, int divisor) override {
        return num % divisor == 0;
    }
};

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    Calculator calc;
    
    for (int i : arr) {
        if (calc.divide(i, divisor)) {
            answer.push_back(i);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return !answer.empty() ? answer : vector<int>{-1};
}