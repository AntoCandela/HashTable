#include "source/header/header.h"

#define TABLE_SIZE 10

int main(void)
{
    HashTable ht[TABLE_SIZE];
    DATA data;

    initializeHashTable(TABLE_SIZE, ht);

    strcpy(data.name, "Antonio");
    strcpy(data.surname, "Candela");
    insertInTable(ht, TABLE_SIZE, 4, data);

    strcpy(data.name, "Gioele");
    strcpy(data.surname, "Ferrari");
    insertInTable(ht, TABLE_SIZE, 123, data);

    strcpy(data.name, "Luca");
    strcpy(data.surname, "Candela");
    insertInTable(ht, TABLE_SIZE, 4, data);

    strcpy(data.name, "Antonio");
    strcpy(data.surname, "Patria");
    insertInTable(ht, TABLE_SIZE, 4, data);

    printHashTable(ht, TABLE_SIZE);

    return 0;
}