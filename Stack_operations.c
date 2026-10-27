#include<stdio.h>
#include<stdbool.h>

#define STACK_SIZE 5


void push(int stack[], int *top, int value) 
{
    if (*top >= STACK_SIZE - 1) {
        printf("Stack overflow!!\n");
        return;
    }
    stack[++(*top)] = value;
}

int pop(int stack[], int *top)
{
    if (*top <= -1)
    {
        printf("Stack Underflow\n");
        return *top;
    }
    return stack[(*top)--];
}

void display(int stack[], int *top)
{
    if (*top <= -1)
    {
        printf("Nothing to display - Stack Underflow\n");
        return;
    }
    printf("Stack Elements (Top to Bottom):\n");
    for (int i= *top; i>=0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int s[STACK_SIZE], top= -1, value, choice;
    while (true)
    {
        printf("1. Push\n2. Pop\n3. Display\n");
        printf("Select your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : printf("Enter the element to be pushed: ");
                     scanf("%d",&value);
                     push(s,&top,value);
                     break;
            
            case 2 : printf("%d\n",pop(s, &top));
                     break;
                
            case 3 : display(s, &top);
                     break;
            
            default : printf("Invalid Choice\n");
                      break;
        }
    }
    return 0;
}