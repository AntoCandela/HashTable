#include "header.h"


/*
 * Function: exception
 * -----------------------
 * Description:
 *   Handle various exceptions in code, given a exception code
 *
 * Parameters:
 *   exceptionCode [char*] : Data type and description of the first parameter.
 *
 * Returns:
 *   [VOID]
 *
 * Notes:
 *   NULL_POINTER -> a memory allocation has returned a NULL value, no allocation has been made
 */
void exception(char exceptionCode[])
{
    printf("\n\tEXCEPTION OF TYPE %s:\n", exceptionCode);

    if(strcmp(exceptionCode, "NULL_POINTER") == 0)
    {
        printf("Pointer has returned NULL!\n");
        return;
    }

    if(strcmp(exceptionCode, "DUPLICATED_KEY") == 0)
    {
        printf("You are trying to insert a value with a key that has been already used inside the table!\n");
        return;
    }

    if(strcmp(exceptionCode, "VALUE_NOT_FOUND") == 0)
    {
        printf("The value searched is not inside the table!\n");
        return;
    }

}