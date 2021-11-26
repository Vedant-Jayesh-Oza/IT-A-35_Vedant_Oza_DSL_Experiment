//IT-A-35_Vedant_Oza
//2.Implementation of Queue using Array for real-world application.
#include <stdio.h>            //Header file
#include <conio.h>            //Header file
void insert(void);            //function declaration
void delete (void);           //function declaration
void display(void);           //function declaration
int queue[100], n, choice, i; //Global variable declaration
int front = -1;               //Global variable declaration
int rear = -1;                //Global variable declaration
int main()                    //main function
{
    printf("\n Enter the Size of Queue less than 100: ");
    scanf("%d", &n); //get size of queue
    do
    {
        printf("Enter Your Choice \n 1.Insert \n 2.Delete \n 3.Display \n 4.Exit\n");
        scanf("%d", &choice); //get choice
        switch (choice)       //switch case
        {
        case 1:
            insert(); //function calling
            break;
        case 2:
            delete (); //function calling
            break;
        case 3:
            display(); //function calling
            break;
        case 4:
            printf("Exit"); //Exit
            break;
        default:
            printf("Invalid choice"); //defoult statement
        }
    } while (choice != 4);
}
void insert() //function defination
{
    int num;
    //we insert from rear end by incrementing rear pointer and n is size of our queue so if rear >= size then its OverFlow
    if (rear >= n - 1)
        printf("Queue is Overflow \n");
    else
    {
        if (front == -1) //initially
            front = 0;   //increment it and make it 1
        printf("enter the element to insert\n");
        scanf("%d", &num);
        rear = rear + 1;   //increment rear pointer
        queue[rear] = num; //Enter element
    }
}
void delete () //function defination
{              //if f==-1 means no data in queue and if f>r then no element and queue is empty since f deletes the element
    if (front == -1 || front > rear)
    {
        printf("Queue is Underflow \n");
    }
    else
    {
        printf("Element deleted from Queue is : %d\n", queue[front]);
        front = front + 1; //inc front pointer
    }
}
void display() //function defination
{
    if (front == -1) //Queue is empty
        printf("Queue is empty \n");
    else
    {
        for (i = front; i <= rear; i++) //from front till rear pointer
            printf("%d ", queue[i]);    //display Queue
        printf("\n");
    }
}
