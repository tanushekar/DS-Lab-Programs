#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<ctype.h>

struct stack
{
    int top;
    int size;
    int *arr;
};

typedef struct stack * STACK;

STACK create(int size)
{
    STACK st= (STACK)malloc(sizeof(struct stack));
    st->top=-1;
    st->size=size;

    st->arr= (int *)malloc(size*sizeof(int));
    return st; 
}

/*
void strrev(char string[])
{
    int left=0;
    int right= strlen(string)-1;
    for(int i=0; i<strlen(string); i++)
    {
        while(left<right)
        {
          char temp= string[left];
          string[left]= string[right];
          string[right]= temp;
          left++;
          right--;
        }
    }
}
*/

int stackprec(char symbol)
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

        case ')': return 0;
         
        case '#': return -1;
        
        default: return 8;
    }
}

int inprec(char symbol)
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

        case ')': return 9;
         
        case '(': return 0;
        
        default: return 7;
    }
}

void infixToPrefix(char infix[], char prefix[])
{
    STACK S= create(50);
    int i=0;
    int j=0;
    char symbol;
    S->arr[++S->top]='#';

    strrev(infix);

    for(i=0; i<strlen(infix); i++)
    {
        symbol= infix[i];

        while(stackprec(S->arr[S->top]) > inprec(symbol))
        {
            prefix[j++]= S->arr[S->top--];
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
    
    while(S->arr[S->top]!= '#')
    {
        prefix[j]= S->arr[S->top--];
        j++;
    }
    prefix[j]='\0';

    strrev(prefix);
}

void prefixEvaluate(char prefix[])
{
    STACK stk= create(30);
    int i, op1, op2;
    int res;
    char ch;
    
    strrev(prefix); 

    for(i=0; i<strlen(prefix); i++)
    {
        ch= prefix[i];

        if(isdigit(ch))
        {
            stk->arr[++stk->top]=ch-'0';
        }
        else
        {
            if(stk->top<1)  
            {
                printf("Not enough operands!\n");
                return;
            }
            else
            {
                op1= stk->arr[stk->top--];   
                op2= stk->arr[stk->top--];
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
                    default: printf("Invalid operator\n");
                }
                
                stk->arr[++stk->top]= res;
            }
        }
    }
    printf("RESULT: %d\n", res);
}

void main()
{
    char infix[30];
    char prefix[30];

    int choice;
    printf("MENU\n1.Enter infix expression\n2.Convert to prefix\n3.Evaluate prefix\n4.EXIT\n");
    for(;;)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter infix expression: ");
                    scanf("%s", infix);
                    break;
                    
            case 2: infixToPrefix(infix, prefix);
                    printf("PREFIX: %s\n", prefix);
                    break;
                    
            case 3: prefixEvaluate(prefix);
                    break;
                    
            case 4: exit(0);
            
            default: printf("Invalid choice!\n");
        }
    }
}