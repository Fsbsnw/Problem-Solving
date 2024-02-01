#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int arr3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int idx = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    
    for (int i = 0; i < answers.size(); i++) {
        if (arr1[i % 5] == answers[i]) {
            cnt1++;
        }
        if (arr2[i % 8] == answers[i]) {
            cnt2++;
        }
        if (arr3[i % 10] == answers[i]) {
            cnt3++;
        }
    }
    int arr[3] = {cnt1, cnt2, cnt3};
    int* maxV = max_element(arr, end(arr));
    
    for (int i = 0; i < 3; i++) {
        if (*maxV == arr[i]) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}