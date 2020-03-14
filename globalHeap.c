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

void insertNodeFromEnd(int x)
{
    struct Node newNode;
    newNode.data = x;
    newNode.next = NULL;
    if( (g_endLocation+1)%MAX_SIZE == g_firstLocation)
    {
        return;// no space
    }
    if(head == NULL)
    {
        g_firstLocation = 0;
        g_endLocation = 0;
        head = &newNode;
        g_heap[g_endLocation] = newNode;
        g_endLocation ++;
        return;
    }
    else
    {
        g_heap[(g_endLocation)%MAX_SIZE] = newNode;
        g_endLocation =  (g_endLocation+1)%MAX_SIZE;
    }
}

void removeNodeFromBegin(void)
{
    if(g_endLocation == -1 && g_firstLocation == -1)
    {
        return;
    }
    else if(g_endLocation == 0 && g_firstLocation == 0)
    {
        g_endLocation = -1;
        g_firstLocation = -1;
    }
    else
    {
        g_firstLocation = (g_firstLocation + 1)%MAX_SIZE;
        head = &g_heap[g_firstLocation] ;
    }
}
void printStaticLinkedList(void)
{
    int size = (g_endLocation-g_firstLocation+MAX_SIZE)%(MAX_SIZE);
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
    insertNodeFromEnd(5);
    insertNodeFromEnd(4);
    insertNodeFromEnd(3);
    insertNodeFromEnd(2);
    insertNodeFromEnd(1);
    printStaticLinkedList();
    removeNodeFromBegin();
    printStaticLinkedList();
    return 0;
}

