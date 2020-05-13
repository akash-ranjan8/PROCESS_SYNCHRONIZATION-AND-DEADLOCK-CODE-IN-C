//SOLUTION OF PRODUCER-CONSUMER PROBLEM USING SEMAPHORE
//MUTEX IS THE BINARY SEMAPHORE IF ITS VALUE IS 1 THEN EXECUTIION TAKES PLACE
//C IS FOR COUNTING THE ITEMS CONSUMED OR PRODUCED
//EMPTY IS THE SPACE AVAILABLE FOR PRODUCING
//FULL IS FOR THE ITEM THAT ARE CONSUMED 
//UP IS FOR UPGRADING THE VALUES AND DOWN IS FOR DEGRADING THE VALUES
//HERE MUTEX IS BINARY SEMAPHORE 
//HERE EMPTY AND FULL ARE COUNTING SEMAPHORE
#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int c=0;
int empty=5;
int full=0;
int up(int s)
{ return(++s);
}
int down(int s)
{ return(--s);
}
//HERE WE AT FIRST DECREMENTING THE VALUE OF MUTEX SO THAT PROCESS ENTERS IN CRITICAL SECTION
//THEN WE ARE INCREMENTING FULL AS A NEW ITEM IS PRODUCED
//EMPTY IS DECREMENTED AS A SLOT IS REDUCED
//WE ARE INCREMENTING C AS A NEW ITEM IS PRODUCED
//AGAIN WE ARE INCREMENTING MUTEX AS COMPLETE EXECUTION OF PROCESS HAS TAKEN PLACE
void producer()
{ mutex=down(mutex);
  full=up(full);
  empty=down(empty);
  ++c;
  printf("\nitem produced is= %d",c);
  mutex=up(mutex);
}
//HERE AT FIRST WE ARE DECREMENTING VALUE OF MUTEX SO THAT IT CAN ENTER THE CRITICAL SECTION
//FULL IS GETTING DECREMENTED AS A ITEM IS BEEN CONSUMED
//EMPTY IS BEEN INCREMENTED AS A SLOT IS AVAILABLE AGAIN
//C IS DECREMENTED AS A ITEM IS CONSUMED
//AGAIN MUTEX IS INCREMENTED AS PROCESS COMPLETE EXECUTION HAS TAKEN PLACE
void consumer()
{ mutex=down(mutex);
  full=down(full);
  empty=up(empty);
  printf("\nitem consumed is= %d",c);
  --c;
  mutex=up(mutex);
}
//WHEN BUFFER IS EMPTY OR WE CAN SAY MORE THEN ZERO THEN ITEM CAN BE PRODUCED OTHERWISE BUFFER IS FULL
//WHEN BUFFER IS EMPTY MEANS NO ITEM CAN BE CONSUMED 
int main()
{ int n;
  printf("\n1.producer\n2.consumer");
  while(1)
  { printf("\nenter your choice");
    scanf("%d",&n);
    switch(n)
    { case 1:printf("\n1.producer");
             if(mutex==1 && empty!=0)
             { producer();
             }
             else
             { printf("\nbuffer is full");
             }
             break;
      case 2:printf("\n2.consumer");
             if(mutex==1 && full!=0)
             { consumer();
             }
             else
             { printf("\nbuffer is empty");
             }
             break;
     default: exit(0);
    }
   }
   return 0;
}
    
