/* 
Define a structure called Student with the members: Name, Reg_no, marks in 3 tests and average_marks.
Develop a menu driven program to perform the following by writing separate function for each
operation: a) read information of N students 
           b) display student’s information 
		   c) to calculate the average of best two test marks of each student. 
		   d) Sort students based on Reg_no.
Note: Allocate memory dynamically and illustrate the use of pointer to an array of structure.
*/

#include<stdio.h>
#include<stdlib.h>

int N, size ,i , j;

struct student
{
    char name[30];
    int reg_num;
    int marks[3];
    float avg;
};

void read(struct student *st);
void display(struct student *st);
void average(struct student *st);
void sort(struct student *st);

void main()
{
    struct student *st;

    printf("Enter size of structure: ");
    scanf("%d", &size);

    st= (struct student *)malloc(size*sizeof(struct student));

    int choice;
    printf("MENU\n1.Read details\n2.Display details\n3.Calculate average\n4.Sort based on roll number\n5.EXIT\n");

    for(;;)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: read(st);
                    break;
            case 2: display(st);
                    break;
            case 3: average(st);
                    break;
            case 4: sort(st);
                    break;
            case 5: printf("Exiting..\n");
                    exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
void read(struct student *st)
{
    printf("Enter the number of students: ");
    scanf("%d", &N);

    if(N>size)
    {
        printf("Insufficient space\n");
        printf("Reallocating memory..\n");

        st= (struct student *)realloc(st, (N-size)*sizeof(struct student));
        printf("NEW SIZE:%d\n", (N-size));
    }
    for(i=0; i<N; i++)
    {
        printf("Enter details for student-%d: \n", (i+1));
        printf("Enter the reg no.: ");
        scanf("%d", &(st+i)->reg_num);
        printf("\nEnter student name: ");
        scanf("%s", (st+i)->name);
        printf("\nEnter marks in 3 tests: ");
        for(j=0; j<3; j++)
        {
            scanf("%d", &(st+i)->marks[j]);
        }
    }
}

void display(struct student *st)
{
    if(N==0)
    {
        printf("Empty list\n");
        return;
    }
    
    printf("Reg No.\tName\tTest-1\tTest-2\tTest-3\n");
    for(i=0; i<N; i++)
    {
        printf("%d\t%s\t", (st+i)->reg_num, (st+i)->name);
        for(j=0; j<3; j++)
        {
           printf("%d\t", (st+i)->marks[j]);
        }
        printf("\n");
    }
}

void average(struct student *st)
{
    int k, temp, sum[N];

    for(i=0; i<N; i++)
    {
        for(j=0; j<3; j++)
        {
            for(k=0; k<3-j-1; k++)
            {
                if((st+i)->marks[k]>(st+i)->marks[k+1])
                {
                    temp= (st+i)->marks[k];
                    (st+i)->marks[k]= (st+i)->marks[k+1];
                    (st+i)->marks[k+1]= temp;
                }
            }
        }
    }
    for(i=0; i<N; i++)
    {
        sum[i]= (st+i)->marks[1]+(st+i)->marks[2];
        (st+i)->avg= (float)sum[i]/2;
    }
    printf("The average of the students: \n");
    for(i=0; i<N; i++)
    {
        printf("Average marks of student-%d: %.2f", (i+1), (st+i)->avg);
        printf("\n");
    }
}

void sort(struct student *st)
{
   struct student temp;

   for(int i=0; i<N-1; i++)
   {
    for(int j=0; j< N-i-1; j++)
    {
        if( (st+j)->reg_num > (st+j+1)->reg_num )
        {
            temp= *(st+i);
            *(st+i)= *(st+i+1);
            *(st+i+1)= temp;
        }
    }
   }
   printf("Student names sorted by roll number: \n");
   for(int i=0; i<N; i++)
   {
     printf("Roll Number: %d-->%s\n", (st+i)->reg_num,(st+i)->name);

   }
}