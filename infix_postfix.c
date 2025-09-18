#include<stdio.h>
#include<stdlib.h>

#include<string.h>  
#include<ctype.h>   

struct STACK
{
    int top;
    int size;
    int *arr;
};

typedef struct STACK * Stack;

Stack create(int size)
{
    Stack st= (Stack)malloc(sizeof(struct STACK));  
    st->top=-1;
    st->size= size;
    st->arr= (int *)malloc(size*sizeof(int)); 
    return st;
}

int stackprec(char symbol)    
{
    switch(symbol)
    {
        case '+':
        case '-': return 2;

        case '*':
        case '/':
        case '%': return 4;

        case '^':
        case '$': return 5;

        case '(': return 0;

        case '#': return -1;

        default: return 8;
    }
}

int inprec(char symbol)     
{
    switch(symbol)
    {
        case '+':
        case '-': return 1; 

        case '*':
        case '/':
        case '%': return 3;

        case '^':
        case '$': return 6;

        case '(': return 9;

        case ')': return 0;

        default: return 7;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack S= create(30); 

    int i=0;
    int j=0;
    S->arr[++S->top]= '#'; 

    char symbol;

    for(i=0; i<strlen(infix); i++)
    {
        symbol= infix[i];

        while(stackprec(S->arr[S->top]) > inprec(symbol))
        {
            postfix[j++]= S->arr[S->top--];
        }

        if(stackprec(S->arr[S->top]) != inprec(symbol))
        {
            S->arr[++S->top]= symbol;
        }
        else
        {
            S->top--;
        }
    }
    
    while(S->arr[S->top]!='#')
    {
        postfix[j++]= S->arr[S->top--];
    }
    postfix[j]= '\0';
}

void postfixEvaluate(char postfix[])
{
    int i;
    int op1, op2;
    int res;

    Stack stk= create(30);

    char ch;

    for(i=0; i<strlen(postfix); i++)
    {
        ch= postfix[i];

        if(isdigit(ch))
        {
            stk->arr[++stk->top]= ch-'0';
        }
        else 
        {
            if(stk->top<1)
            {
                printf("Not enough operands\n");
            }
            else
            {
                op2= stk->arr[stk->top--];
                op1= stk->arr[stk->top--];

                switch(ch)
                {
                    case '+': res= op1+op2;
                              break;
                    case '-': res= op1-op2;
                              break;
                    case '*': res= op1*op2;
                              break;
                    case '/': res= op1/op2;
                              break;
                    case '%': res= op1%op2;
                              break;
                }
                
                stk->arr[++stk->top]= res;
            }
        }
    }
    printf("RESULT: %d", res);
}

void main()
{
    char infix[30];
    char postfix[30];

    int choice;
    printf("MENU\n1.Enter infix expression\n2.Convert to postfix\n3.Evaluate postfix\n4.EXIT\n");
    for(;;)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter infix expression: ");
                    scanf("%s", infix);
                    break;
                    
            case 2: infixToPostfix(infix, postfix);
                    printf("Postfix: %s", postfix);
                    break;
                    
            case 3: postfixEvaluate(postfix);
                    break;
                    
            case 4: exit(0);
            
            default: printf("Invalid choice!");
        }
    }
}





