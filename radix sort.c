#include<stdio.h>

int count_digits(int num)
{
int digit;
while(num>0)
{
digit++;
num/=10;
}
return digit;
}
int largest(int arr[],int n)
{
    int i,large=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>large)
            large=arr[i];
    }
    return large;
}
int radix_sort(int arr[],int n)
{
    int bucket[10][5],count_per_bucket[10];
    int i,j,k,large,NOP,pass,divisor=1,remainder;
    large=largest(arr,n);
    NOP=count_digits(large);

    for(pass=0;pass<NOP;pass++)
    {
        for(i=0;i<10;i++)
        {
            count_per_bucket[i]=0;
        }

        for(i=0;i<n;i++)
        {
            remainder=(arr[i]/divisor)%10;
            bucket[remainder][count_per_bucket[remainder]]=arr[i];
            count_per_bucket[remainder] += 1;
        }
        i=0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<count_per_bucket[k];j++)
            {
                arr[i]=bucket[k][j];
                i++;
            }
        }
        divisor*=10;
    }
    return arr;
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
    radix_sort(arr,n);
    printf("The sorted array is:\n");
     for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
