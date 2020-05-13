//PRINTER-SPOLLER PROBLEM
//here we had created two linked list one containing process id and file name and another list having in and filename which need to be printed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{ int process_id;
  char file_name[20];
  struct node *next;
};
struct spoller
{ int IN;
  char file[20];
  struct spoller *next1;
};
struct node *head=NULL;
struct spoller *head1=NULL;
void create(int id,char filename[20])
{ struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->process_id=id;
  strcpy(new->file_name,filename);
  new->next=NULL;
  if(head==NULL)
  { head=new;
  }
  else
  { struct node *t=head;
    while(t->next!=NULL)
    { t=t->next;
    }
    t->next=new;
  }
}
void spoller_directory(int in,char name[20])
{ struct spoller *new;
  new=(struct spoller*)malloc(sizeof(struct spoller));
  new->IN=in;
  strcpy(new->file,name);
  new->next1=NULL;
  if(head1==NULL)
  { head1=new;
  }
  else
  { struct spoller *t=head1;
    while(t->next1!=NULL)
    { t=t->next1;
    }
    t->next1=new;
  }
}
void printer()
{ struct spoller *t=head1;
  head1=head1->next1;
   --(head1->IN);
   printf("\nprinted=%s",t->file);
   free(t);
   
}  
int main()
{ 
  int in,id,n;
  in=0;
  char name[20];
  printf("enter your choice\n");
  while(1)
  { printf("\n1.creation and insertion in spoller\n2.printer");
    scanf("%d",&n);
    switch(n)
    { case 1: printf("\nenter the id and filename");
              scanf("%d",&id);
              fgets(name,20,stdin);
              create(id,name);
              printf("\nmoving to spoller directory");
              spoller_directory(in,name);
              ++in;
              break;
     case 2: if(head1==NULL)
             { printf("\n empty spoller directory");
             }
             else
             { printer();
             }
             break;
     default: exit(0);
    }
  }
 return 0;
}
     
         
   
