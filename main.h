#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct Format - Struct to store format and corresponding function
 * @format: The format character.
 * @function: The associated function.
 */
struct Format
{
    char format;
    int (*function)(va_list, char[], int, int, int, int);
};

typedef struct Format Format;

int _printf(const char *format, ...);
int handlePrint(const char *fmt, int *index, va_list args, char buffer[],
                int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

int printChar(va_list args, char buffer[], int flags, int width, int precision, int size);
int printString(va_list args, char buffer[], int flags, int width, int precision, int size);
int printPercent(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Functions to print numbers */
int printInt(va_list args, char buffer[], int flags, int width, int precision, int size);
int printBinary(va_list args, char buffer[], int flags, int width, int precision, int size);
int printUnsigned(va_list args, char buffer[], int flags, int width, int precision, int size);
int printOctal(va_list args, char buffer[], int flags, int width, int precision, int size);
int printHexadecimal(va_list args, char buffer[], int flags, int width, int precision, int size);
int printHexaUpper(va_list args, char buffer[], int flags, int width, int precision, int size);

int printHexa(va_list args, char map_to[], char buffer[], int flags,
              char flag_ch, int width, int precision, int size);

/* Function to print non-printable characters */
int printNonPrintable(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Function to print memory address */
int printPointer(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int getFlags(const char *format, int *index);
int getWidth(const char *format, int *index, va_list args);
int getPrecision(const char *format, int *index, va_list args);
int getSize(const char *format, int *index);

/* Function to print string in reverse */
int printReverse(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Function to print a string in rot 13 */
int printRot13String(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Width handler */
int handleWriteChar(char c, char buffer[], int flags, int width, int precision, int size);
int writeNumber(int is_positive, int index, char buffer[], int flags, int width,
                int precision, int size);
int writeNum(int index, char buffer[], int flags, int width, int precision,
             int length, char padding, char extra_c);
int writePointer(char buffer[], int index, int length, int width,
                 int flags, char padding, char extra_c, int padding_start);

int writeUnsigned(int is_negative, int index, char buffer[], int flags,
                  int width, int precision, int size);

/****************** UTILS ******************/
int isPrintable(char c);
int appendHexaCode(char c, char buffer[], int index);
int isDigit(char c);

long int convertSizeNumber(long int num, int size);
long int convertSizeUnsigned(unsigned long int num, int size);

#endif /* MAIN_H */

