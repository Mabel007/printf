#include "main.h"

/**
 * isPrintable - Check if a character is printable
 * @c: Character to check
 *
 * Return: 1 if the character is printable, 0 otherwise
 */
int isPrintable(char c)
{
    if (c >= 32 && c < 127)
        return 1;

    return 0;
}

/**
 * appendHexaCode - Append ASCII in hexadecimal code to buffer
 * @buffer: Array of characters
 * @index: Index at which to start appending
 * @asciiCode: ASCII code to append
 *
 * Return: Always 3
 */
int appendHexaCode(char asciiCode, char buffer[], int index)
{
    const char hexMap[] = "0123456789ABCDEF";

    if (asciiCode < 0)
        asciiCode *= -1;

    buffer[index++] = '\\';
    buffer[index++] = 'x';

    buffer[index++] = hexMap[asciiCode / 16];
    buffer[index] = hexMap[asciiCode % 16];

    return 3;
}
