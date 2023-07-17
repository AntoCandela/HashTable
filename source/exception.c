#include "header/header.h"

void exception(char exceptionCode[])
{
    if(strcmp(exceptionCode, "NULL_POINTER") == 0)
    {
        printf("Pointer has returned NULL\n");
    }
}