
/* Grammars

    program    -> stmt_list @
    stmt_list  -> stmt_list statement | statement
    statement  -> assignment | input id | output expression | expression
    assignment -> id = expression
    expression -> term | expresion add_op term
    term       -> factor | expression multi_op factor
    factor     -> number | id | expresion 
    add_op     -> + | -
    multi_op   -> * | /
*/

#ifndef Parser_h
#define Parser_h

#include <stdio.h>
#include "Scanner.h" //include Scanner.h when Scanner.c returns its Add/Div/EOF etc... 
//#include "Symbol_Table.h"

static void ExitWithSyntaxError() 
{
    printf("Syntax Error");
}

// List the Non Terminal methods that will be used in Parser.c
static void Program(void);
static void StatementList(void);
static void Statement(void);
static void ReadStatement(void);
static void WriteStatement(void);
static void AssignmentStatement(void);
static int Expression(void);
static int Term(void);
static int Factor(void);


#endif

