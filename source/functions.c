#include "header.h"

/*
 * Function: createNode
 * -----------------------
 * Description:
 *   Creates a new node for a LinkedList with its value-key pair, used in the hash table
 *
 * Parameters:
 *   data [DATA] : The data value to be insert in the node
 *   key  [int]  : The key associated with the data   
 *
 * Returns:
 *   [LINK] a pointer to a node of a linked list
 *
 * Notes:
 *   
 */
LINK createNode(DATA data, int key)
{
    LINK newNode = (LINK) malloc(sizeof(LinkedList));

    if(newNode == NULL)
    {
        exception("NULL_POINTER");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->key = key;
    return newNode;
}

/*
 * Function: printLinkedList
 * -----------------------
 * Description:
 *   prints a linked list with its key value followed by the data
 *
 * Parameters:
 *   list [LINK] : The Linked list to be printed
 *
 * Returns:
 *   [void]
 *
 * Notes:
 *   
 */
void printLinkedList(LINK list)
{
    while(list != NULL)
    {
        printf("[%03d][%s %s] --> ", list->key, list->data.name, list->data.surname);
        list = list->next;
    }
    printf("NULL");
}

/*
 * Function: initializeHashTable
 * -----------------------
 * Description:
 *   Initializes the HashTable to have all values pointing to NULL and in the case they are not NULL, they are freed
 *
 * Parameters:
 *   ht     [HashTable*] : The Hash table to be initialized
 *   size   [int] : The size of the hash table
 *
 * Returns:
 *   [void]
 *
 * Notes:
 *   This function can be used as well to free all the values in the hash table
 */
void initializeHashTable(HashTable ht[], int size)
{
    LINK previous;
    LINK current;

    for(int i = 0; i < size; i++)
    {
        if(ht[i].value != NULL)
        {
            previous = ht[i].value;
            current = ht[i].value->next;
            while(current != NULL)
            {
                free(previous);
                previous = current;
                current = current->next;
            }

        }
        
        ht[i].value = NULL;
    }

}

/*
 * Function: printHashTable
 * -----------------------
 * Description:
 *   Prints the Hash Table
 *
 * Parameters:
 *   ht     [HashTable*] : The Hash table to be printed
 *   size   [int] : The size of the hash table
 *
 * Returns:
 *   [void]
 *
 * Notes:
 *   
 */
void printHashTable(HashTable ht[], int size)
{
    printf("POSITION | KEY | VALUE \n");
    for(int i = 0; i < size; i++)
    {
        printf("[%d] :: ", i);
        printLinkedList(ht[i].value);
        printf("\n");
    }
}

/*
 * Function: hash
 * -----------------------
 * Description:
 *   Prints the Hash Table
 *
 * Parameters:
 *   key         [unsigned int] : The key value
 *   tableSize   [int] : The size of the hash table
 *
 * Returns:
 *   [unsigned int] the hashed key into a valid position inside the Hash Table (a position in the array)
 *
 * Notes:
 *   
 */
unsigned int hash(unsigned int key, int tableSize) 
{
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = (key >> 16) ^ key;
    return key % tableSize;
}

/*
 * Function: insertInTable
 * -----------------------
 * Description:
 *   Insert a new value in the Hash table given;
 *
 * Parameters:
 *   ht          [HashTable] : The Hash table where the data will be inserted into
 *   tableSize   [int] : The size of the hash table
 *   key         [unsigned int] : The key value
 *   data        [DATA] : The data value to be insert in the node
 * 
 * Returns:
 *   [void]
 *
 * Notes:
 *   If a collision occurs, the value will be inserted in the tail of the 
 *   linked list corresponding to the position of the hashed key 
 *   
 */
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

/*
 * Function: returnDataFromKey
 * -----------------------
 * Description:
 *   Fetch the data from the HashTable
 *
 * Parameters:
 *   ht          [HashTable] : The Hash table where the data will be fetched from
 *   tableSize   [int] : The size of the hash table
 *   key         [unsigned int] : The key value
 * 
 * Returns:
 *   [DATA]      A copy of the DATA value corresponding to the key given
 *
 * Notes:
 *   It only returns a copy of the data, modifing it won't affect the original Hash Table
 *   
 */
DATA returnDataFromKey(HashTable ht[], int tableSize, int key)
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