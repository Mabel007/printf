#ifndef MAIN_H
#define MAIN_H

#include <stdrag.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* Defining all Flags to be used */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/*defining sizes */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
*struct Format - Struct to hold format specifiers and corresponding functions
*@specifier: the Format specifier
*@function: the function associated with specifier
*/
typedef struct Format{
  char specifier;
  int (*function)(va_list, char[],int, int, int, int);
} Format;
int _printf(const char *format, ...);
int handlePrint(const char *
fmt, int *ind,val_list list, char buffer[], int flags,int width, int precision, int size);
