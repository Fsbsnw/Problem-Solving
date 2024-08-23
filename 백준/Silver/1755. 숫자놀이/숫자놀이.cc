#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) 
{
    return a.second < b.second;
}

int main() {
    vector<string> str = 
    {
        "zero", "one", "two", "three",
        "four", "five", "six", "seven",
        "eight", "nine"
    };
    vector<pair<int, string>> v;
    
    int M, N;
    cin >> M >> N;
    for ( int i = M; i <= N; i++ ) 
    {
        string s = "";
        for ( auto c : to_string(i) ) 
        {
            s += str[c - '0'];
            s += " ";
        }
        v.push_back(pair<int, string>(i, s));
    }
    
    sort(v.begin(), v.end(), comp);
    
    for ( int i = 0; i < v.size(); i++ ) 
    {
        cout << v[i].first << " ";
        if ( i % 10 == 9 ) cout << '\n';
    }
}