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
 *   Initializes the HashTable to have all values pointing to NULL
 *
 * Parameters:
 *   ht     [HashTable*] : The Hash table to be initialized
 *   size   [int] : The size of the hash table
 *
 * Returns:
 *   [void]
 *
 * Notes:
 *  
 */
void initializeHashTable(HashTable ht[], int size)
{
    for(int i = 0; i < size; i++)
        ht[i].value = NULL;
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

    // If the list has not been yet initialized, it is the first value in given key
    if(ht[keyValue].value == NULL)
    {
        ht[keyValue].value = createNode(data, key);
        return;
    }
    
    // There has been a collision, so I have to inset the data in the Linked list tail
    firstNode = ht[keyValue].value;

    // If the key is already in use, I cannot insert the value in table
    // I have the same control outside the while loop because if the linked List contains
    // only one value, it wouldn't check the first one as the condition is "ht[keyValue].value->next != NULL"
    if(key == ht[keyValue].value->key)
    {
        exception("DUPLICATED_KEY");
        ht[keyValue].value = firstNode;
        return;
    }

    while(ht[keyValue].value->next != NULL)
    {
        // If the key is already in use, I cannot insert the value in table
        if(key == ht[keyValue].value->key)
        {
            exception("DUPLICATED_KEY");
            ht[keyValue].value = firstNode;
            return;
        }
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

/*
 * Function: deleteByKey
 * -----------------------
 * Description:
 *   Fetch the data from the HashTable
 *
 * Parameters:
 *   ht          [HashTable] : The Hash table where the data will be deleted from
 *   tableSize   [int] : The size of the hash table
 *   key         [unsigned int] : The key value
 * 
 * Returns:
 *   [BOOLEAN]      True -> value found and deleted | False -> Value not deleted
 * Notes:
 *   
 */
Boolean deleteByKey(HashTable ht[], int tableSize, int key)
{
    int keyValue = hash(key, tableSize);
    Boolean found = False;
    LINK del = NULL;
    LINK firstNode = ht[keyValue].value;

    if(ht[keyValue].value == NULL)
        return False;
    
    // In case it is the first, I have to delete in head
    if(ht[keyValue].value->key == key)
    {   
        del = ht[keyValue].value;
        ht[keyValue].value = ht[keyValue].value->next;
        free(del);
        printf("Value deleted\n");
        found = True;

        if(!found)
        {
            exception("VALUE_NOT_FOUND");
        }   

        return found;
    }

    // Else I check inside the linked list
    while(!found && ht[keyValue].value->next != NULL)
    {
        if(ht[keyValue].value->next->key == key)
        {
            del = ht[keyValue].value->next;
            ht[keyValue].value->next = ht[keyValue].value->next->next;
            free(del);
            printf("Value deleted\n");
            found = True;
        }
        else
            ht[keyValue].value = ht[keyValue].value->next;
    }

    ht[keyValue].value = firstNode;

    if(!found)
    {
        exception("VALUE_NOT_FOUND");
    }

    return found;
}