


#include "Scanner.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>



char str[100]; //create a char array with max 100 characters




TokenType GetNextTokenType(void)
{
    static int c = ' '; //empty int to temp store characters
    int i = 0;

    /* skip white space */
    while (isspace(c)) //while its a whitespace get character make c equal it and pass to the next character
    {
        c = getchar();
    }

    if (c == ';') {   //If the character from getchar is equal to ; then return EndOfStatement
        return EndOfStatement; 
    }

    /* finds if letters */
    if (isalpha(c))  //if c is  alphanumeric  then do below
    {
        do {
            str[i++] = c; //add i to str for everytime c is a letter 

            if (i >= 100) { //however since we defined str to be max 100 if i is greater or equal to 100 printf
                printf("max token length exceeded\n");
            }

            c = getchar(); //get the next character
        } while (isalpha(c)); //do everything if and while its alphanumeric 

        /* finds input, output, or variable name */
        str[i] = '\0'; 
        if (strcmp(str, "input")) //compare str and input and if they match Return read, this is the keyword used instead of read
        {
            return Read;
        }
        else if (strcmp(str, "output")) //same as above comment however its output instead of Write
        {
            return Write;
        }
        else
            return Id; //if its neither assume its an id and return it
    }

    /* finds numbers */
    else if (isdigit(c)) //if c is a digit do below
    {
        do {
            str[i] = c; //store c into the array 
            i++; //increase its size everytime this is done by 1
            c = getchar(); // get the next character

        } while (isdigit(c)); //do above if and while its a digit

        str[i] = '\0';
        return Numb; //return Number

        /* finds arithmatic expressions */
    }
    else
        switch (c) { //switch case if the c equals and of the case symbols get the next characters and return something. 
            case '=':
                c = getchar();
                return AssignOP;
            case '+':
                c = getchar();
                return Add;
            case '-':
                c = getchar();
                return Sub;
            case '*':
                c = getchar();
                return Multi;
            case '/':
                c = getchar();
                return Div;
            case '(':
                 c = getchar();
                 return Lparan;
            case ')':
                c = getchar();
                return Rparan;
            case EOF:
                return EndOfFile;
            default:     //if its not a number, whitespace, a letter, or a special character in the case default and printf
                printf("Lexical Error");
                exit(1);
        }
}

Token GetNextToken(void) {
    Token t;
    t.type = GetNextTokenType();
    if (t.type == Id)
        strcpy(t.value.name, str);
    else if (t.type == Numb)
        t.value.number = atoi(str);

    return t;
}
