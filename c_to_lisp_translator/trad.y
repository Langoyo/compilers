/*Carlos Gallego Jiménez Andrés Langoyo Martín GRUPO 12*/
/*100405937@alumnos.uc3m.es 100405869@alumnos.uc3m.es*/
%{                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata
char temp [2048] ;
char funcion_actual [2030];
char *mi_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
         fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
         fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
         exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}
char *genera_cadena (char *nombre)     // copia el argumento a un
{                                      // string en memoria dinamica
      char *p ;
      int l ;

      l = strlen (nombre)+1 ;
      p = (char *) mi_malloc (l) ;
      strcpy (p, nombre) ;

      return p ;
}



%}

%union {                      // El tipo de la pila tiene caracter dual
      int valor ;             // - valor numerico de un NUMERO
      char *cadena ;          // - para pasar los nombres de IDENTIFES
}

%token <valor> NUMERO         // Todos los token tienen un tipo para la pila
%token <cadena> IDENTIF       // Identificador=variable
%token <cadena> INTEGER       // identifica la definicion de un entero
%token <cadena> STRING
%token <cadena> MAIN          // identifica el comienzo del proc. main
%token <cadena> PUTS          // identifica el comienzo de una impresion de un literal  
%token <cadena> PRINTF        // identifica el comienzo de una impresion de una expresion 
%token <cadena> WHILE         // identifica el bucle 
%token <cadena> IF            // identifica la condicion if
%token <cadena> ELSE          // identifica la condicion else
%token <cadena> FOR           // identifica bucle for
%token <cadena> RETURN        // identifica palabra clave return
%token <cadena> OR            // identifica el operador '||'
%token <cadena> AND           // identifica el operador '&&'
%token <cadena> COMPARISON    // identifica el operador '=='
%token <cadena> DIFFERENCE    // identifica el operador '!='
%token <cadena> LESS_EQUAL    // identifica el operador '<='
%token <cadena> GREATER_EQUAL // identifica el operador '>='


%type   <cadena> retorno_sentencia ambito_anidado variables_ambito_multiple variables_ambito_asignacion variables_ambito retorno_funcion asignacion_multiple r_parametros_llamada parametros_llamada llamada_funcion cuerpo_funcion r_parametros parametros funciones expresion_aritm expresion_cond r_if r_else r_sentencia argumento imprimir_cadena v_multiple iniciar r_sentencias r_variables def_variables def_funciones v_asignacion v_global r_impresion impresion expresion termino operando sentencia axioma asignacion

%right '='                    // es la ultima operacion que se debe realizar
%left OR 
%left AND
%left COMPARISON DIFFERENCE
%left '>' '<' LESS_EQUAL GREATER_EQUAL 
%left '+' '-'                 // menor orden de precedencia
%left '*' '/' '%'             // orden de precedencia intermedio
%left SIGNO_UNARIO            // mayor orden de precedencia

%%
                                          // Seccion 3 Gramatica - Semantico

axioma:     def_variables  def_funciones   { printf ("%s %s\n(main)", $1, $2)  ;
                                                 sprintf (funcion_actual, "main"); } 
            ;
def_variables:/*lambda*/                   { sprintf (temp, "");
                                             $$ = genera_cadena (temp) ;}

            |   v_global ';' r_variables   { sprintf (temp, "%s \n%s ", $1, $3);
                                            $$ = genera_cadena (temp) ;}
            
            ;

r_variables: def_variables                { sprintf (temp, "%s", $1);
                                            $$ = genera_cadena (temp) ;}
            ;

def_funciones: funciones iniciar            { sprintf (temp, "%s \n%s", $1, $2);
                                            $$ = genera_cadena (temp) ;}
               ;
funciones: /*lambda*/                         { sprintf (temp, "");
                                             $$ = genera_cadena (temp) ;}
                                             
         | IDENTIF '('parametros')' '{' { sprintf (funcion_actual, "%s", $1);}
                                         cuerpo_funcion '}' funciones        
                                                                { sprintf (temp, "( defun %s (%s) \n%s \n)\n%s",$1,$3,$7,$9);
                                                                    $$ = genera_cadena (temp) ;}
        ;





// ambitos en una funcion ------------------------------------------------------------------------------------------------------------

variables_ambito: INTEGER IDENTIF variables_ambito_asignacion  variables_ambito_multiple           {sprintf (temp, "(let (( %s %s) %s",$2,$3,$4);
                                                                            $$ = genera_cadena (temp) ;
                                                            }
