#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int mw = 0, mh = 0;
    
    for (auto pair : sizes)
    {
        mw = max(mw, max(pair[0], pair[1]));
        mh = max(mh, min(pair[0], pair[1]));
    }
    return mw * mh;
}