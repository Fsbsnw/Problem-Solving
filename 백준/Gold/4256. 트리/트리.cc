#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;
vector<int> inorder;

void PostOrder(int start, int end, int pos)
{
    for (int i = start; i < end; i++)
    {
        if (preorder[pos] == inorder[i])
        {
            PostOrder(start, i, pos + 1);
            PostOrder(i + 1, end, pos + i + 1 - start);
            cout << preorder[pos] << ' ';
            
            return;   
        }
    }
}


int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        cin >> n;
        
        preorder = vector<int>(n, 0);
        inorder = vector<int>(n, 0);
        
        for (int j = 0; j < n; j++)
        {
            cin >> preorder[j];
        }
        
        for (int j = 0; j < n; j++)
        {
            cin >> inorder[j];
        }
        
        PostOrder(0, n, 0);
        cout << '\n';
    }

    return 0;
}
