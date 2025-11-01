#include<stdio.h>
#define max 5
int a[max],top=-1;
void push(int x)
{
   if(top>=max-1)
   {
    printf("Stack overflow");
   }
   else
   {
    top++;
    a[top]=x;
    printf("%d is pushed into the stack\n",x);
   }
}
void pop()
{
    if(top<=0)
    {
        printf("Stack is in underflow condition");
    }
    else
    {
        printf("%d is popped from the stack\n",a[top]);
        top--;
    }
}
void peek()
{
    if(top<=0)
    {
        printf("stack is in underflow condition");
    }
    else if(top>=max-1)
    {
        printf("Stack is in overflow condition");
    }
    else
    {
        printf("Top element:%d\t",a[top]);
    }
}
void traverse()
{
    int i;
    if(top<=0)
    {
        printf("Stack is in underflow");
    }
    else if(top>=max-1)
    {
        printf("Stack overflow");
    }
    else
    {
        printf("Stack elements\n");
        for(i=0;i<=top;i++)
        {
        printf("%d\t",a[i]);
        }
    }
}
void main(){
    int c=1,ch,x;
    while(c)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Traverse\n5.exit");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the value to push:");
                  scanf("%d",&x);
                  push(x);
                  break;
            case 2:pop();
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