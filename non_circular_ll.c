#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

};

typedef struct node *Node;

Node header= NULL;
int count=0;

Node createNode(int value)
{
    Node nn= (Node)malloc(sizeof(struct node));
    nn->data=value;
    nn->next=NULL;
    return nn;
}

void initializeheader()
{
    header= createNode(0);
}

void insertFront(int value)
{
    Node nn= createNode(value);
    if(header->next==NULL)
    {
        header->next= nn;
       count++;
       return;
    }
    Node temp= header->next;
    nn->next= temp;
    header->next= nn;
    count++;
}

void insertByOrder(int value)
{
    Node temp= header->next;
    Node prev= header;
    while(temp!=NULL && temp->data<value)
    {
        prev= temp;
        temp= temp->next;
    }
    Node nn= createNode(value);
    nn->next= temp;
    prev->next=nn;
    count++;
}

void insertByPos(int value, int pos)
{
    
    
    if(header->next==NULL && pos==1)
    {
        Node nn= createNode(value);
        header->next=nn;
        count++;
        return;
    }
    if(pos==1)
    {
        Node nn= createNode(value);
        nn->next= header->next;
        header->next= nn;
        count++;
        return;
    }
    if(pos<1||pos>count+1)
    {
        printf("Invalid pos\n");
        return;
    }
    Node nn= createNode(value);
    int i=1;
    Node temp=header->next;
    Node prev=header;
    while(i<pos)
    {
        prev= temp;
        temp= temp->next;
        i++;
    }
    prev->next=nn;
    nn->next=temp;
    count++;

}

void display()
{
    if(header->next==NULL)
    {
        printf("Empty list\n");
        return;
    }
    
    Node temp= header->next;
    do
    {
        printf("%d ", temp->data);
        temp= temp->next;
    }while(temp!=NULL);
    printf("\n");
    printf("Count:%d\n", count);
}

void main()
{
    initializeheader();
    int choice, pos, key, value;
    printf("MENU\n1.INSERT FRONT\n2.Insert by order\n3.Insert by pos\n4.EXIT\n");
    for(;;)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter value: ");
                    scanf("%d", &value);
                    insertFront(value);
                    display();
                    break;

            case 2: printf("Enter value: ");
                    scanf("%d", &value);
                    insertByOrder(value);
                    display();
                    break;
            
            case 3: printf("Enter value: ");
                    scanf("%d", &value);
                    printf("Enter pos: ");
                    scanf("%d", &pos);
                    insertByPos(value, pos);
                    display();
                    break;
            
            case 4: printf("Exiting..\n");
                    exit(0);

        }
    }
}