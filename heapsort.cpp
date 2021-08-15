#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a,int n,int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	while(l<n && a[l] > a[largest])
	{
		largest = l;
	}

	while(r<n && a[r] > a[largest])
	{
		largest = r;
	}

	if(largest!=i)
	{
		swap(a[i],a[largest]);
		heapify(a,n,largest);
	}

}

void heapsort(vector<int> &a,int n)
{
	for(int i = n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(int i = n-1;i>=0;i--)
	{
		swap(a[i],a[0]);
		heapify(a,i,0);
	}
}

int  main()
{

	
	vector<int> a = {90,12,34,12,2,12,3,1,21,232,3,1,212,1,11,111,31,1,123,4,1,11};
	int n = a.size();

	heapsort(a,n);

	for(int i:a)
		cout<<i<<"   ";



}