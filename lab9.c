#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
  int coeff;
  int x_pow,y_pow,z_pow;
  struct node*next;
};
typedef struct node*NODEPTR;
NODEPTR list=NULL; //for main function

NODEPTR getnode()
{
  NODEPTR r;
  r=(NODEPTR)malloc(sizeof(struct node));
  return r;
}

NODEPTR create_poly(NODEPTR list,int cf,int x,int y,int z)
{
  NODEPTR p =getnode();
  p->coeff=cf;
  p->x_pow=x;
  p->y_pow=y;
  p->z_pow=z;
  p->next=NULL;
  if(list==NULL)
  {
    p->next=p;
    list=p;
  }
  else
  {
    NODEPTR q=list;
    while(q->next!=list)
    {
      q=q->next;
    }
    q->next=p;
    p->next=list;
  }
  return list;
}

double eval(NODEPTR list,int x,int y,int z)
{ 
  double res=0.0;
  if(list==NULL)
  {
    printf("Empty polynomial\n");
    return res;
  }
  else
  {
    NODEPTR u=list;
    do
    {
      res=res+(u->coeff*(pow(x,u->x_pow))*(pow(y,u->y_pow))*(pow(z,u->z_pow)));
      u=u->next;
    }while(u!=list);
  }
  return res;
}

void display(NODEPTR list)
{
  if(list==NULL)
  {
    printf("Empty polynomial!\n");
  }
  else
  {
    NODEPTR p=list;
    do
    {
      printf(" %dx^%dy^%dz^%d",p->coeff,p->x_pow,p->y_pow,p->z_pow);
      p=p->next;
      if(p!=list)
        printf(" +");
    }while(p!=list);
    printf("\n");
  }
}

int main()
{
  list=create_poly(list,6,2,2,1);
  list=create_poly(list,-4,0,1,5);

  printf("displaying the polynomial: \n");
  display(list);

  double result=eval(list,1,2,3);
  printf("Evaluation result: %lf\n",result);

}