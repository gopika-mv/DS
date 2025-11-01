#include<stdio.h>
#define max 10
int q[max];
int r=-1,f =-1;
void enqueue(int x)
{
    if(r>=max-1)
    {
        printf("Queue overflow");
    }
    else
    {
        if(f==-1)
        {
            f=0;
        }
        ++r;
        q[r]=x;
        printf("Enqueued %d in the queue",x);
    }
}
void dequeue()
{
    if(f==-1 || f>r)
    {
        printf("Queue is in underflow condition");
    }
    else
    {
        printf("Dequeued %d from the queue",q[f]);
        f++;
    }
}
void peek()
{
    if(r>=max-1)
    {
        printf("Queue is overflow");
    }
    else if(f==-1||f>r)
    {
        printf("Queue is underflow");
    }
    else
    {
        printf("Front element:%d",q[f]);
    }
}
void traverse()
{
    int i;
    if(r>=max-1)
    {
        printf("Queue overflow");
    }
    else if(f==-1||f>r)
    {
        printf("Queue underflow");
    }
    else
    {
        printf("Queue elements:");
        for(i=f;i<=r;i++)
        {
            printf("%d\t",q[i]);
        }
    }
}
void main(){
    int c=1,ch,x;
    while(c)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Traverse\n5.exit");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the value to push:");
                  scanf("%d",&x);
                  enqueue(x);
                  break;
            case 2:dequeue();
                   break;
            case 3:peek();
                   break;
            case 4:traverse();
                   break;
            case 5:printf("Exit");
                   return;
            default:
                   printf("Invalid choice");
  

        }
    }
}