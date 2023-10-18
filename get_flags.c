#include "main.h"
/*
*getFlags - check active flags from the format string
*@format: formatted string to analyze for flags available
*@index:  index to track the current posisiton in the format string
*Return : flags check based on the format string.
*/

int getFlags(const char *format, int *index)
{
  const char FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
  const char FLAGS_ARRY[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO, FLAG_HASH, FLAG_SPACE, 0};
  int i, currentIndex;
  int flags = 0;

  for (currentIndex = *index + 1; format[currentIndex] != '\0'; currentIndex++)
  {
    for (i = 0; FLA_CHARS[i] != '\0'; i++)
    {
      if (format[currentIndex] == FLAG_CHARS[i])
      { 
	flags |= FLAG_ARRAY[i];
	break;
      }
    }
    if (FLAG_CHARS[i] ==0)
      break;
  }
  *index =currentIndex -1;
  return flags;
}
