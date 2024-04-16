#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> inorder;
vector<int> postorder;

void PreOrder(int start, int end, int pos)
{
    int root = postorder[pos];
    
    for (int i = start; i <= end; i++)
    {
        if (root == inorder[i])
        {
            cout << root << ' ';
            PreOrder(start, i - 1, pos - end + (i - 1));
            PreOrder(i + 1, end, pos - 1);
        }
    }
}

int main()
{
    cin >> n;
    inorder = vector<int>(n, 0);
    postorder = vector<int>(n, 0);
    
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }
    
    PreOrder(0, n - 1, n - 1);
    
    return 0;
}
