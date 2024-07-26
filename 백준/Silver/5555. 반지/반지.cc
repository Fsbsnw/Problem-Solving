#include <iostream>

using namespace std;

string toFind;
int t;

int main()
{
    cin >> toFind >> t;
    
    int result = 0;
    for (int i = 0; i < t; i++)
    {
        string temp; cin >> temp;
        
        for (int i = 0; i < 20; i++)
        {
            int idx = 0;
            int tidx = i % 10;
            while (idx < toFind.size() && toFind[idx] == temp[tidx])
            {
                idx++;
                tidx = (tidx + 1) % 10;
            }
            
            if (idx == toFind.size()) 
            {
                result++;
                break;
            }
        }
    }
    
    cout << result;

    return 0;
}