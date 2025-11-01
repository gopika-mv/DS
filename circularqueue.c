#include<stdio.h>
#include<stdlib.h>
#define Max 5
int cq[Max];
int f=-1,r=-1;
int c=0;
void enqueue(int value)
{
    if((f==0 && r==Max-1)||(f==r+1))
    {
        printf("Queue overflow");
        return;
    }
    if(f==-1)
    {
        f=r=0;
    }
    else if(r==Max-1 && f!=0)
    {
        r=0;
    }
    else{
        r++;
    }
    cq[r]=value;
    c++;
    printf("%d is inserted",value);
}
void dequeue()
{
  if(f==-1)
  {
    printf("Queue is in underflow");
    return;
  }
  printf("%d is deleted",cq[f]);
  if(f==r)
  {
    f=r=-1;
  }
  else if(f==Max-1)
  {
    f=0;
  }
  else{
    f++;
  }
  c--;
}
void display()
{
 if(f==-1)
 {
    printf("Queue is empty\n");
    return;
 }
 printf("Queue elements:");
 if(r>=f)
 {
    for(int i=f;i<=r;i++)
    {
        printf("%d",cq[i]);
    }
 }
 else
 {
    for(int i=f;i<Max;i++)
    {
        printf("%d",cq[i]);
    }
    for(int i=0;i<=r;i++)
    {
        printf("%d",cq[i]);
    }
 }
}
void count()
{
 printf("Total number of elements:%d\n",c);
}
int main()
{
    int choice,value;
    while(1)
    {
        printf("Circular Queue Menu\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Count\5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                 printf("Enter value:");
                 scanf("%d",&value);
                 enqueue(value);
                 break;
            case 2:
                 dequeue();
                 break;
             case 3:
                 display();
                 break;
             case 4:
                 count();
                 break;
             case 5:
                 printf("Exit\n");
                 exit(0);
             default:
                 printf("Invalid choice");        
        }
    }
    return 0;
}