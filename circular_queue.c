#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int front;
    int rear;
    int *queue;
}Q;

int size;

void enqueue(int value)
{
    if(Q.front== (Q.rear+1)% size)
    {
        printf("Queue is full\n");
        printf("Reallocating memory\n");
        size++;
        Q.queue=(int *)realloc(Q.queue ,size*sizeof(int));
        printf("Resized to size:%d\n", size);
        
        if(Q.front>Q.rear)
        {
            for(int i=size-1; i>Q.front; i--)
            {
                Q.queue[i]= Q.queue[i-1];
            }
            Q.front++;
        }
    }
    
    if(Q.front==-1 && Q.rear==-1)
    {
        Q.front=Q.rear=0;
    }
    else
    {
        Q.rear=(Q.rear+1)%size;  
    }
    
    *(Q.queue+Q.rear)=value;
}

void dequeue()
{
    if(Q.front==-1 ) 
    {
        printf("Queue is empty\n");
        return;
    }
    else if(Q.front==Q.rear)  
    {
        printf("Deleted element: %d\n", *(Q.queue+Q.front));
        Q.front= Q.rear=-1;
    }
    else{
       printf("Deleted element: %d\n", *(Q.queue+Q.front));
       Q.front= (Q.front+1)%size;
    }
}

void peek()
{
    if(Q.front==-1&&Q.rear==-1) 
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Peek/front element: %d\n", *(Q.queue+Q.front));
}

void display()
{
    if(Q.front==-1&&Q.rear==-1) 
    {
        printf("Queue is empty\n");
        return;
    }
    
    int i=Q.front;
    do
    {
        printf("%d ", *(Q.queue+i));
        i= (i+1)%size;
    }while(i!=(Q.rear+1)%size);
    
    printf("\n");
}

void main()
{
    printf("Enter size of queue: ");
    scanf("%d", &size);
    Q.front= Q.rear=-1;
    Q.queue= (int *)malloc(size*sizeof(int));
    
    int choice, value;
    printf("MENU\n1.Enqueue\n2.dequeue\n3.Peek\n4.Display\n5.EXIT\n");
    for(;;)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: printf("Enter element: ");
                    scanf("%d", &value);
                    enqueue(value);
                    display();
                    break;
                    
            case 2: dequeue();
                    display();
                    break;
                    
            case 3: peek();
                    display();
                    break;
                    
            case 4: display();
                    break;
                    
            case 5: printf("Exiting\n");
                    exit(0);
                    
            default: printf("Invalid choice!\n");
        }
    }
}