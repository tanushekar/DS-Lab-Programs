/*
  1.insert by order
  2.insert front
  3.insert rear
  4.search by position
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node *Node;

Node header= NULL;
int count=0;

Node createNode(int value)
{
    Node newnode=(Node)malloc(sizeof(struct node));
    newnode->data= value;
    newnode->next= newnode->prev=NULL;
    return newnode;
}

void initializeheader()
{
    header= createNode(0);
    header->next= header->prev= header;
}

void insertByOrder(int value)
{
    Node temp= header->next;

    while(temp!=header && temp->data<value)
    {
        temp=temp->next;
    }
    Node newnode= createNode(value);
    
    newnode->next= temp;
    newnode->prev= temp->prev;
    temp->prev->next= newnode;
    temp->prev= newnode;
    count++;
}

void insertFront(int value)
{
    Node newnode= createNode(value);
    newnode->next= header->next;
    newnode->prev= header;
    newnode->next->prev= newnode;
    newnode->prev->next= newnode;
    
    if(header->next== header)
    {
        header->prev= newnode;
    }
    count++;
}

void insertRear(int value)
{
    Node newnode= createNode(value);
    
    newnode->prev= header->prev;
    newnode->next= header;
    newnode->prev->next= newnode;
    newnode->next->prev= newnode;
    count++;
}

void searchByPos(int pos)
{
    if(header->next==header)
    {
        printf("Empty list\n");
        return;
    }
    if(pos<1||pos>count)
    {
        printf("Invalid position\n");
        return;
    }
    Node temp=header->next;
    int i=1;
    while(i<pos)
    {
        temp= temp->next;
        i++;
    }
    printf("%d is found at position-%d\n",temp->data, pos);
}

void display()
{
    if(header->next== header)
    {
        printf("List is empty\n");
        return;
    }
    Node temp= header->next;
    while(temp!=header)
    {
        printf("%d-->", temp->data);
        temp= temp->next;
    }
    printf("(Header)\n");
}

void main()
{
    initializeheader();

    int choice, value, pos, key;
    printf("MENU\n1.Insert by order\n2.Insert front\n3.Insert Rear\n4.Search item by position\n");
    for(;;)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter value to be inserted in order: ");
                    scanf("%d", &value);
                    insertByOrder(value);
                    display();
                    printf("\nCount= %d", count);
                    break;

            case 2: printf("Enter value: ");
                    scanf("%d", &value);
                    insertFront(value);
                    display();
                    printf("COUNT=%d\n", count);
                    break;

            case 3: printf("Enter value: ");
                    scanf("%d", &value);
                    insertRear(value);
                    display();
                    printf("COUNT=%d\n", count);
                    break;

            case 4: printf("Enter position to be searched: ");
                    scanf("%d", &pos);
                    searchByPos(pos);
                    display();
                    break;

            case 5: printf("Exiting..\n");
                    exit(0);

            default: printf("Invalid choice\n");
        }
    }
}