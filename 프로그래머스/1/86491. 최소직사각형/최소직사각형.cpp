#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int mw = 0, mh = 0;

    for (const vector<int>& size : sizes)
    {
        mw = max(mw, max(size[0], size[1]));
        mh = max(mh, min(size[0], size[1]));
    }
    
    return mw * mh;
}