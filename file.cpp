#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int majority(int input1,int input2[])
{
    unordered_map<int,int> mp;
    for(int i = 0;i<input1;i++)
        mp[input2[i]]++;
    for(auto i : mp)
    {
        if(i.second > input1/2)
            return i.first;
    }

    return -1;
}

int main()
{
    
}
