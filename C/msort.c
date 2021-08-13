#include <stdio.h>
#include <stdlib.h>
void merge(int *a,int low,int mid,int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid ;
    int k = low;

    int arr1[n1],arr2[n2];

    for(int i=0;i<n1;i++)
        arr1[i]=a[i+low];
    
    for(int i=0;i<n2;i++)
        arr2[i]=a[i+mid+1];
    
    int i=0,j=0;
    while(i<n1  && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            a[k++] = arr1[i++];
        }
        else
        {
            a[k++] = arr2[j++];
        }
    }

    while(i<n1)
    {
        a[k++] = arr1[i++];
    }

    while(j<n2)
    {
        a[k++] = arr2[j++];
    }
}
void mergesort(int *a,int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void main()
{
    int arr[]={9,8,12,221,3,13,13,12,111,9,7,5,3,64,23};
    int n= sizeof(arr)/sizeof(arr[0]);

    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

        
}