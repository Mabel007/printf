#include "main.h"
#include <limits.h>
#include <stdio.h>

int main(void) {
    int len;
    int len2;    
    len = _printf("here we go with the hello world.\n");
    len2 = printf("i think i made it.\n");
    
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    
    return 0;
}
