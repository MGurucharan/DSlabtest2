#include<stdio.h>
#include<stdlib.h>

struct node
{
  int pageno;
  struct node*left;
  struct node*right;
};
typedef struct node*NODEPTR;
NODEPTR list=NULL;

NODEPTR getnode()
{
  NODEPTR r=(NODEPTR)malloc(sizeof(struct node));
  return r;
}

NODEPTR createlist(NODEPTR list,int pgno)
{
  NODEPTR p=getnode();
  p->pageno=pgno;
  p->left=NULL;
  p->right=NULL;
  if(list==NULL)
  {
    list=p;
  }
  else
  {
    NODEPTR q=list;
    while(q->right!=NULL)
    {
      q=q->right;
    }
    q->right=p;
    p->left=q;
  }
  return list;
}

NODEPTR moveforward(NODEPTR list,int currentpagenumber,int steps)
{
  int s=0;
  if(list==NULL)
  {
    printf("Empty list\n");
    return NULL;
  }
  NODEPTR p=list;
  while(p!=NULL && p->pageno!=currentpagenumber)
  {
    p=p->right;
  }
  if(p==NULL)
  {
    printf("Enter a valid current page number!!!\n");
    return NULL;
  }
  NODEPTR q=p;
  while(q->right!=NULL&&s<steps)
  {
    q=q->right;
    s++;
  }
  return q;
}

NODEPTR movebackward(NODEPTR list,int currentpagenumber,int steps)
{
  int s=0;
  if(list==NULL)
  {
    printf("Empty list\n");
    return NULL;
  }
  NODEPTR p=list;
  while(p!=NULL && p->pageno!=currentpagenumber)
  {
    p=p->right;
  }
  if(p==NULL)
  {
    printf("Enter a valid current page number!!!\n");
    return NULL;
  }
  NODEPTR q=p;
  while(q->left!=NULL&&s<steps)
  {
    q=q->left;
    s++;
  }
  return q;
}

void display(NODEPTR list)
{
  if(list==NULL)
  {
    printf("Empty list!!\n");
  }
  NODEPTR p =list;
  while(p!=NULL)
  {
    printf("%d <-> ",p->pageno);
    p=p->right;
  }
  printf("NULL");
  printf("\n");
}

int main()
{
  int pagenum;
  NODEPTR p =list;
  int choice,steps,currentpageno;
  char response;
  do
  {
    printf("1-> CREATE LIST 2-> MOVE FORWARD 3->MOVE BACKWARD 4->DISPLAY 5->EXIT\n");
    printf("Enter your choice: \n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        do
        {
          printf("Enter the page number: \n");
          scanf("%d",&pagenum);
          list=createlist(list,pagenum);
          printf("Do you want to enter more?[Y/N]: \n");
          scanf(" %c",&response);
        }while(response=='Y' || response=='y');
        break;

      case 2:
        printf("Enter the current page number from wher you want to start: \n");
        scanf("%d",&currentpageno);
        printf("Enter the number of steps to move forward: \n");
        scanf("%d",&steps);
        p=list;
        p=moveforward(list,currentpageno,steps);
        printf("MOVED TO %d pagenumber from %d pagenumber\n",p->pageno,currentpageno);
        break;

      case 3:
        printf("Enter the current page number from wher you want to start: \n");
        scanf("%d",&currentpageno);
        printf("Enter the number of steps to move backward: \n");
        scanf("%d",&steps);
        p=list;
        p=movebackward(list,currentpageno,steps);
        printf("MOVED TO %d pagenumber from %d pagenumber\n",p->pageno,currentpageno);
        break;

      case 4:
        display(list);
        break;
  
      case 5:
        exit(1);
        break;
      
      default:
        printf("Enter a valid choice!!\n");
        break;
    }
  }while(choice!=5);
  return 0;
}