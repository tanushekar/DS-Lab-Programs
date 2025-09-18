/*
  1.insert by order
  2.delete by position
  3.delete by key
  4.search by position
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *Node;

Node header=NULL;
int count=0;

Node createNode(int value)
{
    Node newnode= (Node)malloc(sizeof(struct node));
    newnode->data= value;
    newnode->next=newnode->prev=NULL;
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
        temp= temp->next;
    }
    //temp will be at node next to required position
    Node newnode= createNode(value);
    
    newnode->next= temp;
    newnode->prev= temp->prev;
    temp->prev->next= newnode;
    temp->prev= newnode;
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
    Node temp=header->next;
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

void deleteByKey(int key)
{
    if(header->next==header)
    {
        printf("Empty list\n");
        return;
    }
    Node temp=header->next;
    while(temp!=header)
    {
        if(temp->data==key)
        {
            temp->prev->next= temp->next;
            temp->next->prev= temp->prev;
            free(temp);
            count--;
            return;
        }
        temp= temp->next;
    }
    printf("Key not found\n");
}

void searchByPos(int pos)
{
    if(header->next==header)
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
    printf("%d is found position-%d\n", temp->data, pos);
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
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("(Header)");
    
}

void main()
{
    initializeheader();

    int choice, value, pos, key;
    printf("MENU\n1.Insert by order\n2.Delete by position\n3.Search by key\n4.Delete by key\n");
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
                    
            case 2: printf("Enter position to be deleted: ");
                    scanf("%d", &pos);
                    deleteByPos(pos);
                    display();
                    printf("\nCount= %d", count);
                    break;
                    
            case 3: printf("Enter key: ");
                    scanf("%d", &value);
                    deleteByKey(value);
                    display();
                    break;
                    
            case 4: printf("Enter position to be searched: ");
                    scanf("%d", &pos);
                    searchByPos(pos);
                    display();
                    break;
                    
            case 5: exit(0);
            
            default: printf("Invalid position\n");
        }
    }
}