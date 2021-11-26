//IT-A-35_Vedant_Oza
//1.Implementation of Stack using Array for real-world application.
#include <stdio.h>
#include <stdlib.h>
int *STK;
int TOP = -1, i, n, x, choice; //Initializing Top pointer at -1 i.e before start point
void Push();                   //insert or add
void Pop();                    //remove from top
void Peep();                   //Check value at position from top
void change();                 //change valu of position x from top
void Display();                //display stack elements
void main()
{
    printf("\t WELCOME to Implementation of STACK using array !! \n");
    printf("Enter the size of Stack: ");
    scanf("%d", &n);
    STK = (int *)malloc(n * sizeof(int));
    do
    {
        printf("\n Stack Operation available: \n");
        printf("\t1.Push\t 2.Pop\t 3.Peep\t 4.Change\t 5.Display\t 6.Exit \n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peep();
            break;
        case 4:
            change();
            break;
        case 5:
            Display();
            break;
        case 6:
            printf("Exit: Program Finished !! ");
            break;
        default:
            printf("Please enter a valid choice: 1, 2, 3, 4, 5 \n");
        }
    } while (choice != 6); //at choice=6 i.e. exit ....close the program execution
}
// Function to perform PUSH Operation
void Push()
{
    if (TOP >= n - 1) //we insert from TOP by incrementing TOP pointer and n is size of our Stackso if TOP >= size then its OverFlow
    {
        printf(" Stack Overflow \n");
    }
    else
    {
        printf(" Enter the element to be pushed: ");
        scanf("%d", &x);
        TOP++;        //inc TOP
        STK[TOP] = x; //Add the element
    }
}
// Function to perform POP Operation
void Pop()
{
    if (TOP < 0) //i.e. No element in STACK
    {
        printf(" Stack Underflow \n");
    }
    else
    {
        printf(" The popped element is: %d \n", STK[TOP]); //Remove element from stack
        TOP--;                                             //dec TOP pointer
    }
}
// Function to perform PEEP Opeartion
void Peep()
{
    printf(" Enter the position of the element from the top which you want to peep: ");
    scanf("%d", &i);
    //lets take eg our stack contains elements 9,6,5 so TOP is at 3rd position i.e. 5 and we have to check 2nd element from Top i.e.6
    //if (TOP - i + 1) here i=2 since 2nd element from top,so TOP-i+1=3-2+1=2nd position =6
    //if we dont write +1 then it will access 1 element below i.e. 9
    if (TOP - i + 1 < 0) //in our eg 3-2+1=2 if >0 but is top=1 and we have to acces 2nd element then 1-2+1=0 or 3rd element then 1-3+1=-1 ie <0
    {
        printf(" Stack Underflow on Peep \n");
    }
    else
    {
        printf(" The %d element from the top is: %d \n", i, STK[TOP - i + 1]);
    }
}
// Function to perform changee Opeartion
void change()
{
    printf(" Enter the position of the element from the top which you want to Change: ");
    scanf("%d", &i);
    int new;
    printf("Enter new value:");
    scanf("%d", &new);
    if (TOP - i + 1 < 0) //same as we do for peep
    {
        printf(" Stack Underflow on Change \n");
    }
    else
    {
        printf(" The old %d element from the top was: %d \n", i, STK[TOP - i + 1]);
        STK[TOP - i + 1] = new; //here we change the old element with new one
        printf(" The new %d element from the top is: %d \n", i, STK[TOP - i + 1]);
    }
}
// Function to DISPLAY the Stack
void Display()
{
    if (TOP < 0) //no element in Stack
    {
        printf(" Stack is empty \n");
    }
    else
    {
        printf(" The element in the stack are:");
        for (i = TOP; i > -1; i--) //from TOP to end ie 0 position
        {
            printf("\n %d \n", STK[i]); //print elements
        }
    }
}
