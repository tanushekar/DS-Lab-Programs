#include<stdio.h>
#include<stdlib.h>

int size;

struct Queue
{
  int front;
  int rear;
  int *queue;
}Q;

void resize()
{
  size++;
  int *temp= (int *)realloc(Q.queue, size*sizeof(int));
  if(temp==NULL)
  {
    printf("Memory allocation failed\n");
    return;
  }

  Q.queue= temp;

  if(Q.front>Q.rear)
  {
    for(int i=size-1; i>Q.front; i--)
    {
      Q.queue[i]= Q.queue[i-1];
    }
    Q.front++;
  }
  printf("Queue resized to new size=%d\n", size);
}

void enqueueFront(int value)
{
  if(Q.front==(Q.rear+1)%size)
  {
    printf("Queue is full\n");
    printf("Reallocating memory\n");

    resize();
  }
  if(Q.front==-1 && Q.rear==-1)
  {
    Q.front=Q.rear=0;
  }
  else if(Q.front==0)
  {
    Q.front=size-1;
  }
  else
  {
    Q.front--;
  }
  Q.queue[Q.front]= value;
  printf("Enqueued at front: %d\n", Q.queue[Q.front]);
}

void enqueueRear(int value)
{
  if(Q.front==(Q.rear+1)%size)
  {
    printf("Queue is full\n");
    printf("Reallocating memory\n");

    resize();
  }
  if(Q.front==-1 && Q.rear==-1)
  {
    Q.front=Q.rear=0;
  }
  if(Q.rear==size-1)
  {
    Q.rear=0;
  }
  else
  {
    Q.rear++;
  }
  Q.queue[Q.rear]= value;
  printf("Enqueued at rear: %d\n", Q.queue[Q.rear]);
}

void dequeueFront()
{
  if(Q.rear==-1 && Q.front==-1)
  {
    printf("Queue is empty\n");
    return;
  }

  printf("Deleted element from front: %d\n", Q.queue[Q.front]);
  if(Q.front==Q.rear)
    Q.front= Q.rear= -1;
  else if(Q.front==size-1)
    Q.front= 0;
  else
    Q.front++;
}

void dequeueRear()
{
  if(Q.front==-1 && Q.rear==-1)
  {
    printf("Queue is empty\n");
    return;
  }
  printf("Deleted element from rear:%d\n", Q.queue[Q.rear]);

  if(Q.front==Q.rear)
    Q.front= Q.rear=-1;
  else if(Q.rear==0)
    Q.rear= size-1;
  else
    Q.rear--;
}

void getFront()
{
  if(Q.front==-1 && Q.rear==-1)
  {
    printf("Empty queue\n");
    return;
  }

  printf("Front element: %d\n", Q.queue[Q.front]);
}

void getRear()
{
  
  if(Q.front==-1 && Q.rear==-1)
  {
    printf("Empty queue\n");
    return;
  }
  
  printf("Rear element: %d\n", Q.queue[Q.rear]);

}

void display()
{
  if(Q.front==-1)
  {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue is: ");
  int i=Q.front;
  do
  {
    printf("%d ", Q.queue[i]);
    i= (i+1)%size;
  }while(i!=(Q.rear+1)%size);
  
  printf("\n");
}

void main()
{
  int choice, value;

  Q.front= Q.rear=-1;

  printf("Enter size of queue: ");
  scanf("%d", &size);
  Q.queue= (int *)malloc(size*sizeof(int));

  printf("MENU\n1.Enqueue front\n2.Enqueue rear\n3.Dequeue front\n4.Dequeue rear\n5.Get front\n6.Get rear\n7.EXIT\n");

  for(;;)
  {
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1: printf("Enter element: ");
              scanf("%d", &value);
              enqueueFront(value);
              display();
              break;
              
      case 2: printf("Enter element: ");
              scanf("%d", &value);
              enqueueRear(value);
              display();
              break;
              
      case 3: dequeueFront();
              display();
              break;
              
      case 4: dequeueRear();
              display();
              break;
              
      case 5: getFront();
              break;
              
      case 6: getRear();
              break;
              
      case 7: printf("Exiting\n");
              exit(0);
              
      default: printf("Invalid choice\n");
    }
  }
}