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
    int key;
    struct linkedList *next;
} LinkedList;

// Define my pointer to the first node of List
typedef LinkedList *LINK;

// Define the hash table

typedef struct hashTable
{
    LINK value;
} HashTable;

// FUNCTIONS
// LINKED LIST
LINK createNode(DATA data, int key);
void printLinkedList(LINK list);

// HASH TABLE
void initializeHashTable(int size, HashTable newHashTable[]);
void printHashTable(HashTable *hashTableToPrint, int size);
int simpleHashing(int keyValue, int tableSize);
void insertInTable(HashTable ht[], int tableSize, int keyValue, DATA data);
void printValueInHashTable(HashTable *hashTableToPrint, int tableSize, int key);
DATA returnDataFromKey(HashTable *ht, int tableSize, int key);
// EXCEPTION
void exception(char exceptionCode[]);
