#include<stdio.h>
int main()
{
    int a[20],i,n,e,pos;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array:");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("Enter the element to insert:");
    scanf("%d",&e);
    printf("Enter the position to insert:");
    scanf("%d",&pos);
    for(i=n;i>=pos-1;i--)
    {
        a[i]=a[i-1];
    }
    a[pos-1]=e;
    n++;
    printf("Updated array:");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("Enter the position to delete:");
    scanf("%d",&pos);
    for(i=pos-1;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    n--;
    printf("After deletion");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}