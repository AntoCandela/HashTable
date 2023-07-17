#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data type
typedef struct data
{
    char name[20];
    char surname[20];
} DATA;

// Define my Linked List
typedef struct linkedList 
{
    DATA data;
    struct linkedList *next;
} LinkedList;

// Define my pointer to the first node of List
typedef LinkedList *LINK;

// Define the hash table

typedef struct hashTable
{
    int key;
    LINK value;
} HashTable;

// FUNCTIONS
// LINKED LIST
LINK createNode(DATA data);
void printLinkedList(LINK list);

// HASH TABLE
void initializeHashTable(int size, HashTable newHashTable[]);
void printHashTable(HashTable *hashTableToPrint, int size);
int simpleHashing(int keyValue, int tableSize);
void insertInTable(HashTable ht[], int tableSize, int keyValue, DATA data);

// EXCEPTION
void exception(char exceptionCode[]);
