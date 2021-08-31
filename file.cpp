#include <iostream>
#include <bits/stdc++.h>
#include "time.cpp"
using namespace std;


bool check(string s,string t)
{
    unordered_map<char,int> mp;
    for(char i : s)
    {
        mp[i]++;
    }

    for(char i : t)
    {
        mp[i]++;
    }

    for(auto i : mp)
    {
        if(i.second % 2 !=0)
            return false;
    }

    return true;

}

int main()
{
    TIMESTART
    
    int t;
    cin>>t;
    while(t--)
    {
        string s , t;
        cin>>s;
        cin>>t;
        if(check(s,t))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    TIMEEND
    return 0;
}
