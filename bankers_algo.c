//BANKERS ALGORITHM
//HERE p[n1] is for the process and total[n1] is for the maximum no. of resource present
//allocation[n1][n2] and max_need[n1][n2] is for the purpose of resource allocated and maximum no. of resorces in need
//total_sum[n1] is for sum of allocated resources
//current_available[n2] stores no. of resources currently available
#include<stdio.h>
int main()
{ int n1,n2;
  printf("enter the no. of process\n");
  scanf("%d",&n1);
  printf("enter the no. of resources\n");
  scanf("%d",&n2);
  int p[n1];
  int total[n2];
  int i,j;
  printf("enter the total number of each resource\n");
  for(i=0;i<n2;++i)
  { scanf("%d",&total[i]);
  }
  int allocation[n1][n2];
  int max_need[n1][n2];
  printf("enter the allocation and maximum need of each process\n");
  for(i=0;i<n1;++i)
  { p[i]=i+1;
    for(j=0;j<n2;++j)
    { scanf("%d%d",&allocation[i][j],&max_need[i][j]);
    }
  }
  int remaining_need[n1][n2];
  for(i=0;i<n1;++i)
  { for(j=0;j<n2;++j)
    { remaining_need[i][j]=max_need[i][j]-allocation[i][j];
    }
  }
  int total_sum[n1];
  for(i=0;i<n1;++i)
  { total_sum[i]=0;
    for(j=0;j<n2;++j)
    { total_sum[i]+=max_need[i][j];
    }
  }
  int current_available[n2];
  for(i=0;i<n2;++i)
  { current_available[i]=total[i]-total_sum[i];
  }
//here we are comparing current_available with the remaining_need and then adding the resources which got freed after getting executed
  for(i=0;i<n1;++i)
  { for(j=0;j<n2;++j)
    { if(current_available[i]>=remaining_need[i][j])
      { printf("\nprocess %d got executed",p[i]); 
       current_available[i]+=allocation[i][j];
       }
       else
       { printf("no process executable\n");
       }
    }
  }
//here if total no. of resources is equal to current_available then it shows that all process has been executed so flag is assigned value 1 otherwise value 0
  int flag=0;
  int c=0;
  for(i=0;i<n2;++i)
  { if(total[i]==current_available[i])
    { flag=1; 
      ++c;
    }
    else
    { flag=0;
    }
  }
//when flag is 1 then system is deadlock free and c is equal to n2 then it shows system is deadlock free
  if(flag==1 && c==n2)
  { printf("\ndeadlock free (safe)\n");
  }
  else
  { printf("\nsystem having deadlock\n");
  }
  return 0;
}
   
