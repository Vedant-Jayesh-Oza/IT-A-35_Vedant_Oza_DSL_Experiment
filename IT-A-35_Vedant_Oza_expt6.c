

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} * head, *temp, *temp1, *temp2;

void insert_beg();
void insert_end();
void insert_mid();
void delete ();
void display_forward();
void display_backward(int i);

int count = 0;

void main()
{
    int choice, insert_option, print_option;
    printf("Welcome to the implementation of the singly linked list ! \n");
    do
    {
        printf("\n Please select an operation to perform from the below list \n");
        printf(" 1. Insert a node \n 2. Delete a node \n 3. Print the existing list \n 4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n \n");
        switch (choice)
        {
        case 1:
            do
            {
                printf("Select a position where you to want to insert new node \n");
                printf(" 1. Beginning of the List \n 2. At the end of the list \n 3. Insert in between \n 4. Exit the insert operation \n");
                printf("Enter your choice: ");
                scanf("%d", &insert_option);
                switch (insert_option)
                {
                case 1:
                    insert_beg();
                    break;
                case 2:
                    insert_end();
                    break;
                case 3:
                    insert_mid();
                    break;
                case 4:
                    printf("Insert operation Exit");
                    break;
                default:
                    printf("Please enter a valid choide: 1, 2, 3, 4");
                }
            } while (insert_option != 4);
            printf("\n \n");
            break;
        case 2:
            delete ();
            break;
        case 3:
            do
            {
                printf(" --Display Option Menu-- \n");
                printf(" 1. Print List in Forward Direction \t2. Print List in Backward Direction \t3. Exit \n");
                printf(" Enter your choice: ");
                scanf("%d", &print_option);
                switch (print_option)
                {
                case 1:
                    display_forward();
                    printf("\n \n");
                    break;
                case 2:
                    temp2 = head;
                    if (temp2 == NULL)
                        printf(" Error : List empty to display \n");
                    else
                    {
                        printf(" Linked list elements in backward direction : ");
                        display_backward(temp2->data);
                    }
                    printf("\n \n");
                    break;
                case 3:
                    printf(" Print Operation Exit !! \n");
                    break;
                default:
                    printf(" Please enter a valid option: 1, 2, 3 \n");
                    break;
                }
            } while (print_option != 3);
            break;
        case 4:
            printf("Exit: Program Finished !!");
            break;
        default:
            printf("Please enter a valid choide: 1, 2, 3, 4, 5");
        }
    } while (choice != 4);
}

// Function to create new empty node
void create()
{
    int x;
    temp = (struct node *)malloc(1 * sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("Enter the data to be inserted: ");
    scanf("%d", &x);
    printf("\n");
    temp->data = x;
    count++;
}

// Function to insert element
void insert_beg()
{
    if (head == NULL)
    {
        create();
        head = temp;
        temp1 = head;
    }
    else
    {
        create();
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insert_end()
{
    if (head == NULL)
    {
        create();
        head = temp;
        temp1 = head;
    }
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}
void insert_mid()
{
    int pos, i = 2;

    printf(" Enter position of the element to be inserted : ");
    scanf("%d", &pos);
    temp2 = head;

    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Position out of range to insert");
        return;
    }
    if ((head == NULL) && (pos != 1))
    {
        printf("\n Empty list cannot insert other than 1st position");
        return;
    }
    if ((head == NULL) && (pos == 1))
    {
        create();
        head = temp;
        temp1 = head;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create();
        temp->prev = temp2;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        temp2->next = temp;
    }
}

// Function to delete element
void delete ()
{
    int i = 1, pos;

    printf("\n Enter position of the element to be deleted : ");
    scanf("%d", &pos);
    temp2 = head;

    if ((pos < 1) || (pos >= count + 1))
    {
        printf(" Error : Position out of range to delete \n");
        return;
    }
    if (head == NULL)
    {
        printf(" Error : Empty list no elements to delete \n");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        if (i == 1)
        {
            if (temp2->next == NULL)
            {
                printf(" Node deleted from list \n");
                free(temp2);
                temp2 = head = NULL;
                return;
            }
        }
        if (temp2->next == NULL)
        {
            temp2->prev->next = NULL;
            free(temp2);
            printf(" Node deleted from list \n");
            return;
        }
        temp2->next->prev = temp2->prev;
        if (i != 1)
            temp2->prev->next = temp2->next;
        if (i == 1)
            head = temp2->next;
        printf(" Node deleted \n");
        free(temp2);
    }
    count--;
}

// Function to display elements
void display_forward()
{
    temp2 = head;

    if (temp2 == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf(" Linked list elements in forward direction : ");

    while (temp2->next != NULL)
    {
        printf(" %d ", temp2->data);
        temp2 = temp2->next;
    }
    printf(" %d ", temp2->data);
}
void display_backward(int i)
{
    if (temp2 != NULL)
    {
        i = temp2->data;
        temp2 = temp2->next;
        display_backward(i);
        printf(" %d ", i);
    }
}
