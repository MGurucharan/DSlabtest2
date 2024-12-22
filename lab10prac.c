#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  char word[25];
  struct node *left;
  struct node *right;
};
typedef struct node *NODEPTR;

NODEPTR getnode() // gives life to a node
{
  NODEPTR r = (NODEPTR)malloc(sizeof(struct node));
  if (r == NULL)
  {
    printf("Allocation failed!!\n");
    return NULL;
  }
  return r;
}

NODEPTR create_tree(char word[]) // initializes the node created with values
{
  NODEPTR tree_node = getnode();
  strcpy(tree_node->word, word);
  tree_node->left = NULL;
  tree_node->right = NULL;
  return tree_node;
}

void attach_as_leftnode(NODEPTR curr_root_node, char word[])
{
  if (curr_root_node == NULL)
  {
    printf("Void insertion!\n");
  }
  else if (curr_root_node->left != NULL)
  {
    printf("Left Node already exists ,can't make a new one!\n");
  }
  else
  {
    curr_root_node->left = create_tree(word);
  }
}

void attach_as_rightnode(NODEPTR curr_root_node, char word[])
{
  if (curr_root_node == NULL)
  {
    printf("Void insertion!\n");
  }
  else if (curr_root_node->right != NULL)
  {
    printf("Right Node already exists ,can't make a new one!\n");
  }
  else
  {
    curr_root_node->right = create_tree(word);
  }
}

void pretrav(NODEPTR root_node)
{
  if(root_node!=NULL)
  {
    printf("%s\t",root_node->word);
    pretrav(root_node->left);
    pretrav(root_node->right);
  }
}
void posttrav(NODEPTR root_node)
{
  if(root_node!=NULL)
  {
    posttrav(root_node->left);
    posttrav(root_node->right);
    printf("%s\t",root_node->word);
  }
}
void intrav(NODEPTR root_node)
{
  if(root_node!=NULL)
  {
    intrav(root_node->left);
    printf("%s\t",root_node->word);
    intrav(root_node->right);
  }
}

void search(NODEPTR root_node,char key[])
{
  NODEPTR p=root_node;
  while(p!=NULL&&strcmp(p->word,key)!=0)//p!=NULL ensures full tree traversal 
  {
    if(strcmp(key,p->word)<0)
    {
      p=p->left;
    }
    else
    {
      p=p->right;
    }
  }
  if(p!=NULL)
  {
    printf("Key %s is found in the dictionary! \n",key);
  }
  else
  {
    printf("Key %s is not found in the dictionary! \n",key);
  }
}

int main()
{
  int choice;
  NODEPTR ptree=NULL; // pointer to root node
  char word[25]; 
  char key[25];
  do
  {
    printf("1->CREATE DICTIONARY    2->TRAVERSE     3->SEARCH    4->EXIT\n");
    printf("Enter your choice: \n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        //initialize the root node
        printf("Enter the root_word: \n");
        scanf("%s",word);
        ptree=create_tree(word);
        NODEPTR p,q; // two pointers , just like slow and fast
        //but here p is root and q is the child , so root and child
        //lets initialize both , like how we do in LL (p,q=head)
        while(strcmp(word,"END")!=0)
        {
          printf("Enter the word (END TO STOP): \n");
          scanf("%s",word);
          if(strcmp(word,"END")==0)
          {
            break;
          }
          p=ptree;
          q=ptree;
          //The below while loop finds the insertion point in the whole binary tree
          while(q!=NULL && strcmp(word,p->word)!=0) // q!=NULL (till my child is not equal to NULL , we keep traversing) ensures that it has reached the point to insert the freshnode
          // and that comparision condition is another indication that since word and curr_root node 
          // words are equal , so no need to find the insertion position as we have already reached.
          {
            //resetting both the slow and fast pointers to curr_root of the trio as p=q
            p=q; // slow pointer , as its the root node of every trio
            if(strcmp(word,p->word)<0)
            {
              q=p->left; // fast pointer as its the child node of every trio
            }
            else
            {
              q=p->right; // fast pointer as its the child node of every trio
            }
          }
          if(strcmp(word,p->word)<0)
          {
            attach_as_leftnode(p,word); //so p is the current tri root node and attaching freshnode as left
          }
          else if(strcmp(word,p->word)>=0)
          {
            attach_as_rightnode(p,word); // so p is the current tri root node '' '' as right
          } 
        }
        printf("CREATED DICTIONARY !!\n");
        break;
      
      case 2:
        printf("PREORDER TRAVERSAL: \n");
        pretrav(ptree);
        printf("\n");
        printf("POSTORDER TRAVERSAL: \n");
        posttrav(ptree);
        printf("\n");
        printf("INORDER TRAVERSAL: \n");
        intrav(ptree);
        printf("\n");
        break;
      
      case 3:
        printf("Enter the key word to search in dictionary: \n");
        scanf("%s",key);
        search(ptree,key);
        break;
      
      case 4:
        exit(1);
        break;
      
      default:
        printf("Enter a valid choice!!\n");
        break;
    }
  }while(choice!=4);
return 0;
}