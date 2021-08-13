#include <stdio.h>
#include <stdlib.h>

int partition(int *a,int low,int high)
{
    int pivot = a[low];
    int i = low+1;
    int j = high;

    while(i<j)
    {
        while(a[i]<=pivot)
            i++;
        
        while(a[j]>pivot)
            j--;
            
        if(i<j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}
void quicksort(int *a , int low,int high)
{
    if(low<high)
    { 
        int p = partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}


void main()
{
    int arr[]={9,8,12,221,3,13,13,12,111,9,7,5,3,64,23};
    int n= sizeof(arr)/sizeof(arr[0]);

    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

        
}

