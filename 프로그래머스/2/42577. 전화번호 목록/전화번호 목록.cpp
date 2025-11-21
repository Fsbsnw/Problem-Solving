#include <iostream>
#include <vector>

using namespace std;

struct TrieNode
{
    TrieNode* Child[10] = {nullptr, };
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
                int Index = c - '0';
                
                if (Current->bIsEnd) return false;
                
                if (Current->Child[Index] == nullptr)
                {
                    Current->Child[Index] = new TrieNode();
                }
                
                Current = Current->Child[Index];
            }
            
            Current->bIsEnd = true;
            
            for (int i = 0; i < 10; ++i)
            {
                if (Current->Child[i] != nullptr) return false;
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
