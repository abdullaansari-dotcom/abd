#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char c)
{
    stack[++top]=c;
}

char pop()
{
    return stack[top--];
}

int precedence(char c)
{
    if( c=='^')
    return 3;
    else if (c=='*' || c=='/')
    return 2;
    else if (c=='+' || c=='-')
    return 1;
    else
    return 0;
}

void InfixtoPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if (isalnum(c))
        {
            postfix[j++] = c;
            postfix[j] = '\0';

            printf("%s\n", postfix);
        }

        else if (c == '(')
        {
            push(c);

            postfix[j] = '\0';
            printf("%s\n", postfix);
        }

        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
                postfix[j] = '\0';

                printf("%s\n", postfix);
            }

            pop();   // Remove '('
        }

        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = pop();
                postfix[j] = '\0';

                printf("%s\n", postfix);
            }

            push(c);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
        postfix[j] = '\0';

        printf("%s\n", postfix);
    }

    postfix[j] = '\0';

    printf("Final Postfix: %s\n", postfix);
}

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression:");
    scanf("%s",infix);
    InfixtoPostfix(infix,postfix);
    printf("The postfix expression: %s\n",postfix);
    return 0;
}