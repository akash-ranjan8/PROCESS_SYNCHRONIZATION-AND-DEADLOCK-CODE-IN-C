#include<stdio.h>
#include<stdlib.h>
int down(int s)
{ return(--s);
}
int up(int s)
{ return(++s);
}
int mutex=1;
int db=1;
int rc=0;
int r=0;
int w=0;
void reader()
{ 
   mutex=down(mutex);
    rc=rc+1;
    if(rc==1)
    { db=down(db);
    }
    mutex=up(mutex);
    mutex=down(mutex);
    rc=rc-1;
    if(rc==0)
    { db=up(db);
    }
    ++r;
    printf("the reader is =%d",r);
    mutex=up(mutex);
  
}
void writer()
{ 
  db=down(db);
  ++w;
  printf("\nexecution of writer=%d",w);
  db=up(db);
}
int main()
{ int n;
  printf("enter your choice\n");
  while(1)
  { printf("\n1.reader\n2.writer");
    scanf("%d",&n);
    switch(n)
    { case 1:printf("\n1.reader");
             if(mutex==1 && db==1)
             {reader();
             }
             break;
      case 2:printf("\n2.writer");
             if(db==1)
             {writer();
             }
             break;
      default:exit(0);
    }
   }
  return 0;
}
