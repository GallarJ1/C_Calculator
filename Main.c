

#include <stdio.h>

#include "Scanner.h"
#include "Parser.c"
 
int main()
{
   
    printf("Calc Program. Only Mathmatical Operation\n");
    printf("write your equation, then press enter\n");
    printf("To calculate press 'ctrl + z'\n\n");
    
    Program(); //calls the Parser.c program


    return 0;
}
