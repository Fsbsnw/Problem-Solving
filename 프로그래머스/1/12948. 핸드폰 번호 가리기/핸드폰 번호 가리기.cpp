#include <string>
#include <vector>

using namespace std;

class Blind {
public:
    virtual string blind(string number) = 0;
};

class Blinder : public Blind {
public:
    string blind(string number) override {
        int len = number.size();
        for (int i = 0; i < len - 4; i++) {
            number[i] = '*';
        }
        return number;
    }
};

string solution(string phone_number) {
    string answer = "";
    Blinder blinder;
    answer = blinder.blind(phone_number);
    
    return answer;
}