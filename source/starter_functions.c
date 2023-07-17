#include "header/header.h"

LINK createNode(DATA data)
{
    LINK newNode = (LINK) malloc(sizeof(LinkedList));

    if(newNode == NULL)
    {
        exception("NULL_POINTER");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void printLinkedList(LINK list)
{
    while(list != NULL)
    {
        printf("%s %s --> ", list->data.name, list->data.surname);
        list = list->next;
    }
    printf("NULL");
}