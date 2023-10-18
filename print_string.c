#include "main.h"

/**
 * print_string - Prints a string
 * @args: va_list containing the string to print
 * @buffer: Buffer array to handle print
 * @flags: Active formatting flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_string(va_list args, char buffer[], int flags, int width, int precision, int size)
{
    char *str = va_arg(args, char *);
    int str_len = 0;

    UNUSED(size);

    if (str == NULL)
        str = "(null)";

    str_len = string_length(str);

    if (precision >= 0 && precision < str_len)
        str_len = precision;

    if (width > str_len && !(flags & F_MINUS))
    {
        str_len += handle_width(buffer, width - str_len, flags, 0);
        buffer[str_len] = '\0';
        str_len = write(1, buffer, str_len);
    }
    else
    {
        str_len = write(1, str, str_len);
    }

    if (width > str_len && (flags & F_MINUS))
    {
        str_len += handle_width(buffer, width - str_len, flags, 0);
        buffer[str_len] = '\0';
        str_len = write(1, buffer, str_len);
    }

    return (str_len);
}
