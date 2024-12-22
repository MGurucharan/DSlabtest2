#include <stdio.h>
#define MAX 5

struct queue
{
  int front,rear;
  int calls[MAX];
};

void init(struct queue *q)
{
  q->front = q->rear = -1;
}

int isfull(struct queue *q)
{
  return ( (q->rear + 1) % MAX==q->front);
}

int isempty(struct queue *q)
{
  return (q->front == -1);
}

void enqueue(struct queue *q, int call)
{
  if(isfull(q))
  {
    printf("The queue is full , cannot add more calls!!\n");
  }
  else
  {
    if (isempty(q))
    {
      q->front = q->rear = 0;
    }
    else
    {
      q->rear = (q->rear + 1) % MAX;
    }
    q->calls[q->rear] = call;
    printf("Call added successfully!!\n");
  }
}

void dequeue(struct queue *q)
{
  if (isempty(q))
  {
    printf("The queue is empty, cannot delete more calls!!\n");
  }
  else
  {
    printf("call removed : %d\n", q->calls[q->front]);
    if (q->front == q->rear)
    {
      init(q);
    }
    else
    {
      q->front = (q->front + 1) % MAX;
    }
  }
}

void display(struct queue *q)
{
  if (isempty(q))
  {
    printf("The queue is empty!!\n");
  }
  else
  {
    printf("The call status is: \n");
    int i=q->front;
    do
    {
      printf("%d\n",q->calls[i]);
      i=(i+1)%MAX;
    }while(i!=(q->rear+1)%MAX);
  }
}

int main()
{
  struct queue callq;
  init(&callq);
  int call, choice;
  do
  {
    printf("1->ENQUEUE 2->DEQUEUE 3->DISPLAY 4->EXIT\n");
    printf("Enter your choice: \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case (1):
      printf("Enter the call: \n");
      scanf("%d", &call);
      enqueue(&callq, call);
      break;
    case (2):
      dequeue(&callq);
      break;
    case (3):
      display(&callq);
      break;
    case (4):
      printf("Exiting the program!!\n");
      break;
    default:
      printf("Enter a valid choice nigga!!");
      break;
    }
  } while (choice != 4);
  return 0;
}