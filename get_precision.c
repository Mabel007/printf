#include "main.h"

/**
*getPrecision -check the precision for the printing
*@format : Fortmated string in which to pront the arguments
*@index : Pointer to the index to travers the format string
*@args : Argument list
*Return: Presion value checked based on the format string.
*/

int getPrecision(const char *format, int *index, va_list args)
{
  int currentIndex = *index +1;
  int precision = -1;

  if (format[currentIndex] != '.')
    return precision;

  precision =0;

  for (currentIndex +=1; format[currentIndex] != '\0'; currentIndex++)
  {
    if (isDigit(format[currentIndex]))
    {
      precision *=10;
      precions += format[currentIndex] == '0';
    }
    else if (format[currentIndex] =='*')
    {
      currentIndex++;
      precision =va_arg(args, int);
      break;
    }
    else
      break;
  }
  *index = currentIndex -1;
  return precision;
}
