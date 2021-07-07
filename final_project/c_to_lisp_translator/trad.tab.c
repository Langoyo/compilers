/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "trad.y"
                          // SECCION 1 Declaraciones de C-Yacc

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




#line 113 "trad.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMERO = 258,
    IDENTIF = 259,
    INTEGER = 260,
    STRING = 261,
    MAIN = 262,
    PUTS = 263,
    PRINTF = 264,
    WHILE = 265,
    IF = 266,
    ELSE = 267,
    FOR = 268,
    RETURN = 269,
    OR = 270,
    AND = 271,
    COMPARISON = 272,
    DIFFERENCE = 273,
    LESS_EQUAL = 274,
    GREATER_EQUAL = 275,
    SIGNO_UNARIO = 276
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "trad.y"
                      // El tipo de la pila tiene caracter dual
      int valor ;             // - valor numerico de un NUMERO
      char *cadena ;          // - para pasar los nombres de IDENTIFES

#line 189 "trad.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

#define YYUNDEFTOK  2
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    28,     2,     2,
      31,    32,    26,    24,    35,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
      23,    21,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    88,    91,    96,   100,   103,   106,   106,
     118,   122,   124,   128,   130,   141,   143,   147,   149,   154,
     163,   167,   169,   172,   181,   184,   186,   189,   193,   194,
     195,   196,   197,   198,   200,   208,   212,   216,   218,   220,
     222,   232,   236,   241,   243,   245,   252,   256,   259,   261,
     271,   273,   284,   287,   290,   292,   294,   297,   299,   302,
     305,   307,   311,   313,   318,   320,   322,   329,   331,   335,
     336,   338,   340,   342,   344,   346,   348,   350,   352,   354,
     356,   358,   360,   363,   364,   366,   368,   370,   372,   376,
     378,   380,   382,   384,   386,   388,   390,   394,   395,   398,
     404,   407,   409,   411,   413
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO", "IDENTIF", "INTEGER", "STRING",
  "MAIN", "PUTS", "PRINTF", "WHILE", "IF", "ELSE", "FOR", "RETURN", "OR",
  "AND", "COMPARISON", "DIFFERENCE", "LESS_EQUAL", "GREATER_EQUAL", "'='",
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "SIGNO_UNARIO", "';'",
  "'('", "')'", "'{'", "'}'", "','", "'['", "']'", "$accept", "axioma",
  "def_variables", "r_variables", "def_funciones", "funciones", "$@1",
  "variables_ambito", "variables_ambito_asignacion",
  "variables_ambito_multiple", "cuerpo_funcion", "retorno_funcion",
  "parametros", "r_parametros", "parametros_llamada",
  "r_parametros_llamada", "iniciar", "sentencia", "retorno_sentencia",
  "ambito_anidado", "llamada_funcion", "r_sentencias", "r_sentencia",
  "r_if", "r_else", "imprimir_cadena", "v_global", "v_asignacion",
  "v_multiple", "impresion", "argumento", "r_impresion", "asignacion",
  "asignacion_multiple", "expresion", "expresion_aritm", "expresion_cond",
  "termino", "operando", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    61,    62,    60,    43,    45,    42,    47,    37,   276,
      59,    40,    41,   123,   125,    44,    91,    93
};
# endif

