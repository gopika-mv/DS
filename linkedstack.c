#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
Node *top=NULL;
void push(int data)
{
    Node *new=(Node *)malloc (sizeof(Node));
    if(!new)
    {
        printf("Stack Overflow");
        return;
    }
    new->data=data;
    new->next=top;
    top=new;
    printf("%d is pushed onto the stack",&data);
}
void pop()
{
    if(top==NULL)
    {
        printf("Stack underflow");
        return;
    }
    Node *temp=top;
    printf("%d is popped from the stack",temp->data);
    top=top->next;
    free(temp);
}
void display()
{
    if(top==NULL)
    {
        printf("Stack underflow");
        return;
    }
    Node *temp=top;
    printf("Stack elements:");
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void count()
{
    int c=0;
    Node *temp=top;
    while(temp)
    {
        c++;
        temp=temp->next;
    }
    printf("Total elements:%d",c);
}
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack using Singly Linked List ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Count\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                count();
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
