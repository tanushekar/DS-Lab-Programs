#include<stdio.h>
#include<stdlib.h>

int size;

struct Queue
{
    int front;
    int rear;
    int *queue;
}Q;

void enqueue(int value)
{
    if(Q.rear==size-1)
    {
        printf("Queue is full\n");
        printf("Reallocating memory..\n");

        size++;
        Q.queue= (int *)realloc(Q.queue, size*(sizeof(int)));
    }

    if(Q.front==-1)
    {
        Q.front=0;
    }
    Q.rear++;
    
    Q.queue[Q.rear]= value;
    printf("Insertion successful\n");
}

void dequeue()
{
    if(Q.front==-1 && Q.rear==-1)
    {
        printf("Empty queue\n");
    }
    if(Q.front==Q.rear)
    {
        Q.front= Q.rear=-1;
    }
    else
    {
        printf("Deleted element: %d", Q.queue[Q.front]);
        Q.front++;
    }    
}

void display()
{
    if(Q.front==-1 && Q.rear==-1)
    {
        printf("Empty queue\n");
    }
    else
    {
        printf("Queue is: ");
        for(int i=Q.front; i<=Q.rear; i++)
        {
            printf("%d ",Q.queue[i]);
        }
    }
}

void main()
{
    int choice, value;

    Q.front= Q.rear=-1;

    printf("Enter size of queue: ");
    scanf("%d", &size);

    Q.queue= (int *)malloc(size*sizeof(int));

    printf("MENU\n1.Insert\n2.Delete\n3.Display\n4.EXIT\n");
    for(;;)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: printf("Enter value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;
                
        case 2: dequeue();
                break;
                
        case 3: display();
                break;
                
        case 4: printf("Exiting..");
                exit(0);
                
        default:printf("Invalid choice!");
        }
    }
}