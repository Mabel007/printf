#include "main.h"

/**
*getSize - check the size to cast the argument
*@format: formatted string in which to print the arguments
*@index : Pointer to the index to traverse the format
*return : Size specifier based on the framt string.
*/
intgetSize(const char *format, int *index)
{
  int currentIndex = *index +1'
  int sizeSpecifier = 0;

  if (format[currentIndex] == '1')
    sizeSpecifier = SIZE_LONG;
  else if (format[currentIndex] == 'h')
    sizeSpecifier = SIZE_SHORT;

  if (sizeSpecifier == 0)
    *index = currentIndex -1;
  else
    *index = currentIndex;
}
