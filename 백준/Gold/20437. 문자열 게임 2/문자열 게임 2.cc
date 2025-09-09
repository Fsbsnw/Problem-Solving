#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int c = 0; c < T; c++)
    {
        string S;
        int K;
        cin >> S >> K;
        
        vector<int> Alphabets[26];
        
        for (int i = 0; i < S.size(); i++)
        {
            Alphabets[S[i] - 'a'].push_back(i);
        }
        
        int MAX = -1;
        int MIN = 100001;
        
        for (int j = 0; j < 26; j++)
        {
            for (int i = 0; i + K - 1 < Alphabets[j].size(); i++)
            {
                int Left = Alphabets[j][i];
                int Right = Alphabets[j][i + K - 1];
                int Length = Right - Left + 1;
                
                MAX = max(MAX, Length);
                MIN = min(MIN, Length);
            }
        }
        
        if (MAX == -1) 
        {
            cout << -1 << '\n';
        } 
        else 
        {
            cout << MIN << ' ' << MAX << '\n';
        }
    }

    return 0;
}