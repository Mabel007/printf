#include "main.h"

/**
 * handlePrint - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments
 * @index: Pointer to the index to traverse the format string
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specified in the format
 * @precision: Precision specified in the format
 * @size: Size specifier
 *
 * Return: Number of characters printed.
 */
int handlePrint(const char *fmt, int *index, va_list args, char buffer[],
                int flags, int width, int precision, int size)
{
    int i, unknownLength = 0, printedChars = -1;
    fmt_t fmtTypes[] = {
        {'c', printChar}, {'s', printString}, {'%', printPercent},
        {'i', printInt}, {'d', printInt}, {'b', printBinary},
        {'u', printUnsigned}, {'o', printOctal}, {'x', printHexadecimal},
        {'X', printHexaUpper}, {'p', printPointer}, {'S', printNonPrintable},
        {'r', printReverse}, {'R', printRot13String}, {'\0', NULL}
    };

    for (i = 0; fmtTypes[i].fmt != '\0'; i++)
        if (fmt[*index] == fmtTypes[i].fmt)
            return fmtTypes[i].fn(args, buffer, flags, width, precision, size);

    if (fmtTypes[i].fmt == '\0')
    {
        if (fmt[*index] == '\0')
            return -1;
        unknownLength += write(1, "%%", 1);
        if (fmt[*index - 1] == ' ')
            unknownLength += write(1, " ", 1);
        else if (width)
        {
            --(*index);
            while (fmt[*index] != ' ' && fmt[*index] != '%')
                --(*index);
            if (fmt[*index] == ' ')
                --(*index);
            return 1;
        }
        unknownLength += write(1, &fmt[*index], 1);
        return unknownLength;
    }
    return printedChars;
}
