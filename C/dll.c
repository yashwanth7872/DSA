#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

//functions to manipulate DLL
void insertAtBeg(int);
void insertAtEnd(int);
void insertAtPos(int, int);
void deleteAtBeg();
void deleteAtEnd();
void deleteAtPos();
void reverse();
void middle();
int count();
void display();

struct node *head = NULL;

void deleteAtBeg()
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }

    struct node *temp = head;
    printf("%d is deleted\n", head->data);
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
}

void deleteAtEnd()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("%d is deleted\n", temp->data);
    if (head->next == NULL)
        head = NULL;
    else
        temp->prev->next = NULL;
    free(temp);
}

void deleteAtPos(int pos)
{
    if (pos > count() || pos < 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1)
    {
        deleteAtBeg();
        return;
    }
    if (pos == count())
    {
        deleteAtEnd();
        return;
    }
    int i = 1;
    struct node *temp = head;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    printf("%d is deleted\n", temp->data);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void insertAtEnd(int num)
{
    struct node *temp, *newnode;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}

void insertAtBeg(int num)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertAtPos(int pos, int num)
{
    if (pos > count() + 1 || pos < 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1)
    {
        insertAtBeg(num);
        return;
    }

    if (pos == count() + 1)
    {
        insertAtEnd(num);
        return;
    }

    struct node *temp, *newnode;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    newnode->prev = NULL;
    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
}

int count()
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    temp = head;
    printf("Normal Order  :\t");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    //Back Traverse
    printf("Reverse Order :\t");
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->prev;
    }
    printf("\n\n");
}

void reverse()
{
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }

    if(head->next==NULL)
    {
        return;
    }

    struct node *cur,*nextnode;
    cur = head;
    while(cur->next!=NULL)
    {
        nextnode = cur->next;
        cur->next = cur->prev;
        cur->prev = nextnode;
        cur = nextnode;
    }

    nextnode = cur->next;
    cur->next = cur->prev;
    cur->prev = nextnode;
    head = cur;
}

void middle()
{
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }

    struct node *s=head,*f=head;
    while(f!=NULL && f->next!=NULL)
    {
        s=s->next;
        f=f->next->next;
    }

    printf("Middle Element : %d\n",s->data);
}

void main()
{
    insertAtBeg(13);
    display();
    middle();
    insertAtEnd(15);
    display();
    middle();
    printf("Count = %d\n",count());
}
