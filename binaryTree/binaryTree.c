#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *RightNode;
    struct Node *LeftNode;
};
struct Tree
{
    struct Node *root;
    char *name;
};

void addTree(struct Tree *tree, int data)
{

    if (tree->root == NULL)
    {
          printf("adding node in tree root %d \n", data);
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        tree->root = newNode;
        return;
    }
    struct Node *currentNode = malloc(sizeof(struct Node));

    currentNode = tree->root;

    while (1)
    {

        if (data < (currentNode->data))
        {
            if (currentNode->LeftNode == NULL)
            {
                struct Node *newNode = malloc(sizeof(struct Node));
                 newNode->data = data;
                currentNode->LeftNode = newNode;
                
              printf("adding node in  left tree %d \n", data);
                break;
            }
            currentNode = currentNode->LeftNode;
        }
        if (data > (currentNode->data))
        {

            if (currentNode->RightNode == NULL)
            {
                struct Node *newNode = malloc(sizeof(struct Node));
                   newNode->data = data;
                currentNode->RightNode = newNode;
                  printf("adding node in  right tree %d \n", data);
                break;
            }
            currentNode = currentNode->RightNode;
        }
    };
};
void printTree(struct Node* node){

    printf("data: %d \n",node->data);

    if(node->LeftNode != NULL)
        printTree(node->LeftNode);
    if(node->RightNode != NULL)
        printTree(node->RightNode);     

} 


int main()
{

    struct Tree *tree = malloc(sizeof(struct Tree));

   addTree(tree, 10 );
   addTree(tree, 20 );
   addTree(tree, 5 );
   printTree(tree->root);
   
}

