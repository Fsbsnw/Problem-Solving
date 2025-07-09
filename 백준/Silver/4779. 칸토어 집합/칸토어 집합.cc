#include <iostream>
#include <cmath>

using namespace std;

void DivideIntoThree(string Str)
{
    if (Str.size() == 1) 
    {
        cout << '-';
        return;
    }
    int PartitionSize = Str.size() / 3;
    
    DivideIntoThree(Str.substr(0, PartitionSize));
    cout << string(PartitionSize, ' ');
    DivideIntoThree(Str.substr(2 * PartitionSize, PartitionSize));
}

int main()
{
    int n;
    while (cin >> n)
    {
        int Length = pow(3, n);
        string Str(Length, '-');
        DivideIntoThree(Str);
        cout << '\n';
    }
    
    return 0;
}