;
variables_ambito_asignacion:  /*lambda */                            { sprintf (temp, "0");
                                                      $$ = genera_cadena (temp);}
            | '=' expresion_aritm                              { sprintf (temp, "%s", $2);
                                                      $$ = genera_cadena (temp);}
            
    ;
variables_ambito_multiple:  /*lambda*/                              { sprintf (temp, "");
                                                      $$ = genera_cadena (temp) ; }
           | ',' IDENTIF variables_ambito_asignacion variables_ambito_multiple      { sprintf (temp, "( %s %s ) %s", $2, $3, $4);
                                                      $$ = genera_cadena (temp) ; }
            ;








cuerpo_funcion: r_sentencia cuerpo_funcion                 { sprintf (temp, "%s \n%s", $1, $2);
                                                            $$ = genera_cadena (temp) ;}
              |/*lambda*/                               { sprintf (temp, "");
                                                             $$ = genera_cadena (temp) ;}
            ;

retorno_funcion: ','expresion  retorno_funcion  { sprintf (temp, "%s %s", $2, $3);
                                                             $$ = genera_cadena (temp) ;}
                |  /*lambda*/                      { sprintf (temp, "");
                                             $$ = genera_cadena (temp) ;}
                  ;


parametros: INTEGER IDENTIF r_parametros         { if (strcmp("", $3) == 0){ 
                                                                    
                                                sprintf (temp, " %s ",$2);
                                                }
                                                else{
                                                    sprintf (temp, " %s %s ",$2, $3);
                                                }
                                                 $$ = genera_cadena (temp) ;}
                                                 
         | /*lambda*/                         { sprintf (temp, "");
                                             $$ = genera_cadena (temp) ;}
        ;

r_parametros: ',' parametros                  { sprintf (temp, "%s",$2);
                                             $$ = genera_cadena (temp) ;}
            | /*lambda*/                      { sprintf (temp, "");
                                             $$ = genera_cadena (temp) ;}
            ;
parametros_llamada: expresion r_parametros_llamada { if (strcmp("", $2) == 0){ 
                                                                    
                                                sprintf (temp, " %s ",$1);
                                                }
                                                else{
                                                    sprintf (temp, " %s %s ",$1, $2);
                                                }
                                                 $$ = genera_cadena (temp) ;}
                                                 
         | /*lambda*/                         { sprintf (temp, "");
                                             $$ = genera_cadena (temp) ;}
        ;
r_parametros_llamada: ',' parametros_llamada                  { sprintf (temp, "%s",$2);
                                             $$ = genera_cadena (temp) ;}
            | /*lambda*/                      { sprintf (temp, "");
                                             $$ = genera_cadena (temp) ;}
            ;
iniciar:    MAIN '('')' '{' r_sentencias '}'       { sprintf (temp, "(defun %s () \n %s\n)", $1, $5);
                                                  $$ = genera_cadena (temp) ;}
            ;

sentencia:      asignacion                      { $$ = $1; }
            |   impresion                       { $$ = $1; }
            |   v_global                        { $$ = $1; }
            |   imprimir_cadena                 { $$ = $1; }
            |   llamada_funcion                 { $$ = $1; }
            |   retorno_sentencia               { $$ = $1; }
            ;
retorno_sentencia:   RETURN  expresion retorno_funcion 
                                                      { if (strcmp("", $3) == 0){ 
                                                            sprintf (temp, "( return-from %s %s )\n",funcion_actual,$2);
                                                        }else{
                                                             sprintf (temp, "( return-from %s ( values %s %s ) )",funcion_actual,$2,$3);
                                                        }
                                                            $$ = genera_cadena (temp) ;}
            ;
ambito_anidado: '{'variables_ambito ';' r_sentencias'}' { sprintf (temp, "\n%s \n%s) ", $2, $4);
                                                        $$ = genera_cadena (temp) ;}


llamada_funcion: IDENTIF '('parametros_llamada')'        { sprintf (temp, "( %s %s )", $1, $3 );
                                                $$ = genera_cadena (temp) ;}
                    ;

