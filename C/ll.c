#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * start;

void display()
{
    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    else
    {
        struct node *temp;
        for (temp = start; temp != NULL; temp = temp->next)
        {
            printf("%d\t", temp->data);
        }
        printf("\n");
    }
}

void insertAtStart(int key)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = start;
    start = temp;
}

void insertAtEnd(int key)
{
    struct node *temp, *cur;
    cur = start;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = temp;
}

void delete (int key)
{
    if (start == NULL)
    {
        printf("Empty List\n");
        return;
    }

    struct node *cur, *prev;

    cur = start;

    if (start->data == key)
    {
        start = start->next;
        free(cur);
        return;
    }

    while (cur != NULL)
    {
        if (cur->data == key)
        {
            prev->next = cur->next;
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void reverse()
{
    if (start == NULL)
        return;
    if (start->next == NULL)
        return;
    struct node *prev, *cur, *ahead;
    prev = NULL;
    cur = start;
    ahead = start->next;
    while (ahead != NULL)
    {
        cur->next = prev;
        prev = cur;
        cur = ahead;
        ahead = ahead->next;
    }
    cur->next = prev;
    start = cur;
}

void findmiddle()
{
    if (start == NULL)
    {
        printf("Empty\n");
        return;
    }

    if (start->next == NULL)
    {
        printf("Middle Element = %d\n", start->data);
        return;
    }

    struct node *s, *f;

    s = start;
    f = start;

    while (f != NULL && f->next != NULL)
    {
        s = s->next;
        f = f->next->next;
    }

    printf("Middle Element = %d\n", s->data);
}

struct node *reverse2(struct node *head, int k)
{
    struct node *prev, *cur, *ahead;
    
    prev = NULL, cur = head, ahead = head->next;
    int i = k-1;

    while (i-- && ahead != NULL)
    {
        cur->next = prev;
        prev = cur;
        cur = ahead;
        ahead = ahead->next;
    }
    cur->next = prev;
    
    if(ahead!=NULL){
    head->next = reverse2(ahead,k);
    }

    
    
    return cur;
}
int main()
{

    display();
    insertAtStart(3);
    insertAtStart(2);
    insertAtStart(1);
    insertAtStart(6);

    insertAtStart(5);
    insertAtStart(4);
    display();
    start = reverse2(start, 2);
    display();

    return 0;
}