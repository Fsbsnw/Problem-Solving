#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int DP[1000001][2];

struct FNode
{
    FNode(int InID) : ID(InID) {};
    int ID = 0;
    vector<FNode*> Children;
};

class UTree
{
public:
    UTree(int ID)
    {
        Root = new FNode(ID);
        Index[ID] = Root;
    }

    void Insert(int A, int B)
    {
        FNode* ANode = GetOrCreate(A);
        FNode* BNode = GetOrCreate(B);
        
        ANode->Children.push_back(BNode);
        BNode->Children.push_back(ANode);
    }
    
    int GetMinDP()
    {
        return CalcMinDP(Root, nullptr);
    }
    
private:
    FNode* Root;
    
    FNode* GetOrCreate(int ID)
    {
        if (Index.find(ID) == Index.end())
        {
            Index[ID] = new FNode(ID);
        }
        return Index[ID];
    }
    
    int CalcMinDP(FNode* Node, FNode* Parent)
    {
        DP[Node->ID][0] = 0;
        DP[Node->ID][1] = 1;
        
        for (FNode* Child : Node->Children)
        {
            if (Child == Parent) continue;
            
            CalcMinDP(Child, Node);
            int Child0 = DP[Child->ID][0];
            int Child1 = DP[Child->ID][1];
            
            DP[Node->ID][0] += DP[Child->ID][1];
            DP[Node->ID][1] += min(Child0, Child1);
        }
        
        return min(DP[Node->ID][0], DP[Node->ID][1]);
    }
    
    unordered_map<int, FNode*> Index;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    UTree* Tree = new UTree(1);
    
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        
        Tree->Insert(a, b);
    }
    
    cout << Tree->GetMinDP();

    return 0;
}