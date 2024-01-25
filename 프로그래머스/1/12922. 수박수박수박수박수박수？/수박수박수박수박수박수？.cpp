#include <string>
#include <vector>

using namespace std;

class CreateSTR {
public:
    virtual string makeWaterMelon(int len) = 0;
};

class STRMaker : public CreateSTR {
public:
    string makeWaterMelon(int len) override {
        if (len == 1) {
            return "수";
        }
        string result = "";
        for (int i = 0; i < len / 2; i++) {
            result += "수박";
        }
        if (len % 2 == 1) {
            result += "수";
        }
        return result;
    }
};

string solution(int n) {
    string answer = "";
    STRMaker strMaker;
    answer = strMaker.makeWaterMelon(n);
    return answer;
}