r_sentencias: /*lambda*/                                                { sprintf (temp, "");
                                                                        $$ = genera_cadena (temp) ;}
            |sentencia ';' r_sentencias                                 { sprintf (temp, " %s \n %s", $1, $3);
                                                                        $$ = genera_cadena (temp) ;}
            | WHILE '('expresion_cond')' '{' r_sentencias '}' r_sentencias  { sprintf (temp, "( loop while %s do \n%s )\n%s", $3, $6, $8);
                                                                        $$ = genera_cadena (temp) ;}
            | IF '('expresion')' '{'r_sentencia r_sentencias '}' r_if    { if (strcmp("", $7) == 0){ 
                                                                            sprintf (temp, "( if %s \n%s %s", $3, $6, $9);
                                                                        }
                                                                        else{
                                                                            sprintf (temp, "( if %s \n( progn \n %s %s )\n %s", $3, $6, $7, $9);
                                                                             
                                                                            }

                                                                            $$ = genera_cadena (temp) ;}
                                                                            
           | FOR '('IDENTIF '=' expresion_aritm ';' expresion_cond ';' IDENTIF '=' expresion_aritm ')'
                '{' r_sentencias '}' r_sentencias  
                                                    { sprintf (temp, "( setq %s %s )\n( loop while %s do \n%s \n( setq %s %s )\n)\n%s ",$3, $5, $7, $14, $9, $11, $16); 
                                                                       $$ = genera_cadena (temp) ;}
            | ambito_anidado r_sentencias                               { sprintf (temp, " %s \n %s", $1, $2);
                                                                        $$ = genera_cadena (temp) ;}
                                                                        
            ;
r_sentencia:                                            
            sentencia ';'                                             { sprintf (temp, " %s \n", $1);
                                                                        $$ = genera_cadena (temp) ;}
            | WHILE '('expresion_cond')' '{' r_sentencias '}'               { sprintf (temp, "( loop while %s do \n%s )", $3, $6);
                                                                        $$ = genera_cadena (temp) ;}
            | IF '('expresion')' '{'r_sentencia r_sentencias '}' r_else    { if (strcmp("", $7) == 0){ 
                                                                            sprintf (temp, "( if %s \n%s \n%s", $3, $6, $9);
                                                                        }
                                                                        else{
                                                                            sprintf (temp, "( if %s \n( progn \n %s %s )\n %s", $3, $6, $7, $9);
                                                                            }
                                                                            $$ = genera_cadena (temp) ;}
             | FOR '('IDENTIF '=' expresion_aritm ';' expresion_cond ';' IDENTIF '=' expresion_aritm ')'
                '{' r_sentencias '}'  
                                                    { sprintf (temp, "( setq %s %s )\n( loop while %s do \n%s \n( setq %s %s )\n) ",$3, $5, $7, $14, $9, $11); 
                                                                       $$ = genera_cadena (temp) ;} 
             | ambito_anidado                                       {$$ = $1;}
             ;

r_if:       r_sentencias                                            { sprintf (temp, ") \n%s",$1); 
                                                                       $$ = genera_cadena (temp) ;}
            | ELSE '{'r_sentencia r_sentencias'}' r_sentencias      { if (strcmp("", $4) == 0){ 
                                                                            sprintf (temp, " %s ) \n%s", $3, $6);
                                                                        
                                                                    }
                                                                    else{
                                                                            sprintf (temp, "\n( progn \n %s %s )\n \n%s", $3, $4, $6);
                                                                             
                                                                    }
                                                                    $$ = genera_cadena (temp) ;}
            ;                          
r_else:     /*lambda*/                                               { sprintf (temp, ")"); 
                                                                        $$ = genera_cadena (temp) ;}
            | ELSE '{'r_sentencia r_sentencias'}'                   { if (strcmp("", $4) == 0){ 
                                                                            sprintf (temp, " %s )", $3);
                                                                        
                                                                    }
                                                                    else{
                                                                            sprintf (temp, "\n( progn \n %s %s )\n", $3, $4);
                                                                             
                                                                    }
                                                                    $$ = genera_cadena (temp) ;}
            ;

imprimir_cadena: PUTS '('STRING')'           {sprintf (temp, "( print \"%s\" )" ,$3);
                                                      $$ = genera_cadena (temp) ;}

v_global: INTEGER IDENTIF v_asignacion  v_multiple       { sprintf (temp, "( setq %s %s ) %s", $2, $3, $4);
                                                      $$ = genera_cadena (temp) ; }
            ;
v_asignacion:  /*lambda */                            { sprintf (temp, "0");
                                                      $$ = genera_cadena (temp);}
            | '=' expresion_aritm                              { sprintf (temp, "%s", $2);
                                                      $$ = genera_cadena (temp);}
            | '['expresion_aritm']'                            { sprintf (temp, "( make-array %s )", $2);
                                                      $$ = genera_cadena (temp);}
            ;
