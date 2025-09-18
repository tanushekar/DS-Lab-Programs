#include<stdio.h>
#include<stdlib.h>

int size;

struct Queue
{
    int front;
    int rear;
    int *queue;
}Q;

int priorityCheck(int X)
{
    int i=0;
    while(i<=Q.rear && *(Q.queue+i)<X) 
    {
        i++;
    }
    return i;
}

void insert(int X)
{
    int i, pos;
    if(Q.rear==size-1)
    {
        printf("Queue is full\n");
        printf("Reallocating memory\n");

        size++;
        Q.queue= (int *)realloc(Q.queue,size*sizeof(int));
    }
    if(Q.rear==-1 && Q.front==-1)
    {
        Q.front= Q.rear= 0;
        *(Q.queue+Q.rear)=X;
        printf("Insertion successful\n");
    }
    else
    {
        pos= priorityCheck(X);
        Q.rear++; 
        for(i=Q.rear; i>pos; i--)
        {
            *(Q.queue+i)= *(Q.queue+i-1);
        }
        *(Q.queue+pos)=X;
        printf("Insertion SUCCESSful\n");
    }
}

void delete()
{
    if(Q.front==-1)
    {
        printf("Queue is empty\n");
    }
    else if(Q.front==Q.rear)
    {
        printf("Deleted element: %d\n",*(Q.queue+Q.front));
        Q.front= Q.rear=-1;
    }
    else
    {
        printf("Deleted element: %d\n",*(Q.queue+Q.front));
        Q.front++;
    }
}

void display()
{
    if(Q.front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is: ");
        for(int i=Q.front; i<=Q.rear; i++)  
        {
            printf("%d ", *(Q.queue+i));
        }
        printf("\n");
    }
}

void main()
{
    int choice, value;
    Q.front=Q.rear=-1;

    printf("Enter size of queue: ");
    scanf("%d", &size);               

    Q.queue=(int *)malloc(size*sizeof(int));

    printf("MENU\n1.Insert\n2.Delete\n3.Display\n4.EXIT\n");

    for(;;)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: printf("Enter element to be inserted: ");
                    scanf("%d", &value);
                    insert(value);
                    display();
                    break;
                    
            case 2: delete();
                    display();
                    break;
                    
            case 3: display();
                    break;
                    
            case 4: printf("Exiting..");
                    exit(0);
                    
            default: printf("Invalid choice!\n");
        }
    }
}