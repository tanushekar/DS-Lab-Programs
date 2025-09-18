/*
1.Insert by position 
2.Insert by order 
3.Delete by position 
4.Delete by key 
5.Search by position 
6.Search by key 
7.Reverse the contents.
*/

#include<stdio.h>
#include<stdlib.h>

int ne=0;

void read(int *x)  
{
    int i, n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", (x+i));
    }
    ne=n;
}

void display(int *x)
{
    int i;
    printf("The array is: ");
    for(i=0; i<ne; i++)
    {
        printf("%d ", *(x+i));
    }
}

void insert_by_pos(int *x, int size)
{
    int i, pos, ele;
    if(ne==size)
    {
        printf("Array full\n");
        printf("Reallocating memory..\n");

        size++;
        x=(int *)realloc(x, size*sizeof(int));
    }

    printf("Enter element: ");
    scanf("%d", &ele);

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos>=1 && pos<=ne+1)
    {
        for(i=ne; i>=pos; i--)
        {
            *(x+i)= *(x+i-1);
        }
        *(x+i)= ele;
        ne++;
    }
    else
    {
        printf("Invalid position..\n");
    }
}

void insert_by_order(int *x, int size)
{
    int i, ele;
    if(ne==size)
    {
        printf("Array full\n");
        printf("Reallocating memory\n");
        size++;
        x=(int *)realloc(x, size*sizeof(int));
    }
    printf("Enter element to be inserted: ");
    scanf("%d", &ele);

    i= ne-1; 

    while(i>=0 && *(x+i)>ele)
    {
        *(x+i+1)= *(x+i);
        i--;
    }
    *(x+i+1)= ele;
    ne++;
}

void delete_by_pos(int *x)
{
    int i, pos;
    if(ne==0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Enter position to be deleted: ");
    scanf("%d", &pos);
    if(pos>0 && pos<=ne)
    {
       for(i= pos-1; i<ne-1; i++)
       {
           *(x+i)= *(x+i+1);
       }
    ne--;
    }
    else
    {
        printf("Invalid position!\n");
    }
}

void delete_by_key(int *x)
{
    int i, key, pos=0;
    if(ne==0)
    {
        printf("Empty array\n");
        return;
    }
    printf("Enter key to be deleted: ");
    scanf("%d", &key);

    for(i=0; i<ne && *(x+i)!=key; i++)
    {
        pos++;
    };
    if(i==ne)
        {
            printf("Key not found\n");
            return;
        }
    else
    {
      for(i=pos; i<ne-1; i++)
        {
            *(x+i)= *(x+i+1);
        }
      ne--;
    }
}

void search_by_key(int *x)
{
    int i, key, flag=0;
    if(ne==0)
    {
        printf("Empty array\n");
        return;
    }

    printf("Enter key to be searched: ");
    scanf("%d", &key);

    for(i=0; i<ne; i++)
    {
        if(*(x+i)==key)
        {
            flag=1;
            printf("Key found at position %d\n", i+1);
            break;
        }
    }
    if(flag==0)
    {
        printf("Key not found\n");
    }
}

void search_by_pos(int *x)
{
    int i, pos;
    if(ne==0)
    {
        printf("Empty array\n");
        return;
    }

    printf("Enter position to be searched: ");
    scanf("%d", &pos);

    if(pos>0 && pos<=ne)
    {
        i= pos-1;
        printf("Element at position %d is %d\n", pos, *(x+i));
        return;
    }
    else
        printf("Invalid position!\n");
}

void reverse(int *x)
{
    int i;
    if(ne==0)
    {
        printf("Empty array\n");
        return;
    }
    for(i=0; i<ne/2; i++)
    {
        int temp= *(x+i);
        *(x+i)= *(x+ne-i-1);
        *(x+ne-i-1)= temp;
    }
}

void main()
{
    int *a; 
    int choice, size;

    printf("Enter size of array: "); 
    scanf("%d", &size);

    a= (int *)malloc(size*sizeof(int)); 

    printf("MENU\n1.Read\n2.Print\n3.Insert by positon\n4.Insert by order\n5.Delete by position\n6.Delete by key\n7.Search by key\n8.Search by position\n9.Reverse\n10.EXIT\n");
    for(;;)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: read(a); 
                    break;

            case 2: display(a);
                    break;

            case 3: insert_by_pos(a, size);
                    display(a);
                    break; 

            case 4: insert_by_order(a, size);
                    display(a);
                    break;

            case 5: delete_by_pos(a);
                    display(a);
                    break;

            case 6: delete_by_key(a);
                    display(a);
                    break;

            case 7: search_by_key(a);
                    display(a);
                    break;

            case 8: search_by_pos(a);
                    display(a);
                    break;
                    
            case 9: reverse(a);
                    display(a);
                    break;

            case 10: free(a);
                     a= NULL;
                     printf("Exiting..\n");
                     exit(0);

            default: printf("Invalid choice!");
        }
    }
}


    