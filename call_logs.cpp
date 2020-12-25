#include<iostream>
#include <stdlib.h>
//for printing the time
#include <time.h>	
using namespace std;			

//definition of queue
struct queue
{				
long number;
char name[20]; 
char date[20];
char tm[30];
struct queue *next;				
} *front, *back, *p;

//function to print the time of calling
void printtime()
{
  int hours, minutes, seconds, day, month, year;
	time_t now;
	time(&now);
	struct tm *local = localtime(&now);
	hours = local->tm_hour;	  	
	minutes = local->tm_min;	 	 
	seconds = local->tm_sec;	 	 
	day = local->tm_mday;			
	month = local->tm_mon + 1;   	
	year = local->tm_year + 1900;
  printf("\nDate    : %02d/%02d/%d                \n", day, month, year);	
	if (hours < 12)	
		printf("Time    : %02d:%02d:%02d am               \n", hours, minutes, seconds);
	else	
		printf("Time : %02d:%02d:%02d pm               \n", hours - 12, minutes, seconds);
}

//function to display call logs
void display(struct queue *t)
{
  printtime();
  cout<<"Contact : "<<t->name<<"\n";
  cout<<"Number  : "<<t->number<<"\n";
}

//function for enqueue operation
void enqueue()
{
 printf("Enter contact details to place a call\n(1)First Name:");	
 p = (struct queue *)malloc(sizeof(struct queue)); 
 scanf("%s",p->name); 
 printf("(2)Contact Number:");
 scanf("%li",&p->number);					
 p->next = NULL;
 //circular queue implementation 
 if(front == NULL)
 {				
   front = p;
   back = p; 
   back->next = front;					
 } 
 else
 {					
  p->next = front;
  back->next = p;
  back = p;					
 }
 printf("\n     Dialing...");
 display(back);
}
										
//function for dequeue operation 
void dequeue()
{				
 struct queue *temp = front; 
 printf("\n      DELETING...");
 display(temp);
 if(front == back)					
   front = back=NULL;
 else
  {  
   front = temp->next;
   back->next=front;
  }
}

int main()
{	
 printf("\n          WELCOME TO CALL LOG MANAGEMENT SYSTEM\n    ___________________________________________________\n\n");				
 int count = 1;									
 char ch;
 do
 {					
   if(ch != '0' && count <=10)
   {
     enqueue();
     count++;
     printf("enter any number to make another call and 0 to stop\n");
   }
   else if(ch !=0)
   {				
     printf("\nCall log full!! \n Removing first contact\n");
     dequeue();
     printf("\nYou may place your call now\n");
     enqueue();
     printf("Press any key to make another call and 0 to stop\n");		
    }
    cin>>ch;	  		
  }while(ch != '0');
printf("\n***Thank you for using CALL LOG MANAGER!***\n");
return 0; 
}
