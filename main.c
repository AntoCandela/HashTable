#include "source/header.h"

#define TABLE_SIZE 10

int main(void)
{
    HashTable ht[TABLE_SIZE];
    DATA value;

    strcpy(value.name, "Antonio");
    strcpy(value.surname, "Candela");


    initializeHashTable(ht, TABLE_SIZE);

    insertInTable(ht, TABLE_SIZE, 123, value);
    insertInTable(ht, TABLE_SIZE, 321, value);
    insertInTable(ht, TABLE_SIZE, 100, value);
    insertInTable(ht, TABLE_SIZE, 230, value);
    insertInTable(ht, TABLE_SIZE, 230, value);

    printHashTable(ht, TABLE_SIZE);
    

    return 0;
}