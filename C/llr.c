#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};


struct node* create()
{
    struct node* temp;
    int x;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data (-1 for exit):");
    scanf("%d",&x);
    if(x == -1)
    {
        return NULL;
    }

    temp->data = x;
    temp->next = create();

    return temp;
}

void display(struct node* head)
{
    if(head == NULL)
    {
        printf("\n");
        return;
    }
    
    printf("%d \t",head->data);
    display(head->next);
}

struct node* reverse(struct node * head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    struct node * rev = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rev;
}
void main()
{
    struct node* head;
    head = create();
    display(head);
    head = reverse(head);
    display(head);
}