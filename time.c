#include<stdio.h>
#include<stdlib.h>

struct TIME
{
    int hr;
    int min; 
    int sec;
};

typedef struct TIME Time; 

void read(Time *); 
void display(Time *);
void add(Time *, Time *, Time *);
void update(Time *);

void main()
{
    Time T1, T2, T3, T4; 
    int choice;

    printf("MENU\n1.Read\n2.Display\n3.Update time\n4.Add two times\n5.EXIT\n");
    for(;;)
    {
       printf("\nEnter choice: ");
       scanf("%d", &choice);

      switch(choice)
      {
        case 1: printf("\nReading time-1: ");
                read(&T1);                    
                printf("\nReading time-2: ");
                read(&T2);
                break;
        
        case 2: printf("\nThe entered times are: ");
                printf("\nTime-1: ");
                display(&T1);
                printf("\nTime-2: ");
                display(&T2);
                break;
        
        case 3: printf("\nEnter the time to be updated: ");
                read(&T3);
                update(&T3);
                printf("\nThe updated time is: ");
                display(&T3);
                break;
        
        case 4: printf("Adding two given times: ");
                printf("\nT1: ");
                display(&T1);
                printf("\nT2: ");
                display(&T2);
                add(&T1, &T2, &T4);
                printf("\nThe updated time is: ");
                display(&T4);
                break;
        
        case 5: printf("Exiting..");
                exit(0);
        
        default: printf("Invalid choice!");
      }
    }
}

void read(Time *T)
{
    printf("\nEnter time in HOURS:MIN:SEC: ");
    scanf("%d %d %d", &(T->hr), &(T->min), &(T->sec));
}

void display(Time *T)
{
    printf("%d: %d: %d", (T->hr), (T->min), (T->sec));
}

void update(Time *T)
{
    T->sec++;
    if(T->sec>=60)
    {
        T->min++;
        T->sec= T->sec%60;
        if(T->min>=60)
        {
            T->hr++;
            T->min= T->min%60;
            if(T->hr>=24)
            {
                T->hr= T->min=T->sec=0;
            }
        }
    }
}

void add(Time *T1, Time *T2, Time *T3)
{
    T3->hr= T3->min= T3->sec=0;

    T3->hr= T1->hr+T2->hr;
    T3->min= T1->min+T2->min;
    T3->sec= T1->sec+T2->sec;

    if(T3->sec>=60)
    {
        T3->min++;
        T3->sec= T3->sec%60;
        if(T3->min>=60)
        {
            T3->hr++;
            T3->min=T3->min%60;
            if(T3->hr>=24)
            {
                T3->hr=T3->min=T3->sec=0;
            }
        }
    }

    if(T3->min>=60)
    {
        T3->hr++;
        T3->min= T3->min%60;
        if(T3->hr>=24)
        {
            T3->hr=T3->min=T3->sec=0;
        }
    }

    if(T3->hr>=24)
    {
        T3->hr=T3->min=T3->sec=0;
    }
}

