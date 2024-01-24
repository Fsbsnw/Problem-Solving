#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    auto min = min_element(arr.begin(), arr.end());
    arr.erase(min);    
    
    return !arr.empty() ? arr : vector<int>{-1};
}