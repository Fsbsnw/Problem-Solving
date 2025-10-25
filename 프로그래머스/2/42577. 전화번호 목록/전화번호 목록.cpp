#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    set<string> S(phone_book.begin(), phone_book.end());
    
    for (auto It = S.begin(); next(It) != S.end(); ++It)
    {
        string Curr = *It;
        string Next = *next(It);
        if (Next.substr(0, Curr.size()) == Curr) answer = false;
    }
    
    return answer;
}