#define YYPACT_NINF (-198)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-96)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,    29,    37,    48,    49,    -8,  -198,    66,  -198,    83,
      26,    19,    19,    73,   100,    89,  -198,  -198,  -198,  -198,
      70,     5,     5,    19,  -198,   433,  -198,    63,  -198,    87,
     122,  -198,   124,    99,   102,    19,    19,  -198,  -198,   363,
    -198,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,  -198,    -8,   101,   104,   105,   110,
     307,   106,    19,    19,    19,    19,    19,  -198,   516,   528,
     538,   538,    44,    44,    44,    44,    59,    95,    72,   164,
     187,    73,   100,  -198,  -198,   258,  -198,    19,  -198,  -198,
      55,    55,  -198,  -198,  -198,  -198,  -198,   284,     3,   113,
     114,   115,   116,   117,    19,   146,   127,  -198,   258,  -198,
     126,  -198,  -198,  -198,  -198,  -198,   139,   144,   145,   134,
     128,  -198,   284,    19,   176,    19,   177,    42,    19,    19,
     188,   321,   189,   165,   258,  -198,  -198,    19,    19,   196,
      48,  -198,  -198,   447,     6,   166,   170,   -25,  -198,   286,
     461,   182,   381,   197,    19,  -198,   200,   258,  -198,   191,
     399,   207,  -198,  -198,   227,    19,   211,  -198,  -198,    42,
    -198,  -198,    19,    19,    19,    19,    19,    19,    19,    19,
     215,   216,    19,   321,    19,   198,   206,   218,   219,    19,
       6,   335,    19,  -198,   475,   415,   485,   499,   137,   183,
     543,   552,   258,   284,   214,  -198,  -198,   251,  -198,  -198,
     258,   284,   228,    19,    19,   447,   223,   258,    19,   200,
     230,   258,    19,   349,   447,   258,   231,   240,   198,  -198,
     239,   244,  -198,  -198,     7,   257,  -198,   264,   274,   246,
    -198,  -198,   259,   248,  -198,   261,   284,    19,   284,    19,
     258,   253,   258,   255,   262,   266,   273,   267,   258,   258,
    -198,   258,  -198,   281,   282,   258,  -198,  -198
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     7,     0,    54,     1,     0,     2,     0,
       3,     0,     0,    57,    20,     0,     6,     5,     4,   101,
     100,     0,     0,     0,   103,     0,    55,    69,    97,     0,
       0,    53,     0,     0,     0,    24,     0,    98,    99,     0,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    54,    22,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,   102,    82,    81,
      79,    80,    77,    78,    76,    75,    70,    71,    72,    73,
      74,    57,    20,    19,     8,    37,    36,    24,    23,   104,
      70,    71,    72,    73,    74,    58,    21,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    37,    32,
       0,    31,    30,    29,    28,    25,     0,     0,     0,     0,
       0,    47,    16,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,    37,    42,    27,     0,     0,     0,
       7,    43,    15,    64,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,    34,    11,    37,    38,     0,
       0,     0,     9,    67,     0,     0,     0,    52,    63,     0,
      61,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,    13,     0,     0,     0,     0,
       0,     0,     0,    62,    96,    81,    79,    80,    77,    78,
      76,    75,    37,     0,     0,    17,    12,     0,    10,    35,
      37,     0,     0,     0,     0,    65,     0,    37,     0,    11,
       0,    37,     0,     0,    66,    37,     0,     0,    13,    44,
       0,     0,    68,    39,    37,     0,    14,    50,     0,     0,
      48,    40,     0,     0,    45,     0,     0,     0,     0,     0,
      37,     0,    37,     0,     0,     0,     0,     0,    37,    37,
      51,    37,    49,     0,     0,    37,    46,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -198,  -198,   309,  -198,  -198,   180,  -198,  -198,   109,   174,
     270,   210,   312,  -198,   323,  -198,  -198,   -93,  -198,   -92,
      -5,    25,  -197,  -198,  -198,  -198,    32,   356,   331,  -198,
     260,   271,  -198,   238,    12,   -10,  -134,   -11,    91
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    18,     8,     9,    97,   133,   185,   208,
     119,   155,    33,    83,    59,    88,    16,   106,   107,   108,
      24,   110,   122,   241,   244,   111,   112,    13,    31,   113,
     148,   170,   114,   165,    25,    26,   151,    40,    28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    27,    29,   159,   120,   121,   217,   168,    19,    20,
     169,    98,     1,    11,   221,    99,   100,   101,   102,   239,
     103,   104,    19,    20,   123,    27,    61,   163,    12,   120,
     121,     1,     4,     5,    35,    39,    23,     6,   124,   125,
     105,   164,     4,    21,    22,    19,    20,    60,   147,   250,
      23,   252,     7,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    21,    22,    62,    63,
      64,    65,    66,    23,    90,    91,    92,    93,    94,    10,
     109,    64,    65,    66,   227,    64,    65,    66,   231,   -84,
      15,   -84,   109,   -83,   -84,   -83,   -84,    14,   -83,    60,
     -83,    35,   -86,   109,   -86,    32,    36,   -86,    30,   -86,
     120,   121,    37,    38,    27,   145,   131,   109,   120,   121,
      34,    64,    65,    66,    54,   -85,    55,   -85,    56,   109,
     -85,    57,   -85,   135,    58,   143,    82,    84,    85,   149,
     150,   152,    86,    89,   126,   127,   128,   129,   130,   150,
     160,   132,   109,   120,   121,   120,   121,   134,   141,   158,
     136,    62,    63,    64,    65,    66,   183,   -91,   140,   -91,
     137,    27,   204,    27,   206,   138,   139,   191,    27,   212,
     144,   149,   186,   146,   194,   195,   196,   197,   198,   199,
     200,   201,   153,   156,   -87,   157,   -87,   109,   109,   -87,
     161,   -87,   167,   166,   215,   109,   109,    62,    63,    64,
      65,    66,   109,   -92,   180,   -92,   109,   -88,   182,   -88,
     109,   184,   -88,   187,   -88,   223,   224,   216,   189,   109,
     150,   190,   192,   207,   150,   220,    27,   251,    27,   253,
     209,   109,   226,   109,   218,   109,   230,   109,   202,   203,
     233,   210,   211,   109,   109,   219,   109,   225,   222,   240,
     109,   242,    98,     1,   229,   234,    99,   100,   101,   102,
     235,   103,   104,   237,   238,   254,   243,   256,   245,   246,
     247,   248,   249,   262,   263,   255,   264,   257,    98,     1,
     267,   105,    99,   100,   116,   117,   258,   118,   104,   259,
     261,    41,    42,    43,    44,    45,    46,   260,    47,    48,
      62,    63,    64,    65,    66,   265,   266,   105,   168,    17,
     162,   169,    41,    42,    43,    44,    45,    46,   228,    47,
      48,    62,    63,    64,    65,    66,    41,    42,    43,    44,
      45,    46,    87,    47,    48,    62,    63,    64,    65,    66,
      41,    42,    43,    44,    45,    46,   154,    47,    48,    62,
      63,    64,    65,    66,    41,    42,    43,    44,    45,    46,
     214,    47,    48,    62,    63,    64,    65,    66,    41,    42,
      43,    44,    45,    46,   232,    47,    48,    62,    63,    64,
      65,    66,   142,   205,    96,    67,    41,    42,    43,    44,
      45,    46,   236,    47,    48,    62,    63,    64,    65,    66,
     115,    81,    95,   181,    41,    42,    43,    44,    45,    46,
     171,    47,    48,    62,    63,    64,    65,    66,   213,   193,
       0,   188,    43,    44,    45,    46,     0,    47,    48,    62,
      63,    64,    65,    66,     0,   -95,     0,   -95,    41,    42,
      43,    44,    45,    46,     0,    47,    48,    49,    50,    51,
      52,    53,    41,    42,    43,    44,    45,    46,     0,    47,
      48,    62,    63,    64,    65,    66,   172,   173,   174,   175,
     176,   177,     0,   178,   179,    62,    63,    64,    65,    66,
     -82,    42,    43,    44,    45,    46,     0,    47,    48,    62,
      63,    64,    65,    66,    45,    46,     0,    47,    48,    62,
      63,    64,    65,    66,     0,   -93,     0,   -93,    45,    46,
       0,    47,    48,    62,    63,    64,    65,    66,     0,   -94,
       0,   -94,    42,    43,    44,    45,    46,     0,    47,    48,
      62,    63,    64,    65,    66,    43,    44,    45,    46,     0,
      47,    48,    62,    63,    64,    65,    66,    45,    46,     0,
      47,    48,    62,    63,    64,    65,    66,    62,    63,    64,
      65,    66,     0,   -90,     0,   -90,    62,    63,    64,    65,
      66,     0,   -89,     0,   -89
};