v_multiple :  /*lambda*/                              { sprintf (temp, "");
                                                      $$ = genera_cadena (temp) ; }
           | ',' IDENTIF v_asignacion v_multiple      { sprintf (temp, "( setq %s %s ) %s", $2, $3, $4);
                                                      $$ = genera_cadena (temp) ; }
            ;
impresion:      PRINTF '(' argumento                 {sprintf (temp, "%s" , $3 );
                                                      $$ = genera_cadena (temp) ;}
            ;    
argumento: expresion r_impresion                     {sprintf (temp, "( print %s ) %s" , $1, $2 );
                                                      $$ = genera_cadena (temp) ;}
            | STRING r_impresion                    {sprintf (temp, "%s" , $2 );
                                                      $$ = genera_cadena (temp) ;}
            ;

r_impresion: ',' argumento                         {sprintf (temp, "%s" , $2 );
                                                     $$ = genera_cadena (temp) ;}
            | ')'                                   {sprintf (temp, "");
                                                     $$ = genera_cadena (temp) ;}
            ;

 
asignacion: IDENTIF '=' expresion              { sprintf (temp, "( setq %s %s ) " , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            | IDENTIF '['expresion_aritm']' '=' expresion { sprintf (temp, "( setf ( aref %s %s ) %s) " , $1, $3, $6);
                                                  $$ = genera_cadena (temp) ; }
            |IDENTIF',' IDENTIF asignacion_multiple expresion ',' expresion  { sprintf (temp, "(setf ( values %s %s %s %s %s )) " , $1, $3, $4, $5, $7);
                                                                            $$ = genera_cadena (temp) ; }
            ;


      

asignacion_multiple: '='                                 { sprintf (temp, " ) (values ");
                                                         $$ = genera_cadena (temp) ; }
            | ',' IDENTIF asignacion_multiple expresion ','  { sprintf ( temp, "%s %s %s",$2, $3, $4 );
                                                         $$ = genera_cadena (temp) ; }        
            ;  

expresion:      termino					        { $$ = $1 ;}
            |   expresion '+' expresion   		{ sprintf (temp, "( + %s %s )", $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion '-' expresion   		{  sprintf (temp, "( - %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion '*' expresion   		{  sprintf (temp, "( * %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion '/' expresion   		{  sprintf (temp, "( / %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion '%' expresion         {  sprintf (temp, "( mod %s %s )" , $1, $3);
                                                $$ = genera_cadena (temp) ; }
            |   expresion '<' expresion   		{ sprintf (temp, "( < %s %s )", $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion '>' expresion   	{  sprintf (temp, "( > %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion LESS_EQUAL expresion  {  sprintf (temp, "( <= %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion GREATER_EQUAL expresion  {  sprintf (temp, "( >= %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion COMPARISON expresion  { sprintf (temp, "( = %s %s )", $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion DIFFERENCE expresion  {  sprintf (temp, "( /= %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion AND expresion   		{  sprintf (temp, "( AND %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion OR expresion   		{  sprintf (temp, "( OR %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            ;
expresion_aritm:    termino					        { $$ = $1 ;}
            | expresion '+' expresion   		{ sprintf (temp, "( + %s %s )", $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion '-' expresion   		{  sprintf (temp, "( - %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion '*' expresion   		{  sprintf (temp, "( * %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion '/' expresion   		{  sprintf (temp, "( / %s %s )" , $1, $3);
                                                    $$ = genera_cadena (temp) ; }
            |   expresion '%' expresion         {  sprintf (temp, "( mod %s %s )" , $1, $3);
                                                $$ = genera_cadena (temp) ; }
            ;

expresion_cond:  expresion '<' expresion   		{ sprintf (temp, "( < %s %s )", $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion '>' expresion   	{  sprintf (temp, "( > %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion LESS_EQUAL expresion  {  sprintf (temp, "( <= %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion GREATER_EQUAL expresion  {  sprintf (temp, "( >= %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion COMPARISON expresion  { sprintf (temp, "( = %s %s )", $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion DIFFERENCE expresion  {  sprintf (temp, "( //= %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion AND expresion   		{  sprintf (temp, "( AND %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            |   expresion OR expresion   		{  sprintf (temp, "( OR %s %s )" , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            ;

termino:        operando				            { $$ = $1; }                          
            |   '+' operando %prec SIGNO_UNARIO		{ sprintf (temp, "( + %s) ", $2 ); 
                                                      $$ = genera_cadena (temp) ;}
                                                      
            |   '-' operando %prec SIGNO_UNARIO		{ sprintf (temp, "( - %s) ", $2 ) ; 
                                                      $$ = genera_cadena (temp) ;}    
                                                    
                                                 
            ;

operando:       IDENTIF				{ sprintf (temp, "%s ", $1);

                                          $$ = genera_cadena (temp) ; }
            |   NUMERO					{ sprintf (temp, "%d ", $1);
                                          $$ = genera_cadena (temp);}
            |   '(' expresion ')'		{ sprintf (temp, " %s ", $2) ;
                                          $$ = genera_cadena (temp) ; }
            | llamada_funcion           {  $$ = $1; }

            | IDENTIF '['expresion_aritm']' { sprintf (temp, "( aref %s %s ) " , $1, $3);
                                                  $$ = genera_cadena (temp) ; }
            ;

%%
                            // SECCION 4    Codigo en C
int n_linea = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
    printf ( "\n") ;	// bye
}



/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_pal_reservadas { // para las palabras reservadas de C
    char *nombre ;
    int token ;
} t_reservada ;

t_reservada pal_reservadas [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "for",         FOR,
    "while",       WHILE,
    "puts",        PUTS,
    "printf",      PRINTF,
    "||",          OR,
    "&&",          AND,
    "==",          COMPARISON,
    "!=",          DIFFERENCE,
    "<=",          LESS_EQUAL, 
    ">=",          GREATER_EQUAL,
    "if",          IF,
    "else",        ELSE,
    "return",      RETURN,
    NULL,          0               // para marcar el fin de la tabla
} ;

t_reservada *busca_pal_reservada (char *nombre_simbolo)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_reservada *sim ;

    i = 0 ;
    sim = pal_reservadas ;
    while (sim [i].nombre != NULL) {
           if (strcmp (sim [i].nombre, nombre_simbolo) == 0) {
                                         // strcmp(a, b) devuelve == 0 si a==b
                 return &(sim [i]) ;
             }
           i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/


int yylex ()
{
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=>|%&+-/*" ;
    char cadena [256] ;
    t_reservada *simbolo ;

    do {
    	c = getchar () ;

		if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
			do {		//	OJO que puede funcionar mal si una linea contiene #
			 c = getchar () ;	
			} while (c != '\n') ;
		}
		
		if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
			cc = getchar () ;
			if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
				ungetc (cc, stdin) ;
		 } else {
		     c = getchar () ;	// ...
		     if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
		          do {		// Se trata de codigo inline (Codigo embebido en C)
		              c = getchar () ;
		              putchar (c) ;
		          } while (c != '\n') ;
		     } else {		// ==> comentario, ignorar la linea
		          while (c != '\n') {
		              c = getchar () ;
		          }
		     }
		 }
		}
		
		if (c == '\n')
		 n_linea++ ;
		
    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
         i = 0 ;
         do {
             c = getchar () ;
             cadena [i++] = c ;
         } while (c != '\"' && i < 255) ;
         if (i == 256) {
              printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_linea) ;
         }		 	// habria que leer hasta el siguiente " , pero, y si falta?
         cadena [--i] = '\0' ;
         yylval.cadena = genera_cadena (cadena) ;
         return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%d", &yylval.valor) ;
//         printf ("\nDEV: NUMERO %d\n", yylval.valor) ;        // PARA DEPURAR
         return NUMERO ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
         i = 0 ;
         while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
                 (c >= '0' && c <= '9') || c == '_') && i < 255) {
             cadena [i++] = tolower (c) ;
             c = getchar () ;
         }
         cadena [i] = '\0' ;
         ungetc (c, stdin) ;

         yylval.cadena = genera_cadena (cadena) ;
         simbolo = busca_pal_reservada (yylval.cadena) ;
         if (simbolo == NULL) {    // no es palabra reservada -> identificador 
//               printf ("\nDEV: IDENTIF %s\n", yylval.cadena) ;    // PARA DEPURAR
               return (IDENTIF) ;
         } else {
//               printf ("\nDEV: OTRO %s\n", yylval.cadena) ;       // PARA DEPURAR
               return (simbolo->token) ;
         }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
         cc = getchar () ;
         sprintf (cadena, "%c%c", (char) c, (char) cc) ;
         simbolo = busca_pal_reservada (cadena) ;
         if (simbolo == NULL) {
              ungetc (cc, stdin) ;
              yylval.cadena = NULL ;
              return (c) ;
         } else {
              yylval.cadena = genera_cadena (cadena) ; // aunque no se use
              return (simbolo->token) ;
         }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
         return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}

