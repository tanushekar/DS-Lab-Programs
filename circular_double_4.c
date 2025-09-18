/*
  1.Insert by order
  2.Insert by position
  3.Delete rear
  4.Delete front
  5.Reverse
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

void display()
{
    if(header->next== header)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        Node temp= header->next;
        while(temp!=header)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("(Header)");
    }
}

void insertByPos(int value, int pos)
{
    Node newnode= createNode(value);
    
    if(pos==1)
    {
        //insert_front
        newnode->next= header->next;
        newnode->prev= header;
        header->next->prev= newnode;
        header->next= newnode;
        if(header->next==header)
        {
            header->prev= newnode;
        }
        count++;
        return;
    }

    if(pos<1||pos>count+1)
    {
        printf("Invalid position\n");
        return;
    }

    Node temp= header->next;
    int i=1;
    while(i<pos-1)
    {
        temp= temp->next;
        i++;
    }
    
    newnode->next= temp->next;
    newnode->prev= temp;
    temp->next->prev= newnode;
    temp->next= newnode;
    count++;
}

void deleteFront()
{
    if(header->next==header)
    {
        printf("Empty list\n");
        return;
    }
    Node temp= header->next;
    header->next= temp->next;
    temp->next->prev= header;
    free(temp);
    count--;
}

void deleteRear()
{
    if(header->next==header)
    {
        printf("EMPTY LIST\n");
        return;
    }
    Node temp= header->prev;
    temp->prev->next=header;
    header->prev=temp->prev;
    free(temp);
    count--;
}

void reverse()
{
    if(header->next==header || header->next->next==header)
    {
        return;
    }
    Node current= header->next;
    Node firstnode= header->next;
    Node prev= header;
    do
    {
        Node nextnode= current->next;
        current->next= current->prev;
        current->prev=nextnode;
        prev= current;
        current= nextnode;
    }while(current!=header);
    header->next= header->prev;
    header->prev= firstnode;
}

void main()
{
    initializeheader();

    int choice, value, pos, key;
    printf("MENU\n1.Insert by order\n2.Insert by position\n3.Delete rear\n4.Delete front\n5.Reverse");
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

            case 2: printf("Enter position and value: ");
                    scanf("%d %d", &pos, &value);
                    insertByPos(value, pos);
                    display();
                    printf("\nCount= %d", count);
                    break;

            case 3: deleteFront();
                    display();
                    printf("\nCount= %d", count);
                    break;

            case 4: deleteRear();
                    display();
                    printf("\nCount= %d", count);
                    break;

            case 5: reverse();
                    display();
                    break;

            case 6: exit(0);
            
            default: printf("Invalid choice\n");
        }
    }
}