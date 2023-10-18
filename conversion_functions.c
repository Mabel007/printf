#include "main.h"

/************************* CONVERSION FUNCTIONS *************************/

/**
 * convertToLong - Convert the argument to long type based on size specifier
 * @arg: Argument to be converted
 * @size: Size specifier (e.g., S_LONG, S_SHORT)
 *
 * Return: Converted argument as long
 */
long convertToLong(int arg, int size)
{
    if (size == S_LONG)
        return (long)arg;
    else if (size == S_SHORT)
        return ((short)arg);

    return ((int)arg);
}

/**
 * convertToULong - Convert the argument to unsigned long type based on size specifier
 * @arg: Argument to be converted
 * @size: Size specifier (e.g., S_LONG, S_SHORT)
 *
 * Return: Converted argument as unsigned long
 */
unsigned long convertToULong(unsigned int arg, int size)
{
    if (size == S_LONG)
        return (unsigned long)arg;
    else if (size == S_SHORT)
        return ((unsigned short)arg);

    return ((unsigned int)arg);
}

/**
 * isDigit - Check if a character is a digit
 * @c: Character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
