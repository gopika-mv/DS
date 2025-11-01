#include<stdio.h>
#include<stdlib.h>
//Node structure
typedef struct node
{
    int data;
    struct node *next;
}Node;
Node *create(int data)
{
    Node *new=(Node *)malloc(sizeof(Node));
    new->data=data;
    new->next=NULL;
    return new;
}
void insert(Node **head,int data,int pos)
{
    Node *new=create(data);
    if(pos==0 || *head==NULL)
    {
        new->next=*head;
        *head=new;
        return;
    }
    Node *temp=*head;
    for(int i=0;i<pos-1 && temp->next!=NULL;i++)
    {
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
}
void delete(Node **head,int pos)
{
if(*head==NULL)
{
    printf("List is empty\n");
    return;
}
if(pos==0)
{
    Node *temp=*head;
    *head=temp->next;
    free(temp);
    return;
}
Node *temp=*head;
for(int i=0;i<pos-1 && temp->next!=NULL;i++)
{
    temp=temp->next;
}
if(temp->next==NULL)
{
    printf("Position is out of range\n");
    return;
}
Node *del=temp->next;

temp->next=del->next;
free(del);
}
void display(Node *head)
{
Node *temp=head;
while(temp!=NULL)
{
    printf("%d",temp->data);
    temp=temp->next;
}
printf("\n");
}
void count(Node *head)
{
    int c=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    printf("Total nodes:%d",c);
}
int main() {
    Node *head=NULL;
    int choice,data,pos;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1.Insert");
        printf("2. Delete\n");
        printf("3. Traverse\n4. Count Nodes\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
              printf("Enter value: "); 
              scanf("%d", &data);
              printf("Enter position:");
              scanf("%d",&pos); 
              insert(&head,data,pos); 
              break;
        case 2:
              printf("Enter position: "); 
              scanf("%d", &pos); 
              delete(&head,pos); 
              break;
        case 3:
              printf("Linked List:");
              display(head); 
              break;
        case 4:
              count(head);
              break;
        case 5:exit(0);
        default: printf("Invalid choice!\n");
        }
    }
    return 0;
}