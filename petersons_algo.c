#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{ int turn;
  bool flag[2];
  int n;
  while(1)
  { printf("\n1.process(1)\n2.process(2)");
    scanf("%d",&n);
    switch(n)
    { case 1: printf("process 1\n");
              flag[0]=true;
              turn=1;
              if(turn==1 && flag[1]==true)
              { flag[0]=false;
                printf("process 2 executes\n");
              }
              else
              { printf("process 1 executes\n");
              }
              break;
      case 2: printf("process 2\n");
              flag[1]=true;
              turn=0;
              if(turn==0 && flag[0]==true)
              { flag[1]=false;
                printf("\nprocess1");
                                     
              }
              else
              { printf("\n process 2 executes");
               }
              break;
      default: exit(0);
     }
   }
   return 0;
}
               
              
  
  
