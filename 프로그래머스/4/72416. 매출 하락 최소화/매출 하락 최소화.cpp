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
    
    int ID;
    int Sale;
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
    
    void InsertRelation(int ParentID, int ParentSale, int ChildID, int ChildSale)
    {
        FNode* PNode = GetOrCreate(ParentID, ParentSale);
        FNode* CNode = GetOrCreate(ChildID, ChildSale);
        
        PNode->Children.push_back(CNode);
    }
    
    int GetMinSalesDecline()
    {
        CalcMinSales(Root);
        return min(DP[Root->ID][0], DP[Root->ID][1]);
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
    
    void CalcMinSales(FNode* Node)
    {
        DP[Node->ID][1] = Node->Sale;
        
        int Sum_Sales = 0;
        int Min_SalesDecline = INT_MAX;
        bool bAtLeastOne = false;
        
        for (FNode* Child : Node->Children)
        {
            CalcMinSales(Child);
            int Child0 = DP[Child->ID][0];
            int Child1 = DP[Child->ID][1];
            
            if (Child1 <= Child0) bAtLeastOne = true;
            Sum_Sales += min(Child0, Child1);
            Min_SalesDecline = min(Min_SalesDecline, Child1 - Child0);
        }
        
        DP[Node->ID][1] += Sum_Sales;
        if (Node->Children.empty()) return;
        if (bAtLeastOne) DP[Node->ID][0] = Sum_Sales;
        else DP[Node->ID][0] = Sum_Sales + Min_SalesDecline;
    }
    
    unordered_map<int, FNode*> Index;
};

int solution(vector<int> sales, vector<vector<int>> links) {
    
    UTree* Tree = new UTree(1, sales[0]);
    
    for (vector<int> Pair : links)
    {
        Tree->InsertRelation(Pair[0], sales[Pair[0] - 1], Pair[1], sales[Pair[1] - 1]);
    }    
    return Tree->GetMinSalesDecline();
}