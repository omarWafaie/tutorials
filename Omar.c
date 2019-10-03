#include <stdio.h>
#include <stdlib.h>
#define stackSize 5
typedef struct stack
{
    int data;
    struct stack *pBottom;
    } myStack;
myStack*pTop;
myStack* creatStack(int data);
int push (int data);
int pop (int*data);

int dataLimit ;

int main()
{
printf("Hello World");
    myStack cell;
push(5);
push(10);
push(30);
push(40);
push(50);
int data;
int i;
for (i=0;i<stackSize;i++)
{


if(pop(&data))
printf("%d\n",data);
else
    printf("Empty\n");
}



    return 0;


}
