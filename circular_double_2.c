/*
  1.insert front
  2.insert rear
  3.delete by position
  4.search by key
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node * Node;

Node header=NULL;
int count=0;

Node createNode(int value)
{
    Node nn=(Node)malloc(sizeof(struct node));
    nn->data= value;
    nn->next= nn->prev=NULL;
    return nn;
}

void initializeheader()
{
    header= createNode(0);
    header->next= header->prev= header;
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
    
    newnode->next= header;
    newnode->prev= header->prev;
    newnode->prev->next= newnode;
    newnode->next->prev= newnode;
    count++;
}

void deleteByPos(int pos)
{
    if(header->next== header)
    {
        printf("List is empty\n");
        return;
    }
    if(pos<1||pos>count)
    {
        printf("Invalid position\n");
        return;
    }
    Node temp= header->next;
    int i=1;
    while(i<pos)
    {
        temp= temp->next;
        i++;
    }
    temp->prev->next= temp->next;
    temp->next->prev= temp->prev;
    free(temp);
    count--;
}

void searchByKey(int key)
{
    if(header->next== header)
    {
        printf("List is empty\n");
        return;
    }
    Node temp= header->next;
    int pos=1;
    while(temp!=header)
    {
        if(temp->data==key)
        {
            printf("Key %d found at position-%d\n", key, pos);
            return;
        }
        temp= temp->next;
        pos++;
    }
    printf("Key not found\n");
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

    printf("MENU\n1.Insert front\n2.Insert rear\n3.Delete by position\n4.Search by key\n5.EXIT\n");
    for(;;)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter value: ");
                    scanf("%d", &value);
                    insertFront(value);
                    display();
                    printf("COUNT=%d\n", count);
                    break;

            case 2: printf("Enter value: ");
                    scanf("%d", &value);
                    insertRear(value);
                    display();
                    printf("COUNT=%d\n", count);
                    break;

            case 3: printf("Enter position to be deleted: ");
                    scanf("%d", &pos);
                    deleteByPos(pos);
                    display();
                    break;

            case 4: printf("Enter key to be searched: ");
                    scanf("%d", &key);
                    searchByKey(key);
                    display();
                    break;

            case 5: printf("Exiting..\n");
                    exit(0);

            default: printf("invalid choice!");
        }
    }
}