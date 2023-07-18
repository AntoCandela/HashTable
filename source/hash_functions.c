#include "header/header.h"

void initializeHashTable(int size, HashTable newHashTable[])
{

    for(int i = 0; i < size; i++)
    {
        newHashTable[i].value = NULL;
    }

}

void printHashTable(HashTable *ht, int size)
{
    printf("POSITION | KEY | VALUE \n");
    for(int i = 0; i < size; i++)
    {
        printf("[%d] :: ", i);
        printLinkedList(ht[i].value);
        printf("\n");
    }
}

unsigned int simpleHash(unsigned int keyValue, int tableSize)
{
    return keyValue % tableSize;
}

// From stackoverflow, modified
unsigned int hash(unsigned int key, int tableSize) 
{
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = (key >> 16) ^ key;
    return key % tableSize;
}

void insertInTable(HashTable ht[], int tableSize, int key, DATA data)
{
    int keyValue = hash(key, tableSize);

    LINK firstNode = NULL;

    if(ht[keyValue].value == NULL)
    {
        ht[keyValue].value = createNode(data, key);
        return;
    }

    firstNode = ht[keyValue].value;

    while(ht[keyValue].value->next != NULL)
    {
        ht[keyValue].value = ht[keyValue].value->next;
    }

    ht[keyValue].value->next = createNode(data, key);
    ht[keyValue].value = firstNode;
}

void printValueInHashTable(HashTable *ht, int tableSize, int key)
{
    int keyValue = hash(key, tableSize);
    LINK firstNode = ht[keyValue].value;

    while(ht[keyValue].value->key != key)
    {
        ht[keyValue].value = ht[keyValue].value->next;
    }

    printf("\n%s %s\n", ht[keyValue].value->data.name, ht[keyValue].value->data.surname);
    ht[keyValue].value = firstNode;
}

DATA returnDataFromKey(HashTable *ht, int tableSize, int key)
{
    int keyValue = hash(key, tableSize);
    LINK firstNode = ht[keyValue].value;
    DATA returnValue;

    while(ht[keyValue].value->key != key)
    {
        ht[keyValue].value = ht[keyValue].value->next;
    }

    returnValue = ht[keyValue].value->data;
    ht[keyValue].value = firstNode;

    return returnValue;
}