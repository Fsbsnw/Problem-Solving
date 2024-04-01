#include <iostream>
#include <vector>

using namespace std;

int n;
int cntMinus = 0, cntZero = 0, cntPlus = 0;
vector<vector<int>> arr;

void Divide(int x, int y, int size)
{
    int oneThird = size / 3;
    bool canPass = true;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
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
        if (arr[x][y] == -1) cntMinus++;
        else if (arr[x][y] == 0) cntZero++;
        else cntPlus++;
    }
    else
    {
        Divide(x, y, oneThird);
        Divide(x, y + oneThird, oneThird);
        Divide(x, y + oneThird + oneThird, oneThird);
        Divide(x + oneThird, y, oneThird);
        Divide(x + oneThird, y + oneThird, oneThird);
        Divide(x + oneThird, y + oneThird + oneThird, oneThird);
        Divide(x + oneThird + oneThird, y, oneThird);
        Divide(x + oneThird + oneThird, y + oneThird, oneThird);
        Divide(x + oneThird + oneThird, y + oneThird + oneThird, oneThird);
    }
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int temp2;
            cin >> temp2;
            temp.push_back(temp2);
        }
        arr.push_back(temp);
    }
    
    Divide(0, 0, n);

    cout << cntMinus << endl;
    cout << cntZero << endl;
    cout << cntPlus << endl;
    
    return 0;
}
