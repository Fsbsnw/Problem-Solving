#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

int DP[300001][2];

struct FNode
{
    FNode(int InID, int InSale) : ID(InID), Sale(InSale) {};
    
    int ID = 0;
    int Sale = 0;
    vector<FNode*> Children;
};

class UTree
{
public:
    UTree(int RootID, int RootSale)
    {
        Root = new FNode(RootID, RootSale);
        Index[RootID] = Root;
    }
    
    void Insert(int ParentID, int ParentSale, int ChildID, int ChildSale)
    {
        FNode* PNode = GetOrCreate(ParentID, ParentSale);
        FNode* CNode = GetOrCreate(ChildID, ChildSale);
        
        PNode->Children.push_back(CNode);
    }
    
    int CalcDP()
    {
        return DFS(Root);
    }
    
    void Print()
    {
        DFSPrint(Root, 0);
    }
    
private:
    FNode* Root;
    
    FNode* GetOrCreate(int ID, int Sale)
    {
        if (Index.find(ID) == Index.end())
        {
            Index[ID] = new FNode(ID, Sale);
        }
        return Index[ID];
    }
    
    int DFS(FNode* Node)
    {        
        int Sum_Sales = 0;
        int Min_Child = INT_MAX;
        bool bAtLeastOne = false;
        
        for (FNode* Child : Node->Children)
        {
            DFS(Child);
            int Child0 = DP[Child->ID][0];
            int Child1 = DP[Child->ID][1];
            
            if (Child1 <= Child0) bAtLeastOne = true;
            Sum_Sales += min(Child0, Child1);
            Min_Child = min(Min_Child, Child1 - Child0);
        }
        
        DP[Node->ID][1] = Sum_Sales + Node->Sale;
        if (Node->Children.empty()) 
        {
            DP[Node->ID][0] = 0;
            return 0;
        }
        
        if (bAtLeastOne) DP[Node->ID][0] = Sum_Sales;
        else DP[Node->ID][0] = Sum_Sales + Min_Child;
        
        return min(DP[Node->ID][1], DP[Node->ID][0]);
    }
    
    void DFSPrint(FNode* Node, int Depth)
    {
        cout << Node->ID << " (Sale : " << Node->Sale << ")\n";
        
        for (FNode* Child : Node->Children)
        {
            for (int i = 0; i <= Depth; ++i) 
                cout << "   ";
            DFSPrint(Child, Depth + 1);
        }
    }
    
    unordered_map<int, FNode*> Index;
};

int solution(vector<int> sales, vector<vector<int>> links) {
    
    UTree* Tree = new UTree(1, sales[0]);
    
    for (vector<int> Pair : links)
    {
        Tree->Insert(Pair[0], sales[Pair[0] - 1], Pair[1], sales[Pair[1] - 1]);
    }    
    
    int answer = 0;
    
    answer = Tree->CalcDP();
    
    return answer;
}