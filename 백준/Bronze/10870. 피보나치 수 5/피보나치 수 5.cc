#include <iostream>

using namespace std;

int Fibonacci(int Num)
{
    if (Num == 0) 
    {
        return 0;
    }
    if (Num == 1 || Num == 2)
    {
        return 1;
    }
    return Fibonacci(Num - 2) + Fibonacci(Num - 1);
}

int main()
{
    int n; cin >> n;
    cout << Fibonacci(n);
    
    return 0;
}