#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &a,int &n,int value)
{

	n = n + 1;
	a.push_back(value);
	int i = n-1;

	while(i>0)
	{
		int parent = i/2;
		if(a[parent] < a[i])
		{
			swap(a[parent],a[i]);
			i = parent;
		}
		else 
			return;
	} 
}

int delete(vector<int> &a,int &n)
{
	if(n==0) return -1;
	int result = a[0];
	a[0] = a[n-1];
	a.pop_back();
	i = 0;
	while(i < n)
	{
		int c1 = i*2+1;
		int c2 = i*2+2;

		if(a[c1] > a[c2])
		{
			swap(a[i],a[c1]);
			i = c1;
		}
		else if(a[c2] > a[c1])
		{
			swap(a[i],a[c2]);
			i = c2;
		}
		else
		{
			break;
		}
	}

	n = n-1;

	return result;
}

int  main()
{
	int n = 0;
	vector<int> a;

	insert(a,n,1);
	insert(a,n,2);
	insert(a,n,4);
	insert(a,n,3);


	for(auto i : a)
		cout<<i<<endl;
}