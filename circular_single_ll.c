/*
 1.Insert front 
 2.Insert rear 
 3.Insert by position 
 4.Insert by order 
 5.Delete Front
 6.Delete Rear 
 7.Delete by position 
 8.Delete by Key 
 9.Search by key
 10.Search by position.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *Node;

Node header=NULL;
int count=0;

Node createNode(int value)
{
    Node newnode= (Node)malloc(sizeof(struct node));
    newnode->data= value;
    newnode->next= NULL;
    return newnode;
}

void initializeheader()
{
    header= createNode(0);
    header->next= header;
}

void insertFront(int value)
{
    Node newnode=createNode(value);
    if(header->next==header)
    {
        header->next= newnode;
        newnode->next= header;
    }
    else
    {
        newnode->next= header->next;
        header->next= newnode;
    }
    count++;
}

void insertRear(int value)
{
    Node newnode= createNode(value);
    if(header->next==header)
    {
        header->next= newnode;
        newnode->next= header;
    }
    Node temp= header->next;
    while(temp->next!=header)
    {
        temp=temp->next;
    }
    temp->next= newnode;
    newnode->next= header;
    count++;
}

void deleteFront()
{
    if(header->next==header)
    {
        printf("Empty list\n");
        return;
    }
    Node temp=header->next;
    printf("Deleted element: %d\n", temp->data);
    header->next= temp->next;
    free(temp);
    count--;
}

void deleteRear()
{
    if(header->next==header)
    {
        printf("Empty list\n");
        return;
    }
    Node temp=header->next;
    while(temp->next->next!=header)
    {
        temp=temp->next;
    }
    Node lastnode= temp->next;
    temp->next= header;
    free(lastnode);
    count--;
}

void deleteByKey(int key)
{
    if(header->next==header)
    {
        printf("List is empty\n");
        return;
    }
    Node temp= header->next;
    Node prev= header;
    while(temp!=header&&temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==header)
    {
        printf("Key not found\n");
        return;
    }
    else //temp will have the key
    {
        prev->next= temp->next;
        free(temp);
        count--;
    }
}

void insertAtPos(int value, int pos)
{
    Node newnode= createNode(value);

    if(header->next==header && pos==1)   //if pos is 1 and it is an empty list
    {
        header->next= newnode;
        newnode->next= header;
        count++;
        return;
    }
    if(pos<1 || pos>count+1)
    {
        printf("Invalid position\n");
        return;
    }
    if(pos==1)
    {
        //insert front
        newnode->next= header->next;
        header->next= newnode;
        count++;
        return;
    }

    //at any other position
    Node temp=header->next;
    int i=1;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next= temp->next;
    temp->next=newnode;
    count++;
}

void deleteAtPos(int pos)
{
    if(header->next==header)
    {
        printf("Empty list\n");
        return;
    }
    if(pos<1 || pos>count)
    {
        printf("Invalid position\n");
        return;
    }
    Node temp= header->next;
    int i=1;
    Node prev= header;
    while(i<pos)
    {
        prev=temp;
        temp= temp->next;
        i++;
    }
    //temp points to required pos
    prev->next= temp->next;
    free(temp);
    count--;
}

void searchByKey(int key)
{
    Node temp= header->next;
    int pos=1;
    while(temp!= header)
    {
        if(temp->data==key)
        {
            printf("Key found at position-%d\n", pos);
            return;
        }
        temp= temp->next;
        pos++;
    }
    printf("key not found\n");
}

void searchByPos(int pos)
{
    if(header->next==header)
    {
        printf("List empty\n");
        return;
    }
    Node temp=header->next;
    int i=1;
    if(pos>0 && pos<=count)
    {
        while(temp!=header && i!=pos)
        {
            temp=temp->next;
            i++;
        }
        printf("%d is present at pos-%d\n", temp->data, i);
        return;
    }
    else{
        printf("Invalid position\n");
    }
}

void reverse()
{
    if(header->next== header || header->next->next==header)
    {
        return;
    }
    Node cur= header->next;
    Node prev= header;
    do
    {
        Node nextnode= cur->next;
        cur->next= prev;
        prev= cur;
        cur= nextnode;
    }while(cur!=header);
    
    header->next= prev;
}

void insertByOrder(int value)
{
    if(header->next==header)
    {
        Node newnode= createNode(value);
        newnode->next=header;
        header->next= newnode;
        count++;
        return;
    }
    else
    {
        Node temp= header->next;
        Node prev= header;
        while(temp!=header && temp->data<value)
        {
            prev = temp;
            temp=temp->next;
        }
        
        Node newnode= createNode(value);
        newnode->next= temp;
        prev->next= newnode;
        count++;
    }
}

void display()
{
    if(header->next==header)
    {
        printf("List is empty\n");
        return;
    }
    Node temp=header->next;
    while(temp!=header)
    {
        printf("%d-->", temp->data);
        temp=temp->next;
    }
    printf("(Header)\n");
}

void main()
{
    initializeheader();
    
    int value, pos, key, choice;
    printf("MENU\n1.Insert front\n2.Insert rear\n3.Delete front\n4.Delete rear\n5.Delete by Key\n6.Insert at position\n");
    printf("7.Delete at position\n8.Search by key\n9.Search by position\n10.Reverse\n11.Insert by order\n12.Exit\n");
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
                    printf("count= %d\n", count);
                    break;

            case 2: printf("Enter value: ");
                    scanf("%d", &value);
                    insertRear(value);
                    display();
                    printf("count= %d\n", count);
                    break;

            case 3: deleteFront();
                    display();
                    printf("count= %d\n", count);
                    break;
                    
            case 4: deleteRear();
                    display();
                    printf("count= %d\n", count);
                    break;

            case 5: printf("Enter key to be deleted: ");
                    scanf("%d", &value);
                    deleteByKey(value);
                    display();
                    printf("count= %d\n", count);
                    break;
                    
            case 6: printf("Enter value and position: ");
                    scanf("%d %d", &value, &pos);
                    insertAtPos(value, pos);
                    display();
                    printf("count= %d\n", count);
                    break;
                    
            case 7: printf("Enter position to be deleted: ");
                    scanf("%d", &pos);
                    deleteAtPos(pos);
                    display();
                    printf("count= %d\n", count);
                    break;

            case 8: printf("Enter key to be searched: ");
                    scanf("%d", &key);
                    searchByKey(key);
                    display();
                    printf("count= %d\n", count);
                    break;
            
            case 9: printf("Enter position to be searched: ");
                    scanf("%d", &key);
                    searchByPos(key);
                    display();
                    printf("count= %d\n", count);
                    break;
                    
            case 10: reverse();
                     printf("Reversed list: ");
                     display();
                     printf("count= %d\n", count);
                     break;
                    
            case 11: printf("Enter element to be inserted in order: ");
                     scanf("%d", &value);
                     insertByOrder(value);
                     display();
                     printf("count= %d\n", count);
                     break;
            
            case 12: printf("\nExiting..\n");
                     exit(0);

        }
    }
}