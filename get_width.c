#include "main.h"

/**
 * getWidth - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @index: Pointer to the index to traverse the format string
 * @argsList: Argument list
 *
 * Return: Width specified in the format string.
 */
int getWidth(const char *format, int *index, va_list argsList)
{
    int currentIndex;
    int width = 0;

    for (currentIndex = *index + 1; format[currentIndex] != '\0'; currentIndex++)
    {
        if (isDigit(format[currentIndex]))
        {
            width *= 10;
            width += format[currentIndex] - '0';
        }
        else if (format[currentIndex] == '*')
        {
            currentIndex++;
            width = va_arg(argsList, int);
            break;
        }
        else
            break;
    }

    *index = currentIndex - 1;

    return width;
}
