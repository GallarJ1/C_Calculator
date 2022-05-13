


#ifndef Scanner_h
#define Scanner_h

#include <stdio.h>

typedef enum //typedef allows us to define data types and throws a token type to reference them, enum allows us to define those data types as only integers
{
    Id,                    // value 0 
    Read,                  // value 1
    Write,                 // value 2
    Numb,                // value 3
    Add = '+',             // ASCII value 43
    Sub = '-',             // ASCII value 45
    Multi = '*',           // ASCII value 42
    Div = '/',             // ASCII value 47
    Lparan = '(',          // ASCII value 40
    Rparan = ')',          // ASCII value 41
    AssignOP = '=',        // ASCII value 61
    EndOfStatement = ';',  // ASCII value 10
    EndOfFile = EOF,

}TokenType; //TokenType is the token name to reference andything inside the typedef 

typedef struct //struct allows anything inside to be defined so long as its defined 
{
    TokenType type; //type reference TokenType for example you could do type.TokenType to access Div or Add
    union //a struct inside of a struct which allows anything inside to likewise be inside of the same typedef
    {
        char name[100]; //max length is 100 characters
        int number;
    }value; // reference name and number using value 
}Token; //Reference value and type using Token 

TokenType GetNextTokenType(void);
Token GetNextToken(void);

#endif