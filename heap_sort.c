#include<stdio.h>

void printarray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void heapsort(int arr[],int n)
{
    int i;
    for(i=((n/2)-1);i>=0;i--)
    {
        heapify(arr,n,i);
    }

    int j;
    for(j=n-1;j>=0;j--)
    {
        int temp=arr[j];
        arr[j]=arr[0];
        arr[0]=temp;
        heapify(arr,j,0);
    }

}


void heapify(int arr[],int n,int root)
{
    int largest=root;
    int left=2*root+1;
    int right=2*root+2;

    if(left<n && arr[left]>arr[largest])
        largest=left;

    if(right<n && arr[right]>arr[largest])
        largest=right;

    if(largest!=root)
    {
        int temp=arr[root];
        arr[root]=arr[largest];
        arr[largest]=temp;
        heapify(arr,n,largest);
    }
}

int main()
{
    int arr[10],n,i;
    printf("Enter the number of elements in array:");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    heapsort(arr,n);
    printf("The sorted array is:\n");
 //   int arr[]={1,12,9,5,6,1,10};

 //   printf("Array before sorting:\n");
 //   printarray(arr,n);

 //   heapsort(arr,n);

  //  printf("\nSorted array is:\n");
      printarray(arr,n);
  //  return 0;
}
