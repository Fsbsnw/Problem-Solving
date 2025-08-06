#include <iostream>
#include <vector>

using namespace std;

int K;
vector<char> Operators;
bool UsedNumber[10];
string MAX;
string MIN;

bool IsValid(char A, char Oper, char B)
{
    if (Oper == '<') return A < B;
    if (Oper == '>') return A > B;
    return false;
}

void BackTracking(string StringNum)
{
    if (StringNum.size() == K + 1)
    {
        if (MAX.empty() || StringNum > MAX) 
        {
            MAX = StringNum;
        }
        if (MIN.empty() || StringNum < MIN) 
        {
            MIN = StringNum;
        }
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (UsedNumber[i]) continue;
        
        if (!StringNum.empty() && !IsValid(StringNum[StringNum.size() - 1], Operators[StringNum.size() - 1], i + '0'))
        {
            continue;
        }
        
        StringNum += i + '0';
        UsedNumber[i] = true;
        BackTracking(StringNum);
        StringNum.pop_back();
        UsedNumber[i] = false;
    }
}

int main()
{
    cin >> K;
    
    Operators.resize(K);
    
    for (int i = 0; i < K; i++)
    {
        cin >> Operators[i];
    }
    
    BackTracking("");
    
    cout << MAX << '\n' << MIN;

    return 0;
}