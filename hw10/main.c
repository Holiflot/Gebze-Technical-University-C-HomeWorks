#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACK_BLOCK_SIZE 10

typedef struct stack
{
    int *array;
    int currentsize;
    int maxsize;
} stack;
/*create stack and stack array of given capacity */
stack * init_return()
{
    struct stack* stack =(struct stack*) malloc(sizeof(struct stack));
    stack -> array = NULL;
    return stack;
}
int init(stack * s)
{
    s -> array = (int*) malloc( STACK_BLOCK_SIZE * sizeof(int));
    s -> currentsize = -1;
    if(s -> array != NULL)
    {
        return 1;        
    }
    else
    {
        return 0;
    }
}
/*check stack empty or not, if empty return 0 */
int isEmpty(struct stack* stack)
{
    if((stack->currentsize == -1))
    {
        return 0;        
    }
    else
    {
        return 1;
    }
}
/*add an item to stack numbers*/
void push(struct stack *s, int d)
{
    s -> array[++s -> currentsize] = d;
}
/*remove an number in stack*/
int pop(struct stack* s)
{
    if (isEmpty(s)==0)//if array is empty it return 0
    {
        return 0;
    }
    else
    {
        return s -> array[s -> currentsize--];   
    }
}
void moveSmallest(stack *pol1,stack *pol2,char k,char l)/*just for smallest number so 1. take it Pool 1 and put pool 2*/
{
        int smallest=pop(pol1);
        push(pol2,smallest);
        printf("Move the disk %d from '%c' to '%c'\n",smallest,k,l);//print the result
}
void moveLegal(stack *pol1,stack *pol2,char k,char l)/*for other numbers.*/
{
    int disk1=pop(pol1);
    int disk2=pop(pol2);
    if (disk1 ==0 )/*if pol1 is empty add disk2 pol1*/
    {
        push(pol1, disk2);
        printf("Move the disk %d from '%c' to '%c'\n",disk2,l,k);
    }
    else if (disk2 == 0)/*if pol2 is empty add disk1 pol2*/
    {
        push(pol2, disk1);
        printf("Move the disk %d from '%c' to '%c'\n",disk1,k,l);
    }
    else if(disk2<disk1)/*if disk2 number smaller than disk1 number, both of them put pol1*/
    {
        push(pol1, disk1);
        push(pol1, disk2);
        printf("Move the disk %d from '%c' to '%c'\n",disk2,l,k);
    }
    else /*if disk1 number smaller than disk2 number, both of them put pol2*/
    {
        push(pol2, disk2);
        push(pol2, disk1);
        printf("Move the disk %d from '%c' to '%c'\n",disk1,k,l);
    }
}
int main()
{
    int number, i,j;
    printf("Please enter a number greater than 3\n");
    scanf("%d", &number);// take the number
    int n = pow(2, number);
    stack *A = init_return();//creat A stack
    A->maxsize=number;// i created the size here because when i send it to the function i can only make 10 
    j=init(A);
    stack *B =init_return();//creat B stack
    B->maxsize=number;
    j=init(B);
    stack *C =init_return();//creat C stack
    C->maxsize=number;
    j=init(C);
    if(number>10)//if number bigger than ten , memory occupied is increaased for each bar.
    {//Can be made up to 20 ,can be increased if desired.
        int o=2;
        A -> array = (int*) realloc(A -> array, o*STACK_BLOCK_SIZE * sizeof(int));
        B -> array = (int*) realloc(B -> array, o*STACK_BLOCK_SIZE * sizeof(int));
        C -> array = (int*) realloc(C -> array ,o*STACK_BLOCK_SIZE * sizeof(int));
    }
    for (i = number; i > 0; i--)
    {
        push(A, i);
    }
    printf("\n");
    char a='1';//for stacks
    char b='2';
    char c='3';
    int movement=0;//number of moves
        if(number%2==0)//even numbers algorithm
        {
            for(i=0;i<(n-1)/6;i++)
            {
                moveSmallest(A,B,a,b);
                movement++;
                moveLegal(A,C,a,c);
                movement++;
                moveSmallest(B,C,b,c);
                movement++;
                moveLegal(A,B,a,b);
                movement++;
                moveSmallest(C,A,c,a);
                movement++;
                moveLegal(B,C,b,c);
                movement++;
               
            }
            if((n-1)%6==1)
            {
                moveSmallest(A,B,a,b);
                movement++;
            }
            else if((n-1)%6==2)
            {
                moveSmallest(A,B,a,b);
                movement++;
                moveLegal(A,C,a,c);
                movement++;
            }
            else if((n-1)%6==3)
            {
                moveSmallest(A,B,a,b);
                movement++;
                moveLegal(A,C,a,c);
                movement++;
                moveSmallest(B,C,b,c);
                movement++;
            }
            else if((n-1)%6==4)
            {
                 moveSmallest(A,B,a,b);
                movement++;
                moveLegal(A,C,a,c);
                movement++;
                moveSmallest(B,C,b,c);
                movement++;
                moveLegal(A,B,a,b);
                movement++;
            }
            else if((n-1)%6==5)
            {
                moveSmallest(A,B,a,b);
                movement++;
                moveLegal(A,C,a,c);
                movement++;
                moveSmallest(B,C,b,c);
                movement++;
                moveLegal(A,B,a,b);
                movement++;
                moveSmallest(C,A,c,a);
                movement++;
            }
            else 
            {
                printf("game is running");
            }
        }
        else //even numbers algorithm
        {
            for(i=0;i<(n-1)/6;i++)
            {
            moveSmallest(A,C,a,c);
            movement++;
            moveLegal(A,B,a,b);
            movement++;
            moveSmallest(C,B,c,b);
            movement++;
            moveLegal(A,C,a,c);
            movement++;          
            moveSmallest(B,A,b,a);
            movement++;
            moveLegal(C,B,c,b);
            movement++; 
            }
            if((n-1)%6==1)
            {
                moveSmallest(A,C,a,c);
            movement++;
            }
            else if((n-1)%6==2)
            {
                moveSmallest(A,C,a,c);
                movement++;
                moveLegal(A,B,a,b);
                movement++;
            }
            else if((n-1)%6==3)
            {
                moveSmallest(A,C,a,c);
                movement++;
                moveLegal(A,B,a,b);
                movement++;
                moveSmallest(C,B,c,b);
                movement++;
            }
            else if((n-1)%6==4)
            {
                moveSmallest(A,C,a,c);
            movement++;
            moveLegal(A,B,a,b);
            movement++;
            moveSmallest(C,B,c,b);
            movement++;
            moveLegal(A,C,a,c);
            movement++;
            }
            else if((n-1)%6==5)
            {
                moveSmallest(A,C,a,c);
            movement++;
            moveLegal(A,B,a,b);
            movement++;
            moveSmallest(C,B,c,b);
            movement++;
            moveLegal(A,C,a,c);
            movement++;          
            moveSmallest(B,A,b,a);
            movement++;
            }
            else 
            {
                printf("game is running");
            }
        }
    return 0;
}
