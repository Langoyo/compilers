/*Carlos Gallego Jiménez Andrés Langoyo Martín GRUPO 12*/
/*100405937@alumnos.uc3m.es 100405869@alumnos.uc3m.es*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define T_NUMBER 1001
#define T_OP     1002		

int ParseExpression () ;		// Prototype for forward reference 

int token ;			// Here we store the current token/literal 
int number ;		// and the value of the number 

int line_counter = 1 ;


int rd_lex ()
{
	int c ;
	
	do {
		c = getchar () ;
	} while (c == ' ' || c == '\t') ;
	
	if (isdigit (c)){
		ungetc (c, stdin) ;
		scanf ("%d", &number) ;
		token = T_NUMBER ;
		return (token) ;	// returns the Token for Number
	}

	if (c == '\n')
		line_counter++ ;	// info for rd_syntax_error()
	
	token = c ;
	return (token);	// returns a literal
}


void rd_syntax_error (int expected, int token, char *output) 
{
	fprintf (stderr, "ERROR in line %d ", line_counter) ;
	fprintf (stderr, output, token, expected) ;
	
	exit (0);
}


void MatchSymbol (int expected_token)
{
	if (token != expected_token){
		rd_syntax_error (expected_token, token, "token %d expected, but %d was read") ;
	}
	rd_lex () ;
}


#define ParseLParen() 	MatchSymbol ('(') ; // More concise and efficient definitions
#define ParseRParen() 	MatchSymbol (')') ; // rather than using functions
											// This is only useful for matching Literals

int ParseNumber () 			// Parsing Non Terminals and some Tokens require more
{							// complex functions
	MatchSymbol (T_NUMBER) ;
	return number;
}


int ParseTerm () 		// T ::= N | ( E ) | + N | - N     returns the numeric value of the Term
{
	int val, operator ;

	

	if (token == T_NUMBER){		// T derives alternatives, requires checking FIRST ( E )
		return ParseNumber () ;
	} 	
	switch (token){			// This part is for the Semantic actions
		case '+' :
		case '-' :  operator=token ;
			    	break ;
		case '(':
				ParseLParen () ;
				val = ParseExpression () ;
				ParseRParen () ;
				return val;
		default :   rd_syntax_error (operator, 0, "Unexpected error in ParseExpressionRest for operator %c\n") ;
			    	break ;
	}
	rd_lex () ;
	val = ParseTerm ();
	switch (operator){			// This part is for the Semantic actions
		case '+' :
					break;
		case '-' :  val=-val ;
			    	break ;
		default :   rd_syntax_error (operator, 0, "Unexpected error in ParseExpressionRest for operator %c\n") ;
			    	break ;
	}
	return val;
}

int ParsePotencia()
{
	int val, val2,operator;
	val = ParseTerm();
	
	//      ParsePotencia () ;			// we expand this function into ParsePotencia()

	// Resto Potencia
	if (token == '\n' || token == ')' || token == '+' || token == '-' || token == '/' || token == '*' ){	// Therefore, we check FOLLOW(RestoPotencia)
		return val ;		// This means that lambda has been derived
	}

	if( token!='^'){
		 	rd_syntax_error (operator, 0, "Unexpected error in ParseExpressionRest for operator %c\n") ;
	}

	rd_lex () ;

	val2 = ParsePotencia();

	return pow(val,val2);
}

int ParseFactor () 			//F ::=Term RestoFactor
{
	int val, val2,operator;
	val = ParsePotencia();
	
	//      ParseRestoFactor () ;			// we expand this function into ParseFactor()

	// Resto factor
	if (token == '\n' || token == ')' || token == '+' || token == '-'){	// Therefore, we check FOLLOW(RestoFactor)
		return val ;		// This means that lambda has been derived
	}


	switch (token){			// This part is for the Semantic actions
		case '*' : 
		case '/' :  operator = token ;
			    	break ;
		default :   rd_syntax_error (operator, 0, "Unexpected error in ParseExpressionRest for operator %c\n") ;
			    	break ;
	}
	rd_lex () ;

	val2 = ParseFactor();
	
	switch(operator){
	case '*':	val *=val2;
				break;
	case '/':	val /=val2;
				break;
	default: rd_syntax_error (operator, 0, "Unexpected error in ParseExpressionRest for operator %c\n") ;
			    break ;
	}

	return val;

}
	

int ParseExpression () 		// E ::= TE' + E' ::= lambda | E 
{							// returns the numeric value of the Expression
	int val ;
	int val2 ;
	int operator ;

	val = ParseFactor () ;

//      ParseExpressionRest () ;			// we expand this function into ParseExpression()

											// ExpressionRest is a nullable Non Terminal
	if (token == '\n' || token == ')'){	// Therefore, we check FOLLOW(ExpressionRest)
		return val ;		// This means that lambda has been derived
	}

	switch (token){		// ExpressionRest derives in alternatives
		case '+' :  		// requires checking FIRST(ExpressionRest))
		case '-' :  operator = token ;
			    	break ;
		default :   rd_syntax_error (token, 0, "Token %d was read, but an Operator was expected");
			     	break ;
	}
	rd_lex () ;

	val2 = ParseExpression () ;
								// At this point the input has been parsed correctly
	switch (operator){			// This part is for the Semantic actions
		case '+' :  val += val2 ;
			    	break ;
		case '-' :  val -= val2 ;
			    	break ;
		default :   rd_syntax_error (operator, 0, "Unexpected error in ParseExpressionRest for operator %c\n") ;
			    	break ;
	}
	
	return val;
}


int main (void){

	while (1){
		rd_lex () ;
		printf ("Valor %d\n", ParseExpression ()) ;
	}	
	
	system ("PAUSE") ;
}

/*
Símbolos JFLP
E-> Expresion
R-> ExpressionRest
F->Factor
T-> Term
O-> RestoFactor
N -> Number
P-> Potencia
C-> RestoPotencia
S->Expression

parte 1 para añadir los factores
S->Expression

Expression ::= 
Factor ExpressionRest

ExpressionRest ::= 
+ Expression |
- Expression |
lambda

E ::= F + E 
F ::= P * F 
P::= T ^ P

Factor ::=
Term RestoFactor

RestoFactor ::=
* Factor
/ Factor
lambda

Term ::= 
Number |
( Expression )  |
+ Number |
- Number


Gramática 2 para potencias
E-> Expresion
R-> ExpressionRest
F->Factor
T-> Term
O-> RestoFactor
N -> Number
P-> Potencia
C-> RestoPotencia
S->Expression

Expresion ::= 
Factor ExpresionRest

ExpressionRest ::= 
+ Expression |
- Expression |
lambda

Factor ::=
Potencia RestoFactor

RestoFactor ::=
* Factor
/ Factor
lambda

1^3*2

Potencia ::=
Term RestoPotencia|

RestoPotencia ::=
^ Potencia |
lambda

Term ::= 
Number |
( Expression )  |
+ Number |
- Number


Gramática 3 para parentesis con signos y encadenar signos

Expresion ::= 
Factor ExpresionRest

ExpressionRest ::= 
+ Expression |
- Expression |
lambda

Factor ::=
Potencia RestoFactor

RestoFactor ::=
* Factor
/ Factor
lambda

1^3*2

Potencia ::=
Term RestoPotencia|

RestoPotencia ::=
^ Potencia |
lambda

Term ::= 
Number |
( Expression )  |
+ Term |
- Term


*/