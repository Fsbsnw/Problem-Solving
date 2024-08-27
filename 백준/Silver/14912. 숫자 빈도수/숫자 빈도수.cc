#include <iostream>

using namespace std;

int n, d;
int frequency[10];

int main()
{
    cin >> n >> d;
    
    for (int i = 1; i <= n; i++)
    {
       string STR = to_string(i);
       
       for (int j = 0; j < STR.size(); j++)
       {
           frequency[STR[j] - '0']++;
       }
       
    }

   cout << frequency[d] << ' ';
   
    return 0;
}