  #include<stdio.h>
  int main()
  {
    int a[20],i,n,item,found=0;
    printf("No of elements:");
    scanf("%d",&n);
    printf("Elements:");
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
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            printf("%d is found in %d",item,i);
            found=1;
            break;
        }
    }
    if(found==0)
    {
      printf("Element is not found");
    }
    return 0;
  }