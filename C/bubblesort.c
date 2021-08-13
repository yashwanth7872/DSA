#include <stdio.h>
#include <stdlib.h>


void bubblesort(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        int swap = 0;
        for(int j=0;j<n-i;j++)
            {
                if(a[j] > a[j+1])
                {
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    swap = 1;
                }
            }

        if(swap == 0)
            break;
    }
}

void insertionsort(int *a,int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
            {
                if(a[j] < a[j-1])
                {
                    int temp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = temp;
                }
            }
    }
}

void selectionsort(int *a,int n)
{

    int min_index,temp;
    
    for(int i=0;i<n;i++){
        int min = a[i];
        for(int j=i;j<n;j++)
        {
            if(a[j] < min)
            {
                min = a[j];
                min_index = j;
            }
        }

        temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
            
    }
}
void main()
{
    int arr[]={9,8,12,221,3,13,13,12,111,9,7,5,3,64,23};
    int n= sizeof(arr)/sizeof(arr[0]);

    selectionsort(arr,n);

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

        
}

