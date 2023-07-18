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
    if(strcmp(exceptionCode, "NULL_POINTER") == 0)
    {
        printf("Pointer has returned NULL\n");
    }
}