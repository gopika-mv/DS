#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev,*next;
}Node;
Node *head=NULL;
Node *create(int data)
{
    Node *new=(Node *)malloc(sizeof(Node));
    new->data=data;
    new->prev=new->next=NULL;
    return new;
}
void insert_begin(int data)
{
    Node *new=create(data);
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        new->next=head;
        head->prev=new;
        head=new;
    }
    printf("%d is inserted at beginning",data);
}
