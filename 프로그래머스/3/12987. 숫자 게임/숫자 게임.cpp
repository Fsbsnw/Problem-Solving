#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for (int i = 0; i < A.size(); i++)
    {
        int r = i;
        
        while (A[i] >= B[r] && r < A.size())
        {
            r++;
        }
            
        if (r == A.size()) 
        {
            break;
        }
        else
        {
            B[r] = 0;
            answer++;
        }
    }
    
    return answer;
}