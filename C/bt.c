#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild, *rchild;
};

struct node *insert(struct node *root, int n)
{
    if (root == NULL)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = n;
        newnode->lchild = newnode->rchild = NULL;
        return newnode;
    }

    if (n < root->data)
        root->lchild = insert(root->lchild, n);
                                                                                                                
    else if(n > root->data)
        root->rchild = insert(root->rchild, n);
    
    return root;
}

struct node* findmin(struct node *root)
{
    struct node * temp;
    while(temp && temp->lchild != NULL)
        temp = temp->lchild;
    return temp;
}

struct node* find(struct node *root,int n)
{
    if(root==NULL || root->data == n)
    {
        return root;
    }

    if(n < root->data)
        return find(root->lchild,n);
    
    return find(root->rchild,n);
    

}
  

struct node* delete(struct node *root,int n)
{
    //base case
    if(root==NULL)
        return NULL;

    //check in left sub-tree
    if(n < root->data)
        root->lchild = delete(root->lchild,n);
    
    //check in right sub-tree
    else if(n > root->data)
        root->rchild = delete(root->rchild,n);
    
    //found
    else{

        //delete if node has 1 child or 0 child
        if(root->lchild == NULL)
        {
            struct node *temp = root->rchild;
            free(root);
            return temp;
        }
        else if(root->rchild == NULL)
        {
            struct node *temp = root->lchild;
            free(root);
            return temp;
        }

        //delete if node has two children  
        struct node* temp = findmin(root->rchild);

        //copy data of inordersuccessor
        root->data = temp->data;

        //delete inordersuccessor
        root->rchild = delete(root->rchild,temp->data);
    }

    return root;

    
    
}

struct node *create()
{
    struct node *newnode;
    int x;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value (-1 for no node) : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    newnode->data = x;
    printf("Enter left child of %d\n", x);
    newnode->lchild = create();
    printf("Enter right child of %d\n", x);
    newnode->rchild = create();

    return newnode;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%d\t", root->data);
        inorder(root->rchild);
    }
}

void main()
{
    struct node *root = NULL;

    root = create();

    inorder(root);

    // root = insert(root, 90);
    insert(root, 130);
    insert(root, 92);

    printf("\n");
    inorder(root);

    delete(root,130);
    printf("\n");
    inorder(root);
    struct node *temp = find(root,92);
    printf("Found = %d",(temp==NULL)?0:temp->data);
}