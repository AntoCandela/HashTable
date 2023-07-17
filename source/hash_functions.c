#include "header/header.h"

void initializeHashTable(int size, HashTable newHashTable[])
{

    for(int i = 0; i < size; i++)
    {
        newHashTable[i].value = NULL;
    }

}

void printHashTable(HashTable *hashTableToPrint, int size)
{
    printf("KEY | VALUE \n");
    for(int i = 0; i < size; i++)
    {
        printf("[%d] :: ", i);
        printLinkedList(hashTableToPrint[i].value);
        printf("\n");
    }
}

int simpleHashing(int keyValue, int tableSize)
{
    return keyValue % tableSize;
}

void insertInTable(HashTable ht[], int tableSize, int keyValue, DATA data)
{
    keyValue = simpleHashing(keyValue, tableSize);

    LINK firstNode = NULL;

    if(ht[keyValue].value == NULL)
    {
        ht[keyValue].value = createNode(data);
        return;
    }

    firstNode = ht[keyValue].value;

    while(ht[keyValue].value->next != NULL)
    {
        ht[keyValue].value = ht[keyValue].value->next;
    }

    ht[keyValue].value->next = createNode(data);
    ht[keyValue].value = firstNode;
}