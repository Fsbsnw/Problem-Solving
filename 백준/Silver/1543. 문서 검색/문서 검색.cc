#include <iostream>
#include <string>

using namespace std;

string document, word;

int main()
{
    getline(cin, document);
    getline(cin, word);
    
    int cnt = 0;
    int pos = document.find(word);
    
    while (pos != string::npos)
    {
        cnt++;
        pos = document.find(word, pos + word.size());
    }
    
    cout << cnt;

    return 0;
}
