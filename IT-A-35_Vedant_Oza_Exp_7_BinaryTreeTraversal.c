//IT-A-35_Vedant_Oza
//7.Implementation of Binary Tree and its Traversal for real-world application.
//Note:If you dont have Node for any perticular position for that respective root Node then enter -1
#include <stdio.h>
#include <stdlib.h>
// #include "Queue.h"
// Queue Header File
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}
void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
struct Node *root = NULL;
void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Eneter root value ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}
int main()
{
    Treecreate();
    printf("\nPre Order ");
    Preorder(root);
    printf("\nin Order ");
    Inorder(root);
    printf("\nPost Order ");
    Postorder(root);
    return 0;
}


//I found this Program is not accurate as it is not asking for Left and Right Nodes
// /**************************************************************
//  Implementation of Binary Tree Traversal
// **************************************************************/
// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>
// #include <malloc.h>
// struct node
// {
//     int data;
//     struct node *left;
//     struct node *right;
// };
// struct node *tree;
// void create(struct node *);
// struct node *insert(struct node *, int);
// void inorder(struct node *);
// void preorder(struct node *);
// void postorder(struct node *);
// void main()
// {
//     printf("\n --- WELCOME TO IMPLEMENTATION OF BINARY TREE TRAVERSALS --- \n");
//     int choice, x;
//     struct node *ptr;
//     create(tree);
//     do
//     {
//         printf("\n *** --- opertaions available --- *** ");
//         printf("\n 1. Insert a Node");
//         printf("\n 2. Display Inorder Traversal");
//         printf("\n 3. Display Preorder Traversal");
//         printf("\n 4. Display Postorder Traversal");
//         printf("\n 5. Exit \n");
//         printf(" Please enter your choice : ");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             printf("\n Enter the data to be inserted : ");
//             scanf("%d", &x);
//             tree = insert(tree, x);
//             break;
//         case 2:
//             printf("\n Elements in the inorder traversala are : ");
//             inorder(tree);
//             printf("\n");
//             break;
//         case 3:
//             printf("\n Elements in the preorder traversala are : ");
//             preorder(tree);
//             printf("\n");
//             break;
//         case 4:
//             printf("\n Elements in the postorder traversala are : ");
//             postorder(tree);
//             printf("\n");
//             break;
//         default:
//             printf("\n Please enter a valid option 1, 2, 3, 4.");
//             break;
//         }
//     } while (choice != 5);
// }
// void create(struct node *tree)
// {
//     tree = NULL;
// }
// // Function for inserting a new node
// struct node *insert(struct node *tree, int x)
// {
//     struct node *p, *temp, *root;
//     p = (struct node *)malloc(sizeof(struct node));
//     p->data = x;
//     p->left = NULL;
//     p->right = NULL;
//     if (tree == NULL)
//     {
//         tree = p;
//         tree->left = NULL;
//         tree->right = NULL;
//     }
//     else
//     {
//         root = NULL;
//         temp = tree;
//         while (temp != NULL)
//         {
//             root = temp;
//             if (x < temp->data)
//                 temp = temp->left;
//             else
//                 temp = temp->right;
//         }
//         if (x < root->data)
//             root->left = p;
//         else
//             root->right = p;
//     }
//     return tree;
// }
// // Function for Inorder Traversals
// void inorder(struct node *tree)
// {
//     if (tree != NULL)
//     {
//         inorder(tree->left);
//         printf(" %d \t", tree->data);
//         inorder(tree->right);
//     }
// }
// // Function for Preorder Traversals
// void preorder(struct node *tree)
// {
//     if (tree != NULL)
//     {
//         printf(" %d \t", tree->data);
//         preorder(tree->left);
//         preorder(tree->right);
//     }
// }
// // Function for Postorder Traversals
// void postorder(struct node *tree)
// {
//     if (tree != NULL)
//     {
//         postorder(tree->left);
//         postorder(tree->right);
//         printf(" %d \t", tree->data);
//     }
// }