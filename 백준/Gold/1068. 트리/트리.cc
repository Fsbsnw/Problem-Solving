#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FNode
{
    FNode(int InNumber) : Number(InNumber) {};
    int Number = 0;
    int Parent = 0;
    vector<FNode*> Children;
};
vector<FNode> Tree;

void RemoveNode(int Number)
{
    int Parent = Tree[Number].Parent;
    
    for (int i = 0; i < Tree[Parent].Children.size(); ++i)
    {
        if (Tree[Parent].Children[i]->Number == Number)
        {
            Tree[Parent].Children.erase(Tree[Parent].Children.begin() + i);
            return;
        }
    }
}

int TreeDFS(FNode* Node)
{
    int LeafCount = 0;
    
    if (Node->Children.empty()) ++LeafCount;
    
    for (FNode* Child : Node->Children)
    {
        LeafCount += TreeDFS(Child);
    }
    return LeafCount;
}

int main()
{
    int N, Root;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        Tree.push_back(FNode(i));
    }
    
    for (int i = 0; i < N; ++i)
    {
        int Parent;
        cin >> Parent;
        
        if (Parent != -1)
            Tree[Parent].Children.push_back(&Tree[i]);
        Tree[i].Parent = Parent;
        
        if (Parent == -1) Root = i;
    }
    
    int RemoveIndex;
    cin >> RemoveIndex;
    
    if (RemoveIndex == Root) cout << 0;
    else 
    {
        RemoveNode(RemoveIndex);
        cout << TreeDFS(&Tree[Root]);
    }

    return 0;
}