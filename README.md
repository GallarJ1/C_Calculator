# C_Calculator
Using The Language Specifications below create a Calculator in C
1. The parser must be implemented as a Recursive Descent Parser
2. The scanner must be implemented with a function GetNextToken 
3. The types of tokens are declared as enums and tokens are a struct
4. The main function calls the parser. The translation is guided by the parser: it gets tokens from the scanner, parses them, and executes the statements. The principal components of the translator are: Main, Parser, and Scanner. 
5. To build Calc, issuing the command make should be enough. For that to work we need a Makefile
6. Implement function calls and definitions 
 
Lexical Rules:

Number → [0-9] [0-9]*
Keywords → Read | Write
Digit → 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
Assign → =
Mult_op →  mult | div
Add_op →  plus | minus
Div → /
Mult → *
Plus → +
minus → -
Identifier → letter (letter | digit)*
Letter →  a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z
End Of Statement → $

A number can be 0 to 9, followed  by more 0’s and/or positive numbers with the given 10 digits.

Read and Write are reserved as case sensitive keywords to perform specific operations. An identifier cannot be named “Read or Write” but can be named “read” or “write”.

Digit is used by number and ld. Its purpose is to specify the list of allowed digits in the given program. 

The Assignment operator is “ = “ , the division operator symbol is “ / “ , the addition operator symbol is “ + “, the subtraction operator symbol  is “ - “, the multiplication operator symbol  is “ * “ , and the end of statement symbol “ $ “ indicated no more tokens in the standard input. 

mult_op and add_op operators are plus,minus,div,mult which would include there stated symbols which would make the mult_op and add_op equal +,-,*, and /

The Identifier can be lowercase letters followed by either other letters or numbers. In letter only lowercase letters are defined therefore the Identifier will only allow lowercase letters. 


Syntactic Level: 

Program → stmt_list $
The program is built using the stmt_list
Stmt_list → stmt_list stmt
A statement list is itself and another statement and so on.. Meaning statements can keep being added to the list
Stmt_list → stmt
A statement list is built using a statement
Stmt → Identifier = expr | Read identifier | Write expr
Statement is a identifier assigned to an expression, a read identifier , an expression made using write 
Expr → term
An expression can be defined using a term
Expr → expr add_op term
An expression can be a plus or minus term
Term → factor 
A term can be defined using a factor
Term →  term mult_op factor 
A term multiplied by a factor is still a term
Factor → ( expr)
A factor can be an expression surrounded by parenthesis 
Factor → Identifier | Number
Factors are defined as numbers and saved as identifiers. 


















Semantic Level: 

Program → stmt_list $ 
A program is up by a statement list, or the user can enter the $ symbol to indicate the end of the statement. When the user gives standard input, the program will analyze the user's input from the statement list.

Stmt_list → stmt stmt_list 
A statement list can be a statement followed by a statement list, or just a statement by itself. 

Stmt_list → stmt
The first statement added will be used to create the start of a list of statements

Stmt → identifier = expr | Read identifier | Write expr 
A statement can be an expression assigned to an identifier, or an identifier following the keyword

Read, or an expression following the keyword Write,

Write – Write to standard output the value of evaluated expression. If the expression has not been assigned a value, there will be syntax error. 
Read – The identifier is being stored via standard input, where the identifier may or may be assigned to a value of a positive base 10 integer. Since “Read” and “Write” are reserved keywords, an identifier cannot be named “Read” or “Write”; if the identifier does not follow the correct lexical format, there will be syntax error.
Assignment operator (=) – Stores value of evaluated expression to the identifier.
Expr → term
All terms can be classified as expressions and will used to build statements for the program

Expr → expr add_op term 
An expression can be itself plus or minus a term

Term → Factor
All factors can be classified as a term by the program which will be used to build expressions 
Term → term mult_op factor 
A term can be built out of multiplying or dividing a term and a factor

Factor → (expr)
A factor can be considered an expression surrounded by parenthesis and that identifier will be used by the program to build terms

Factor → identifier | Number 
A factor can be an identifier or a number 




