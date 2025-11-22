#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode*> Child;
    // TrieNode* Child[10] = {nullptr, };
    bool bIsEnd = false;
};

class Trie
{
    private:
        TrieNode* Root;
    public:
        Trie()
        {
            Root = new TrieNode();
        }
    
        bool InsertAndCheck(const string& Word)
        {
            TrieNode* Current = Root;
            for (char c : Word)
            {                
                if (Current->bIsEnd) return false;
                
                if (Current->Child.find(c) == Current->Child.end())
                {
                    Current->Child[c] = new TrieNode();
                }
                
                Current = Current->Child[c];
            }
            
            Current->bIsEnd = true;
            
            for (int i = 0; i < 10; ++i)
            {
                if (Current->Child.find(i + '0') != Current->Child.end()) return false;
            }
            
            return true;
        }
};

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    Trie* PhoneBook = new Trie();
    
    for (string s : phone_book)
    {
        if (!PhoneBook->InsertAndCheck(s)) answer = false;
    }
    
    return answer;
}
