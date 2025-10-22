#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, char> dictionary = 
{
    {"zero", '0'},
    {"one", '1'},
    {"two", '2'},
    {"three", '3'},
    {"four", '4'},
    {"five", '5'},
    {"six", '6'},
    {"seven", '7'},
    {"eight", '8'},
    {"nine", '9'}
};

int solution(string s) {
    string word = "", temp = "";
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            temp += s[i];
            continue;
        }
        
        word += s[i];
        
        if (dictionary.find(word) != dictionary.end())
        {
            temp += dictionary[word];
            word = "";
        }
    }
    
    return stoi(temp);
}