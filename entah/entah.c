#include <stdio.h>
#include <stdlib.h>

struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
};

struct DNode *createDNode(int value)
{
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode -> data = value;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
};

void insertEndD(struct DNode **head, int value)
{
    struct DNode *temp = *head;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    struct DNode *temp = *head;
    while (temp -> next != NULL)
        temp = temp -> next;

    temp -> next = newNode; 
}

void printForward(struct DNode *head)
{
    printf("Forward: ");
    while (head != NULL)
    {
        printf("%d <-> ", head -> data);
        if (head > 0)
        {
            /* code */
        }
        
    }
    
};
