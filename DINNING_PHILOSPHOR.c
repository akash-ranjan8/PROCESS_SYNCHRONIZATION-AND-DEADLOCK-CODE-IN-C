//DINNING PHILOSPHOR SOLUTION IN C
//BY REVERSING THE ORDER OF THE LAST PHILOSPHOR WE CAN AVOID THE DEADLOCK IN THE PROBLEM MEANS LAST PHILOSPHOR WILL PICK RIGHT FORK FIRST THEN THE LEFT FORK
//HERE WE HAD CREATED TWO STRUCTURE ONE FOR FORK AND OTHER FOR PHILOSPHOR
#include<stdio.h>
#define n 4
int c=0;
struct fork
{ int taken;
}fork_avail[n];
struct philosphor
{ int left;
  int right;
}phil[n];
//WE HAD TAKEN A RANDOM VALUE 10 TO ASSIGN TO THE LEFT AND RIGHT OF PHILOSPHOR ARRAY TO SHOW THAT THEY HAD DONE THERE DINNER
//C IS USED FOR COUNTING THE NO. OF PHILOSPHORS COMPLETED DINNER
//WE HAD TAKEN FOUR CASES FIRST PHILOSPHOR DONE DINNER SECOND PICKED BOTH THE FORKS THIRD PICKED LEFT FORK AND FOURTH ONE NOT PICKED ANY FORK
//WE ARE ASSIGING VALUE ONE IF CASE GOES TRUE OTHERWISE ASSIGNING ZERO TO IT
//IN EVERY CASE WE ARE CHECKING THAT PHILOSPHOR HAS PICKED THE FORK OR STILL WAITING
void dinner(int id)
{ if( phil[id].left==10 && phil[id].right==10)
  { printf("\nphilosphor completed dinner is =%d",id+1);
  }
  else if(phil[id].left==1 && phil[id].right==1)
  { phil[id].left=phil[id].right=10;
    int other=id-1;
    if(other==-1)
    { other=n-1;
    }
    fork_avail[id].taken=fork_avail[other].taken=0;
    printf("\nphilosphor %d released fork %d and %d ",id+1,id+1,other+1);
    ++c;
  }
  else if(phil[id].left==1 && phil[id].right==0)
  { if(id==n-1)
    { if(fork_avail[id].taken==0)
      { fork_avail[id].taken=phil[id].right=1;
        printf("\n philosphor %d taken fork %d ",id+1,id+1);
      }
      else
      { printf("\n philosphor %d waiting for fork %d",id+1,id+1);
      }
    }
    else
    { int d=id;
      id=id-1;
      if(id==-1)
      { id=n-1;
      }
      if(fork_avail[id].taken==0)
      { fork_avail[id].taken=phil[n].right=1;
        printf("\n philosphor %d taken fork %d ",d+1,id+1);
      }
      else
      { printf("\n philosphor %d is waiting for fork %d",d+1,id+1);
      }
   }
  }  
 else if(phil[id].left==0)
 { if(id==n-1)
   { if(fork_avail[id-1].taken==0)
     { fork_avail[id-1].taken=phil[id].left=1;
       printf("\n philosphor %d has taken fork %d",id,id-1);
     }
     else
     { printf("\n philosphor %d is waiting for fork %d",id,id-1);
     }
   }
   else
   { if(fork_avail[id].taken==0)
     { fork_avail[id].taken=phil[id].left=1;
       printf("\n philosphor %d has taken fork %d ",id+1,id+1);
     }
     else
     { printf("\n philosphor %d is waiting for fork %d ",id+1,id+1);
     }
   }
 }
 else
 { printf("\nwrong!!!!!!");
 }
}
int main()
{ int i;
  for(i=0;i<n;++i)
  { phil[i].left=phil[i].right=1;
    fork_avail[i].taken=1;
  }
  while(c<n)
  { for(i=0;i<n;++i)
    { dinner(i);
    }  
    printf("\n till now philosphors completed dinner is = %d",c);
  }
  return 0;
}
         
