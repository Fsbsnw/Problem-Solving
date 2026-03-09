#include <iostream>
#include <unordered_map>

using namespace std;

struct FNode
{
    unordered_map<char, FNode*> Children;
};

class UTrie
{
public:
    UTrie()
    {
        Root = new FNode();
    }
    
    void Insert(const string& s)
    {
        FNode* Node = Root;
        
        for (const char& c : s)
        {
            if (Node->Children.find(c) == Node->Children.end())
            {
                Node->Children[c] = new FNode();
            }
            Node = Node->Children[c];
        }
    }
    
    bool Seach(const string& s)
    {
        FNode* Node = Root;
        
        for (const char& c : s)
        {
            if (Node->Children.find(c) != Node->Children.end())
            {
                Node = Node->Children[c];
            }
            else return false;
        }
        return true;
    }
    
private:
    FNode* Root;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    UTrie* Trie = new UTrie();
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i)
    {
        string S;
        cin >> S;
        
        Trie->Insert(S);
    }
    
    int Count = 0;
        
    for (int i = 0; i < M; ++i)
    {
        string S;
        cin >> S;
        
        const bool bFound = Trie->Seach(S);
        Count += bFound;
    }
    cout << Count;

    return 0;
}