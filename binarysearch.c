#include<stdio.h>
int main()
{
    int a[20],n,i,beg,end,mid,item,found=1;
    printf("No of elements:");
    scanf("%d",&n);
    printf("Elements in sorted order:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("Enter the element to search:");
    scanf("%d",&item);
    beg=0,end=n-1;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(a[mid]==item)
        {
            printf("%d is found in %d",a[mid],mid+1);
            found=1;
            break;
        }
        else if(item<a[mid])
        {
            end=mid-1;
        }
        else
        {
            beg=mid+1;
        }
    }
    if(found==0)
    {
        printf("Element is not found");
    }
    return 0;
}