#include "source/header/header.h"

#define TABLE_SIZE 10

int main(void)
{
    HashTable ht[TABLE_SIZE];
    DATA data;

    initializeHashTable(TABLE_SIZE, ht);

    strcpy(data.name, "Antonio");
    strcpy(data.surname, "Candela");
    insertInTable(ht, TABLE_SIZE, 14, data);

    strcpy(data.name, "Gioele");
    strcpy(data.surname, "Ferrari");
    insertInTable(ht, TABLE_SIZE, 123, data);

    strcpy(data.name, "Patrizio");
    strcpy(data.surname, "Candela");
    insertInTable(ht, TABLE_SIZE, 24, data);

    strcpy(data.name, "Antonio");
    strcpy(data.surname, "Patria");
    insertInTable(ht, TABLE_SIZE, 4, data);

    strcpy(data.name, "Carmelo");
    strcpy(data.surname, "Patria");
    insertInTable(ht, TABLE_SIZE, 123, data);

    printHashTable(ht, TABLE_SIZE);
    printValueInHashTable(ht, TABLE_SIZE, 4);
    printf("\n%s %s\n", returnDataFromKey(ht, TABLE_SIZE, 24).name, returnDataFromKey(ht, TABLE_SIZE, 24).surname);

    return 0;
}