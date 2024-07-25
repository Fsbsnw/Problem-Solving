#include <iostream>
#include <vector>

using namespace std;

int t;

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n; cin >> n;
        vector<char> cards(n);
        string result = "";
        
        for (int i = 0; i < n; i++) 
        {
            cin >> cards[i];
            
            if (result.size() == 0) 
            {
                result += cards[i];
                continue;
            }
            
            if (result[0] < cards[i]) result += cards[i];
            else result = cards[i] + result;
        }
        
        cout << result <<'\n';
    }

    return 0;
}