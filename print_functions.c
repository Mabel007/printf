#include "main.h"

/************************* PRINT FUNCTIONS *************************/
/**
 * printChar - Print a character
 * @args: Arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int printChar(va_list args, char buffer[], int flags, int width, int precision, int size)
{
    int index = 0;
    char padding = ' ';

    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (flags & FLAG_ZERO)
        padding = '0';

    buffer[index++] = va_arg(args, int);
    buffer[index] = '\0';

    return (write(1, &buffer[0], 1));
}

/**
 * printString - Print a string
 * @args: Arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int printString(va_list args, char buffer[], int flags, int width, int precision, int size)
{
    int index = 0;
    char *str = va_arg(args, char *);
    int str_len = 0;
    char padding = ' ';

    UNUSED(precision);
    UNUSED(size);

    if (!str)
        str = "(null)";

    while (str[str_len])
        str_len++;

    if (flags & FLAG_ZERO)
        padding = '0';

    if (width > str_len)
    {
        for (index = 0; index < width - str_len; index++)
            buffer[index] = padding;

        buffer[index] = '\0';

        if (flags & FLAG_MINUS)
            return (write(1, str, str_len) + write(1, buffer, index));
        else
            return (write(1, buffer, index) + write(1, str, str_len));
    }

    buffer[index] = '\0';
    return (write(1, str, str_len));
}

/**
 * printPercent - Print a percent sign
 * @args: Arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Always 1 (number of characters printed)
 */
int printPercent(va_list args, char buffer[], int flags, int width, int precision, int size)
{
    UNUSED(args);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (flags & FLAG_ZERO)
        buffer[0] = '0';
    else
        buffer[0] = '%';

    buffer[1] = '\0';
    return (write(1, buffer, 1));
}