static const yytype_int16 yycheck[] =
{
      11,    12,    12,   137,    97,    97,   203,    32,     3,     4,
      35,     4,     5,    21,   211,     8,     9,    10,    11,    12,
      13,    14,     3,     4,    21,    36,    36,    21,    36,   122,
     122,     5,     0,     4,    31,    23,    31,     0,    35,    36,
      33,    35,    10,    24,    25,     3,     4,    35,     6,   246,
      31,   248,     4,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    24,    25,    24,    25,
      26,    27,    28,    31,    62,    63,    64,    65,    66,    30,
      85,    26,    27,    28,   218,    26,    27,    28,   222,    30,
       7,    32,    97,    30,    35,    32,    37,    31,    35,    87,
      37,    31,    30,   108,    32,     5,    36,    35,    35,    37,
     203,   203,    21,    22,   125,   125,   104,   122,   211,   211,
      31,    26,    27,    28,    37,    30,     4,    32,     4,   134,
      35,    32,    37,   108,    32,   123,    35,    33,    33,   127,
     128,   129,    32,    37,    31,    31,    31,    31,    31,   137,
     138,     5,   157,   246,   246,   248,   248,    30,    30,   134,
      34,    24,    25,    26,    27,    28,   154,    30,    34,    32,
      31,   182,   182,   184,   184,    31,    31,   165,   189,   189,
       4,   169,   157,     6,   172,   173,   174,   175,   176,   177,
     178,   179,     4,     4,    30,    30,    32,   202,   203,    35,
       4,    37,    32,    37,   192,   210,   211,    24,    25,    26,
      27,    28,   217,    30,    32,    32,   221,    30,    21,    32,
     225,    21,    35,    32,    37,   213,   214,   202,    21,   234,
     218,     4,    21,    35,   222,   210,   247,   247,   249,   249,
      34,   246,   217,   248,    30,   250,   221,   252,    33,    33,
     225,    33,    33,   258,   259,     4,   261,    34,    30,   234,
     265,     4,     4,     5,    34,    34,     8,     9,    10,    11,
      30,    13,    14,    34,    30,   250,    12,   252,     4,    33,
      21,    33,    21,   258,   259,    32,   261,    32,     4,     5,
     265,    33,     8,     9,    10,    11,    34,    13,    14,    33,
      33,    15,    16,    17,    18,    19,    20,    34,    22,    23,
      24,    25,    26,    27,    28,    34,    34,    33,    32,    10,
     140,    35,    15,    16,    17,    18,    19,    20,   219,    22,
      23,    24,    25,    26,    27,    28,    15,    16,    17,    18,
      19,    20,    35,    22,    23,    24,    25,    26,    27,    28,
      15,    16,    17,    18,    19,    20,    35,    22,    23,    24,
      25,    26,    27,    28,    15,    16,    17,    18,    19,    20,
      35,    22,    23,    24,    25,    26,    27,    28,    15,    16,
      17,    18,    19,    20,    35,    22,    23,    24,    25,    26,
      27,    28,   122,   183,    82,    32,    15,    16,    17,    18,
      19,    20,   228,    22,    23,    24,    25,    26,    27,    28,
      87,    55,    81,    32,    15,    16,    17,    18,    19,    20,
     149,    22,    23,    24,    25,    26,    27,    28,   190,   169,
      -1,    32,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    32,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    32,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    32,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    28,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    28,    24,    25,    26,
      27,    28,    -1,    30,    -1,    32,    24,    25,    26,    27,
      28,    -1,    30,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    39,    40,    64,     4,     0,     4,    42,    43,
      30,    21,    36,    65,    31,     7,    54,    40,    41,     3,
       4,    24,    25,    31,    58,    72,    73,    75,    76,    73,
      35,    66,     5,    50,    31,    31,    36,    76,    76,    72,
      75,    15,    16,    17,    18,    19,    20,    22,    23,    24,
      25,    26,    27,    28,    37,     4,     4,    32,    32,    52,
      72,    73,    24,    25,    26,    27,    28,    32,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    65,    35,    51,    33,    33,    32,    35,    53,    37,
      72,    72,    72,    72,    72,    66,    50,    44,     4,     8,
       9,    10,    11,    13,    14,    33,    55,    56,    57,    58,
      59,    63,    64,    67,    70,    52,    10,    11,    13,    48,
      55,    57,    60,    21,    35,    36,    31,    31,    31,    31,
      31,    72,     5,    45,    30,    59,    34,    31,    31,    31,
      34,    30,    48,    72,     4,    73,     6,     6,    68,    72,
      72,    74,    72,     4,    35,    49,     4,    30,    59,    74,
      72,     4,    43,    21,    35,    71,    37,    32,    32,    35,
      69,    69,    15,    16,    17,    18,    19,    20,    22,    23,
      32,    32,    21,    72,    21,    46,    59,    32,    32,    21,
       4,    72,    21,    68,    72,    72,    72,    72,    72,    72,
      72,    72,    33,    33,    73,    49,    73,    35,    47,    34,
      33,    33,    73,    71,    35,    72,    59,    60,    30,     4,
      59,    60,    30,    72,    72,    34,    59,    74,    46,    34,
      59,    74,    35,    59,    34,    30,    47,    34,    30,    12,
      59,    61,     4,    12,    62,     4,    33,    21,    33,    21,
      60,    73,    60,    73,    59,    32,    59,    32,    34,    33,
      34,    33,    59,    59,    59,    34,    34,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    42,    43,    44,    43,
      45,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    55,    55,
      55,    55,    55,    55,    56,    57,    58,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    64,    65,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    70,    70,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    75,
      76,    76,    76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     3,     1,     2,     0,     0,     9,
       4,     0,     2,     0,     4,     2,     0,     3,     0,     3,
       0,     2,     0,     2,     0,     2,     0,     6,     1,     1,
       1,     1,     1,     1,     3,     5,     4,     0,     3,     8,
       9,    16,     2,     2,     7,     9,    15,     1,     1,     6,
       0,     5,     4,     4,     0,     2,     3,     0,     4,     3,
       2,     2,     2,     1,     3,     6,     7,     1,     5,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     2,     2,
       1,     1,     3,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 85 "trad.y"
                                           { printf ("%s %s\n(main)", (yyvsp[-1].cadena), (yyvsp[0].cadena))  ;
                                                 sprintf (funcion_actual, "main"); }
#line 1600 "trad.tab.c"
    break;

  case 3:
#line 88 "trad.y"
                                           { sprintf (temp, "");
                                             (yyval.cadena) = genera_cadena (temp) ;}
#line 1607 "trad.tab.c"
    break;

  case 4:
#line 91 "trad.y"
                                           { sprintf (temp, "%s \n%s ", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1614 "trad.tab.c"
    break;

  case 5:
#line 96 "trad.y"
                                          { sprintf (temp, "%s", (yyvsp[0].cadena));
                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1621 "trad.tab.c"
    break;

  case 6:
#line 100 "trad.y"
                                            { sprintf (temp, "%s \n%s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1628 "trad.tab.c"
    break;

  case 7:
#line 103 "trad.y"
                                              { sprintf (temp, "");
                                             (yyval.cadena) = genera_cadena (temp) ;}
#line 1635 "trad.tab.c"
    break;

  case 8:
#line 106 "trad.y"
                                        { sprintf (funcion_actual, "%s", (yyvsp[-4].cadena));}
#line 1641 "trad.tab.c"
    break;

  case 9:
#line 108 "trad.y"
                                                                { sprintf (temp, "( defun %s (%s) \n%s \n)\n%s",(yyvsp[-8].cadena),(yyvsp[-6].cadena),(yyvsp[-2].cadena),(yyvsp[0].cadena));
                                                                    (yyval.cadena) = genera_cadena (temp) ;}
#line 1648 "trad.tab.c"
    break;

  case 10:
#line 118 "trad.y"
                                                                                                   {sprintf (temp, "(let (( %s %s) %s",(yyvsp[-2].cadena),(yyvsp[-1].cadena),(yyvsp[0].cadena));
                                                                            (yyval.cadena) = genera_cadena (temp) ;
                                                            }
#line 1656 "trad.tab.c"
    break;

  case 11:
#line 122 "trad.y"
                                                                     { sprintf (temp, "0");
                                                      (yyval.cadena) = genera_cadena (temp);}
#line 1663 "trad.tab.c"
    break;

  case 12:
#line 124 "trad.y"
                                                               { sprintf (temp, "%s", (yyvsp[0].cadena));
                                                      (yyval.cadena) = genera_cadena (temp);}
#line 1670 "trad.tab.c"
    break;

  case 13:
#line 128 "trad.y"
                                                                    { sprintf (temp, "");
                                                      (yyval.cadena) = genera_cadena (temp) ; }
#line 1677 "trad.tab.c"
    break;

  case 14:
#line 130 "trad.y"
                                                                                    { sprintf (temp, "( %s %s ) %s", (yyvsp[-2].cadena), (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                      (yyval.cadena) = genera_cadena (temp) ; }
#line 1684 "trad.tab.c"
    break;

  case 15:
#line 141 "trad.y"
                                                           { sprintf (temp, "%s \n%s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1691 "trad.tab.c"
    break;

  case 16:
#line 143 "trad.y"
                                                        { sprintf (temp, "");
                                                             (yyval.cadena) = genera_cadena (temp) ;}
#line 1698 "trad.tab.c"
    break;

  case 17:
#line 147 "trad.y"
                                                { sprintf (temp, "%s %s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                             (yyval.cadena) = genera_cadena (temp) ;}
#line 1705 "trad.tab.c"
    break;

  case 18:
#line 149 "trad.y"
                                                   { sprintf (temp, "");
                                             (yyval.cadena) = genera_cadena (temp) ;}
#line 1712 "trad.tab.c"
    break;

  case 19:
#line 154 "trad.y"
                                                 { if (strcmp("", (yyvsp[0].cadena)) == 0){ 
                                                                    
                                                sprintf (temp, " %s ",(yyvsp[-1].cadena));
                                                }
                                                else{
                                                    sprintf (temp, " %s %s ",(yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                }
                                                 (yyval.cadena) = genera_cadena (temp) ;}
#line 1725 "trad.tab.c"
    break;

  case 20:
#line 163 "trad.y"
                                              { sprintf (temp, "");
                                             (yyval.cadena) = genera_cadena (temp) ;}
#line 1732 "trad.tab.c"
    break;

  case 21:
#line 167 "trad.y"
                                              { sprintf (temp, "%s",(yyvsp[0].cadena));
                                             (yyval.cadena) = genera_cadena (temp) ;}
#line 1739 "trad.tab.c"
    break;

  case 22:
#line 169 "trad.y"
                                              { sprintf (temp, "");
                                             (yyval.cadena) = genera_cadena (temp) ;}
#line 1746 "trad.tab.c"
    break;

  case 23:
#line 172 "trad.y"
                                                   { if (strcmp("", (yyvsp[0].cadena)) == 0){ 
                                                                    
                                                sprintf (temp, " %s ",(yyvsp[-1].cadena));
                                                }
                                                else{
                                                    sprintf (temp, " %s %s ",(yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                }
                                                 (yyval.cadena) = genera_cadena (temp) ;}
#line 1759 "trad.tab.c"
    break;

  case 24:
#line 181 "trad.y"
                                              { sprintf (temp, "");
                                             (yyval.cadena) = genera_cadena (temp) ;}
#line 1766 "trad.tab.c"
    break;

  case 25:
#line 184 "trad.y"
                                                              { sprintf (temp, "%s",(yyvsp[0].cadena));
                                             (yyval.cadena) = genera_cadena (temp) ;}
#line 1773 "trad.tab.c"
    break;

  case 26:
#line 186 "trad.y"
                                              { sprintf (temp, "");
                                             (yyval.cadena) = genera_cadena (temp) ;}
#line 1780 "trad.tab.c"
    break;

  case 27:
#line 189 "trad.y"
                                                   { sprintf (temp, "(defun %s () \n %s\n)", (yyvsp[-5].cadena), (yyvsp[-1].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ;}
#line 1787 "trad.tab.c"
    break;

  case 28:
#line 193 "trad.y"
                                                { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1793 "trad.tab.c"
    break;

  case 29:
#line 194 "trad.y"
                                                { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1799 "trad.tab.c"
    break;

  case 30:
#line 195 "trad.y"
                                                { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1805 "trad.tab.c"
    break;

  case 31:
#line 196 "trad.y"
                                                { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1811 "trad.tab.c"
    break;

  case 32:
#line 197 "trad.y"
                                                { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1817 "trad.tab.c"
    break;

  case 33:
#line 198 "trad.y"
                                                { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1823 "trad.tab.c"
    break;

  case 34:
#line 201 "trad.y"
                                                      { if (strcmp("", (yyvsp[0].cadena)) == 0){ 
                                                            sprintf (temp, "( return-from %s %s )\n",funcion_actual,(yyvsp[-1].cadena));
                                                        }else{
                                                             sprintf (temp, "( return-from %s ( values %s %s ) )",funcion_actual,(yyvsp[-1].cadena),(yyvsp[0].cadena));
                                                        }
                                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1834 "trad.tab.c"
    break;

  case 35:
#line 208 "trad.y"
                                                        { sprintf (temp, "\n%s \n%s) ", (yyvsp[-3].cadena), (yyvsp[-1].cadena));
                                                        (yyval.cadena) = genera_cadena (temp) ;}
#line 1841 "trad.tab.c"
    break;

  case 36:
#line 212 "trad.y"
                                                         { sprintf (temp, "( %s %s )", (yyvsp[-3].cadena), (yyvsp[-1].cadena) );
                                                (yyval.cadena) = genera_cadena (temp) ;}
#line 1848 "trad.tab.c"
    break;

  case 37:
#line 216 "trad.y"
                                                                        { sprintf (temp, "");
                                                                        (yyval.cadena) = genera_cadena (temp) ;}
#line 1855 "trad.tab.c"
    break;

  case 38:
#line 218 "trad.y"
                                                                        { sprintf (temp, " %s \n %s", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                                        (yyval.cadena) = genera_cadena (temp) ;}
#line 1862 "trad.tab.c"
    break;

  case 39:
#line 220 "trad.y"
                                                                            { sprintf (temp, "( loop while %s do \n%s )\n%s", (yyvsp[-5].cadena), (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                                        (yyval.cadena) = genera_cadena (temp) ;}
#line 1869 "trad.tab.c"
    break;

  case 40:
#line 222 "trad.y"
                                                                         { if (strcmp("", (yyvsp[-2].cadena)) == 0){ 
                                                                            sprintf (temp, "( if %s \n%s %s", (yyvsp[-6].cadena), (yyvsp[-3].cadena), (yyvsp[0].cadena));
                                                                        }
                                                                        else{
                                                                            sprintf (temp, "( if %s \n( progn \n %s %s )\n %s", (yyvsp[-6].cadena), (yyvsp[-3].cadena), (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                                             
                                                                            }

                                                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1883 "trad.tab.c"
    break;

  case 41:
#line 234 "trad.y"
                                                    { sprintf (temp, "( setq %s %s )\n( loop while %s do \n%s \n( setq %s %s )\n)\n%s ",(yyvsp[-13].cadena), (yyvsp[-11].cadena), (yyvsp[-9].cadena), (yyvsp[-2].cadena), (yyvsp[-7].cadena), (yyvsp[-5].cadena), (yyvsp[0].cadena)); 
                                                                       (yyval.cadena) = genera_cadena (temp) ;}
#line 1890 "trad.tab.c"
    break;

  case 42:
#line 236 "trad.y"
                                                                        { sprintf (temp, " %s \n %s", (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                                        (yyval.cadena) = genera_cadena (temp) ;}
#line 1897 "trad.tab.c"
    break;

  case 43:
#line 241 "trad.y"
                                                                      { sprintf (temp, " %s \n", (yyvsp[-1].cadena));
                                                                        (yyval.cadena) = genera_cadena (temp) ;}
#line 1904 "trad.tab.c"
    break;

  case 44:
#line 243 "trad.y"
                                                                            { sprintf (temp, "( loop while %s do \n%s )", (yyvsp[-4].cadena), (yyvsp[-1].cadena));
                                                                        (yyval.cadena) = genera_cadena (temp) ;}
#line 1911 "trad.tab.c"
    break;

  case 45:
#line 245 "trad.y"
                                                                           { if (strcmp("", (yyvsp[-2].cadena)) == 0){ 
                                                                            sprintf (temp, "( if %s \n%s \n%s", (yyvsp[-6].cadena), (yyvsp[-3].cadena), (yyvsp[0].cadena));
                                                                        }
                                                                        else{
                                                                            sprintf (temp, "( if %s \n( progn \n %s %s )\n %s", (yyvsp[-6].cadena), (yyvsp[-3].cadena), (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                                            }
                                                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1923 "trad.tab.c"
    break;

  case 46:
#line 254 "trad.y"
                                                    { sprintf (temp, "( setq %s %s )\n( loop while %s do \n%s \n( setq %s %s )\n) ",(yyvsp[-12].cadena), (yyvsp[-10].cadena), (yyvsp[-8].cadena), (yyvsp[-1].cadena), (yyvsp[-6].cadena), (yyvsp[-4].cadena)); 
                                                                       (yyval.cadena) = genera_cadena (temp) ;}
#line 1930 "trad.tab.c"
    break;

  case 47:
#line 256 "trad.y"
                                                                    {(yyval.cadena) = (yyvsp[0].cadena);}
#line 1936 "trad.tab.c"
    break;

  case 48:
#line 259 "trad.y"
                                                                    { sprintf (temp, ") \n%s",(yyvsp[0].cadena)); 
                                                                       (yyval.cadena) = genera_cadena (temp) ;}
#line 1943 "trad.tab.c"
    break;

  case 49:
#line 261 "trad.y"
                                                                    { if (strcmp("", (yyvsp[-2].cadena)) == 0){ 
                                                                            sprintf (temp, " %s ) \n%s", (yyvsp[-3].cadena), (yyvsp[0].cadena));
                                                                        
                                                                    }
                                                                    else{
                                                                            sprintf (temp, "\n( progn \n %s %s )\n \n%s", (yyvsp[-3].cadena), (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                                             
                                                                    }
                                                                    (yyval.cadena) = genera_cadena (temp) ;}
#line 1957 "trad.tab.c"
    break;

  case 50:
#line 271 "trad.y"
                                                                     { sprintf (temp, ")"); 
                                                                        (yyval.cadena) = genera_cadena (temp) ;}
#line 1964 "trad.tab.c"
    break;

  case 51:
#line 273 "trad.y"
                                                                    { if (strcmp("", (yyvsp[-1].cadena)) == 0){ 
                                                                            sprintf (temp, " %s )", (yyvsp[-2].cadena));
                                                                        
                                                                    }
                                                                    else{
                                                                            sprintf (temp, "\n( progn \n %s %s )\n", (yyvsp[-2].cadena), (yyvsp[-1].cadena));
                                                                             
                                                                    }
                                                                    (yyval.cadena) = genera_cadena (temp) ;}
#line 1978 "trad.tab.c"
    break;

  case 52:
#line 284 "trad.y"
                                             {sprintf (temp, "( print \"%s\" )" ,(yyvsp[-1].cadena));
                                                      (yyval.cadena) = genera_cadena (temp) ;}
#line 1985 "trad.tab.c"
    break;

  case 53:
#line 287 "trad.y"
                                                         { sprintf (temp, "( setq %s %s ) %s", (yyvsp[-2].cadena), (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                      (yyval.cadena) = genera_cadena (temp) ; }
#line 1992 "trad.tab.c"
    break;

  case 54:
#line 290 "trad.y"
                                                      { sprintf (temp, "0");
                                                      (yyval.cadena) = genera_cadena (temp);}
#line 1999 "trad.tab.c"
    break;

  case 55:
#line 292 "trad.y"
                                                               { sprintf (temp, "%s", (yyvsp[0].cadena));
                                                      (yyval.cadena) = genera_cadena (temp);}
#line 2006 "trad.tab.c"
    break;

  case 56:
#line 294 "trad.y"
                                                               { sprintf (temp, "( make-array %s )", (yyvsp[-1].cadena));
                                                      (yyval.cadena) = genera_cadena (temp);}
#line 2013 "trad.tab.c"
    break;

  case 57:
#line 297 "trad.y"
                                                      { sprintf (temp, "");
                                                      (yyval.cadena) = genera_cadena (temp) ; }
#line 2020 "trad.tab.c"
    break;

  case 58:
#line 299 "trad.y"
                                                      { sprintf (temp, "( setq %s %s ) %s", (yyvsp[-2].cadena), (yyvsp[-1].cadena), (yyvsp[0].cadena));
                                                      (yyval.cadena) = genera_cadena (temp) ; }
#line 2027 "trad.tab.c"
    break;

  case 59:
#line 302 "trad.y"
                                                     {sprintf (temp, "%s" , (yyvsp[0].cadena) );
                                                      (yyval.cadena) = genera_cadena (temp) ;}
#line 2034 "trad.tab.c"
    break;

  case 60:
#line 305 "trad.y"
                                                     {sprintf (temp, "( print %s ) %s" , (yyvsp[-1].cadena), (yyvsp[0].cadena) );
                                                      (yyval.cadena) = genera_cadena (temp) ;}
#line 2041 "trad.tab.c"
    break;

  case 61:
#line 307 "trad.y"
                                                    {sprintf (temp, "%s" , (yyvsp[0].cadena) );
                                                      (yyval.cadena) = genera_cadena (temp) ;}
#line 2048 "trad.tab.c"
    break;

  case 62:
#line 311 "trad.y"
                                                   {sprintf (temp, "%s" , (yyvsp[0].cadena) );
                                                     (yyval.cadena) = genera_cadena (temp) ;}
#line 2055 "trad.tab.c"
    break;

  case 63:
#line 313 "trad.y"
                                                    {sprintf (temp, "");
                                                     (yyval.cadena) = genera_cadena (temp) ;}
#line 2062 "trad.tab.c"
    break;

  case 64:
#line 318 "trad.y"
                                               { sprintf (temp, "( setq %s %s ) " , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2069 "trad.tab.c"
    break;

  case 65:
#line 320 "trad.y"
                                                          { sprintf (temp, "( setf ( aref %s %s ) %s) " , (yyvsp[-5].cadena), (yyvsp[-3].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2076 "trad.tab.c"
    break;

  case 66:
#line 322 "trad.y"
                                                                             { sprintf (temp, "(setf ( values %s %s %s %s %s )) " , (yyvsp[-6].cadena), (yyvsp[-4].cadena), (yyvsp[-3].cadena), (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 2083 "trad.tab.c"
    break;

  case 67:
#line 329 "trad.y"
                                                         { sprintf (temp, " ) (values ");
                                                         (yyval.cadena) = genera_cadena (temp) ; }
#line 2090 "trad.tab.c"
    break;

  case 68:
#line 331 "trad.y"
                                                             { sprintf ( temp, "%s %s %s",(yyvsp[-3].cadena), (yyvsp[-2].cadena), (yyvsp[-1].cadena) );
                                                         (yyval.cadena) = genera_cadena (temp) ; }
#line 2097 "trad.tab.c"
    break;

  case 69:
#line 335 "trad.y"
                                                                { (yyval.cadena) = (yyvsp[0].cadena) ;}
#line 2103 "trad.tab.c"
    break;

  case 70:
#line 336 "trad.y"
                                                        { sprintf (temp, "( + %s %s )", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2110 "trad.tab.c"
    break;

  case 71:
#line 338 "trad.y"
                                                        {  sprintf (temp, "( - %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2117 "trad.tab.c"
    break;

  case 72:
#line 340 "trad.y"
                                                        {  sprintf (temp, "( * %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2124 "trad.tab.c"
    break;

  case 73:
#line 342 "trad.y"
                                                        {  sprintf (temp, "( / %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2131 "trad.tab.c"
    break;

  case 74:
#line 344 "trad.y"
                                                {  sprintf (temp, "( mod %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                (yyval.cadena) = genera_cadena (temp) ; }
#line 2138 "trad.tab.c"
    break;

  case 75:
#line 346 "trad.y"
                                                        { sprintf (temp, "( < %s %s )", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2145 "trad.tab.c"
    break;

  case 76:
#line 348 "trad.y"
                                                {  sprintf (temp, "( > %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2152 "trad.tab.c"
    break;

  case 77:
#line 350 "trad.y"
                                                {  sprintf (temp, "( <= %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2159 "trad.tab.c"
    break;

  case 78:
#line 352 "trad.y"
                                                   {  sprintf (temp, "( >= %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2166 "trad.tab.c"
    break;

  case 79:
#line 354 "trad.y"
                                                { sprintf (temp, "( = %s %s )", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2173 "trad.tab.c"
    break;

  case 80:
#line 356 "trad.y"
                                                {  sprintf (temp, "( /= %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2180 "trad.tab.c"
    break;

  case 81:
#line 358 "trad.y"
                                                        {  sprintf (temp, "( AND %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2187 "trad.tab.c"
    break;

  case 82:
#line 360 "trad.y"
                                                        {  sprintf (temp, "( OR %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2194 "trad.tab.c"
    break;

  case 83:
#line 363 "trad.y"
                                                                        { (yyval.cadena) = (yyvsp[0].cadena) ;}
#line 2200 "trad.tab.c"
    break;

  case 84:
#line 364 "trad.y"
                                                        { sprintf (temp, "( + %s %s )", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2207 "trad.tab.c"
    break;

  case 85:
#line 366 "trad.y"
                                                        {  sprintf (temp, "( - %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2214 "trad.tab.c"
    break;

  case 86:
#line 368 "trad.y"
                                                        {  sprintf (temp, "( * %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2221 "trad.tab.c"
    break;

  case 87:
#line 370 "trad.y"
                                                        {  sprintf (temp, "( / %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                    (yyval.cadena) = genera_cadena (temp) ; }
#line 2228 "trad.tab.c"
    break;

  case 88:
#line 372 "trad.y"
                                                {  sprintf (temp, "( mod %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                (yyval.cadena) = genera_cadena (temp) ; }
#line 2235 "trad.tab.c"
    break;

  case 89:
#line 376 "trad.y"
                                                        { sprintf (temp, "( < %s %s )", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2242 "trad.tab.c"
    break;

  case 90:
#line 378 "trad.y"
                                                {  sprintf (temp, "( > %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2249 "trad.tab.c"
    break;

  case 91:
#line 380 "trad.y"
                                                {  sprintf (temp, "( <= %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2256 "trad.tab.c"
    break;

  case 92:
#line 382 "trad.y"
                                                   {  sprintf (temp, "( >= %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2263 "trad.tab.c"
    break;

  case 93:
#line 384 "trad.y"
                                                { sprintf (temp, "( = %s %s )", (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2270 "trad.tab.c"
    break;

  case 94:
#line 386 "trad.y"
                                                {  sprintf (temp, "( //= %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2277 "trad.tab.c"
    break;

  case 95:
#line 388 "trad.y"
                                                        {  sprintf (temp, "( AND %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2284 "trad.tab.c"
    break;

  case 96:
#line 390 "trad.y"
                                                        {  sprintf (temp, "( OR %s %s )" , (yyvsp[-2].cadena), (yyvsp[0].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2291 "trad.tab.c"
    break;

  case 97:
#line 394 "trad.y"
                                                                    { (yyval.cadena) = (yyvsp[0].cadena); }
#line 2297 "trad.tab.c"
    break;

  case 98:
#line 395 "trad.y"
                                                        { sprintf (temp, "( + %s) ", (yyvsp[0].cadena) ); 
                                                      (yyval.cadena) = genera_cadena (temp) ;}
#line 2304 "trad.tab.c"
    break;

  case 99:
#line 398 "trad.y"
                                                        { sprintf (temp, "( - %s) ", (yyvsp[0].cadena) ) ; 
                                                      (yyval.cadena) = genera_cadena (temp) ;}
#line 2311 "trad.tab.c"
    break;

  case 100:
#line 404 "trad.y"
                                                { sprintf (temp, "%s ", (yyvsp[0].cadena));

                                          (yyval.cadena) = genera_cadena (temp) ; }
#line 2319 "trad.tab.c"
    break;

  case 101:
#line 407 "trad.y"
                                                        { sprintf (temp, "%d ", (yyvsp[0].valor));
                                          (yyval.cadena) = genera_cadena (temp);}
#line 2326 "trad.tab.c"
    break;

  case 102:
#line 409 "trad.y"
                                                { sprintf (temp, " %s ", (yyvsp[-1].cadena)) ;
                                          (yyval.cadena) = genera_cadena (temp) ; }
#line 2333 "trad.tab.c"
    break;

  case 103:
#line 411 "trad.y"
                                        {  (yyval.cadena) = (yyvsp[0].cadena); }
#line 2339 "trad.tab.c"
    break;

  case 104:
#line 413 "trad.y"
                                            { sprintf (temp, "( aref %s %s ) " , (yyvsp[-3].cadena), (yyvsp[-1].cadena));
                                                  (yyval.cadena) = genera_cadena (temp) ; }
#line 2346 "trad.tab.c"
    break;


#line 2350 "trad.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 417 "trad.y"

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

