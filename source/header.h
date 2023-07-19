/* Header File: header.h
 *
 * Description:
 *   This header file contains all the definitions of structures that are used in files from project
 *
 */
#ifndef header
#define header

/*************************************************
******************* INCLUDES *********************
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************************************
******************* MACROS ***********************
**************************************************/

#define MAX_NAME 20
#define MAX_SURNAME 20

/*************************************************
************ STRUCTURE DEFINITIONS ***************
**************************************************/
/*
 * Typedef: boolean (enum)
 * -----------------------
 * Description:
 *  Define a boolean type of true or false.
 * 
 * Values:
 *   False -> 0
 *   True  -> 1
 * 
 * type:
 *   [Boolean]   
 * 
 * Notes:
 *   As c does not have a bool type by default it can be useful
 *
 */
typedef enum boolean {False, True} Boolean;

/*
 * Typedef: data
 * -----------------------
 * Description:
 *   Define data type, the values that are important for us
 * 
 * Values:
 *   name      [char*] : person's name, maximum length is MAX_NAME
 *   surname   [char*] : person's surname, maximum length is MAX_SURNAME
 * 
 * type:
 *   [DATA]   
 * 
 * Notes:
 *   
 */
typedef struct data
{
    char name[20];
    char surname[20];
} DATA;

/*
 * Typedef: linkedList
 * -----------------------
 * Description:
 *   Define my Linked list, which will be used to insert values one after the other for same hash values (collision)
 * 
 * Values:
 *   data      [DATA] : the important data
 *   key       [int]  : key paired with data
 *   next      [struct linkedList*] : pointer to next node
 * 
 * type:
 *   [LinkedList]   
 * 
 * Notes:
 *  A pointer for the Linked list is defined as [LINK]
 *   
 */
typedef struct linkedList 
{
    DATA data;
    int key;
    struct linkedList *next;
} LinkedList;
// Defines the pointer to a node of linked list
typedef LinkedList *LINK;

/*
 * Typedef: hashTable
 * -----------------------
 * Description:
 *   One entry in the Hash Table is a pointer to a Linked List
 * 
 * Values:
 *   value     [LINK] : pointer to a Linked list that contains the key | data
 * 
 * type:
 *   [HashTable]   
 * 
 * Notes:
 *   
 */
typedef struct hashTable
{
    LINK value;
} HashTable;

/*************************************************
************ DECLARATIONS ************************
**************************************************/
void exception(char exceptionCode[]);
LINK createNode(DATA data, int key);
void printLinkedList(LINK list);
void initializeHashTable(HashTable ht[], int size);
void printHashTable(HashTable ht[], int size);
unsigned int hash(unsigned int key, int tableSize);
void insertInTable(HashTable ht[], int tableSize, int key, DATA data);
DATA returnDataFromKey(HashTable ht[], int tableSize, int key);
Boolean deleteByKey(HashTable ht[], int tableSize, int key);

#endif