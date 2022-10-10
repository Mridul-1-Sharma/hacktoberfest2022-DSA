#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }

        swap(&arr[min], &arr[i]);
    }
}

void display(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("\nEnter size: ");
    scanf("%d",&size);
    int arr[size];
    printf("\nEnter array: ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nUnsorted Array: ");
    display(arr,size);
    selectionSort(arr,size);
    display(arr,size);

    return 0;
}
