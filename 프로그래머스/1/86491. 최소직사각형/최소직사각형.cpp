#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int ml = 0, mr = 0;

    for (vector<int>& size : sizes) {
        ml = max(ml, max(size[0], size[1]));
        mr = max(mr, min(size[0], size[1]));
    }

    return ml * mr;
}