#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
  char song[25];
  struct node*next;
};
typedef struct node* NODEPTR;
NODEPTR playlist=NULL;
NODEPTR getnode()
{
  NODEPTR r;
  r=(NODEPTR)malloc(sizeof(struct node));
  if(r==NULL)
  {
    printf("Allocation has failed!!\n");
  }
  return r;
}

NODEPTR createlist(NODEPTR list,char song[])
{
  NODEPTR p,q;
  p=getnode();
  strcpy(p->song,song);
  p->next=NULL;
  if(list==NULL)
  {
    list=p;
  }
  else
  {
    q=list;
    while(q->next!=NULL)
    {
      q=q->next;
    }
    q->next=p;
  }
  return(list);
}

void begin(NODEPTR list)
{
  if(list==NULL)
  {
    printf("playlist is empty!!\n");
  }
  else
  {
    NODEPTR p=list;
    printf("playing the first song.... [%s]\n",p->song);
  }
}

void end(NODEPTR list)
{
  if(list==NULL)
  {
    printf("playlist is empty!!\n");
  }
  else
  {
    NODEPTR p=list;
    while(p->next!=NULL)
    {
      p=p->next;
    }
    printf("playing the last song....[%s]\n",p->song);
  }
}

NODEPTR deletebegin(NODEPTR list)
{
  NODEPTR p=list;
  if(list ==NULL)
  {
    printf("playlist is empty!!\n");
  }
  else if(list->next==NULL)
  {
    list=p->next;
    free(p);
    return list;
  }
  else
  {
    list=p->next;
    free(p);
    return list;
  }
}

NODEPTR deleteend(NODEPTR list)
{
  NODEPTR p=list;
  if(list ==NULL)
  {
    printf("playlist is empty!!\n");
  }
  else if(list->next==NULL)
  {
    list=p->next;
    free(p);
    return list;
  }
  else
  {
    NODEPTR q=list;
    while(p->next!=NULL)
    {
      q=p; // slow pointer
      p=p->next; // fast pointer
    }
    q->next=NULL;
    free(p);
    return list;
  }
}

void display(NODEPTR head)
{
  if(head==NULL)
  {
    printf("playlist is empty!!\n");
  }
  else
  {
    NODEPTR p=head;
    while(p!=NULL)
    {
      printf("%s\t",p->song);
      p=p->next;
    }
    printf("\n");
  }
}

int main()
{
  char response;
  int choice;
  char song[25];
  do
  {
    printf("1->CREAT PLAYLIST 2->PLAY FIRST 3->PLAY LAST 4->DELETE BEGIN 5->DELETE LAST 6->DISPLAY 7->EXIT\n");
    printf("Enter your choice: \n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        do
        {
          printf("Enter the song name: \n");
          scanf("%s",song);
          playlist=createlist(playlist,song);
          printf("Do you want to enter more songs?[Y/N]: \n");
          scanf(" %c",&response);
        }while(response=='Y'|| response=='y');
        break;
      
      case 2:
        begin(playlist);
        break;
      
      case 3:
        end(playlist);
        break;
      
      case 4:
        playlist=deletebegin(playlist);
        break;
      
      case 5:
        playlist=deleteend(playlist);
        break;
      
      case 6:
        display(playlist);
        break;
      
      case 7:
        exit(1);
        break;
      
      default:
        printf("Enter a valid choice!!\n");
        break;
    }
  }while(choice!=7);
  return 0;
}

