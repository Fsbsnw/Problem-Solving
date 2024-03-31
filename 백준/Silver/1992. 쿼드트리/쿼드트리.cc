#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> arr;

void Divide(int x, int y, int v)
{
    int half = v / 2;
    bool canPass = true;
    
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (arr[x][y] != arr[x + i][y + j]) 
            {
                canPass = false;
                break;
            }
        }
        if (!canPass) break;
    }
    
    if (canPass)
    {
        cout << arr[x][y];
    }
    else
    {
        cout << '(';
        Divide(x, y, half);
        Divide(x, y + half, half);
        Divide(x + half, y, half);
        Divide(x + half, y + half, half);
        cout << ')';
    }
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        
        arr.push_back(row);
    }
    
    Divide(0, 0, n);
    return 0;
}
