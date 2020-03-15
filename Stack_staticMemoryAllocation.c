#include <stdio.h>
#include <stdlib.h>
#define NULL ((void*)0)
#define MAX_SIZE 10
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node g_heap[MAX_SIZE] ;
int g_firstLocation = -1;
int g_endLocation = -1;

void insertNodeFromBegin(int x)
{
    struct Node newNode;
    newNode.data = x;
    newNode.next = NULL;
    if( (g_firstLocation-11)%MAX_SIZE == 0)
    {
        return;// the stack is full cant insert ins it
    }
    if(head == NULL)
    {
        g_firstLocation = MAX_SIZE-1;
        g_endLocation = MAX_SIZE-1;
        head = &newNode;
        g_heap[g_endLocation] = newNode;
        return;
    }
    else
    {
        g_firstLocation = (g_firstLocation - 1)%MAX_SIZE;
        g_heap[g_firstLocation] = newNode;
        g_heap[g_firstLocation].next = &g_heap[(g_firstLocation + 1)%MAX_SIZE];
    }
}

void removeNodeFromBegin(void)
{
    if(g_endLocation == -1 && g_firstLocation == -1)
    {
        return; // empty stack
    }
    else if(g_endLocation == MAX_SIZE - 1 && g_firstLocation == MAX_SIZE - 1)
    {
        // the stack becomes empty
        g_endLocation = -1;
        g_firstLocation = -1;
    }
    else
    {
        g_heap[g_firstLocation].next = NULL;
        g_firstLocation = (g_firstLocation + 1)%MAX_SIZE;
    }
}
void printStaticLinkedList(void)
{
    int size = (g_endLocation-g_firstLocation+MAX_SIZE+1)%(MAX_SIZE);
    int i = 0,index;
    for(i=0;i<size;i++)
    {
        index = (i + g_firstLocation)%(MAX_SIZE);
        printf("%d ",g_heap[index].data);
    }
    printf("\n");
}
int main()
{
    insertNodeFromBegin(4);
    insertNodeFromBegin(3);
    insertNodeFromBegin(2);
    insertNodeFromBegin(1);
    printStaticLinkedList();
    removeNodeFromBegin();
    printStaticLinkedList();
    return 0;
}

