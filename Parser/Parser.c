


#include "Parser.h"
#include <stdio.h>
#include <stdlib.h>

// Scanner
static Token CurrentToken;



/* Match Expected and Move ahead */
static void Match(TokenType expectedToken) 
{
    if (CurrentToken.type = expectedToken) //match the current token with the next expected token 
    {
        CurrentToken = GetNextToken();  //get the next token
        return;
    }

}

static void Program(void) //this is what the main calls 
{
    StatementList(); 
}

static void StatementList(void)
{
    CurrentToken = GetNextToken(); //Make the currenttoken = the next token aka get the next token

    while ( CurrentToken.type != EOF) //while that token isnt the EOF Token do statement 
    {
        Statement();
    }
}

static void Statement(void)
{
    switch (CurrentToken.type)
    {
        case Read:
            ReadStatement();
            //CurrentToken = GetNextToken();
            break;
        case Write:
            printf("Type: %u\n", CurrentToken.type);
            break;
        case Id: //if its an ID Assign() which basically saves the CurrentToken.type as an int, then Factor() where case: AssignOP match 
        // and then Expression it'll return value where we have the saved int = return value 
            break;
        case Lparan:
            Match(Lparan);
            break;
        case Rparan:
            Match(Rparan);
            break;
        case Numb:   
            printf("Value: %d\n", Expression());
            break;
        case EndOfStatement:
            //Match(EndOfStatement);
            break;
        case EndOfFile:
            break;
        default:
            printf("Type: %u\n", CurrentToken.type);
            ExitWithSyntaxError();
    }

}
 
//static void ReadStatement(void);
//static void WriteStatement(void);
static void ReadStatement(void) {

	printf("Here: %u\n");
	char name[100];
	int x;
	for(x= 0; x < 100; x++){

		if(GetNextTokenType() == Numb){

			CurrentToken = GetNextToken();
			name[x] = scanf("%c", CurrentToken.value);

			printf("Name: %u", name[x]);
			printf("Type: %u", CurrentToken.type);
		}else {
			break;
		}
	}


}

  



static int Expression(void)
{
    int value = Term();

    for (; CurrentToken.type == Add || CurrentToken.type == Sub; )
    {
        TokenType operator = CurrentToken.type;
        Match(operator);
        int rhs = Term();   // waits here for some reason
        if (operator == Add)
        {
            value += rhs;
        }
        else 
        {
            value -= rhs;
        }
    }

    return value;
}

static int Term(void)
{
    int value = Factor();

    for (; CurrentToken.type == Multi || CurrentToken.type == Div; )
    {
        TokenType operator = CurrentToken.type;
        Match(operator);
        int rhs = Factor();
        if (Multi == operator)
        {
            value *= rhs;
        }
        else 
            value /= rhs;
    }

    return value;
}

static int Factor(void)
{
    int value = 0;

    switch (CurrentToken.type)
    {
        case Lparan:
        {
            Match(Lparan);
            value = Expression();
            Match(Rparan);
            return value;
        }
        case Rparan:
        {
            Match(Rparan);
            break;
        }
        case Numb:
        {
            value = CurrentToken.value.number;  
            Match(Numb);
            return value;
        }     
        case Id:
        {
        }
            break;
        default:
            printf("Not a Factor");
        
    }

}
