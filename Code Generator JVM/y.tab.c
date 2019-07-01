/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

#include<stdio.h> // include header if needed
#include"common.h"

	extern int yylineno;
	extern int yylex();
	extern char *yytext; // Get current token from lex
	extern char buf[256]; // Get current code line from lex
	extern int ERROR;
	extern int semantic_error;
	int depth = 0;
	int do_depth = 0;
	int flag = 0;
	int num = 0;
	int endline_dump = 0;
	int fun_end = 0;
	char semantic_msg[256];
	char param[256];
	int cur_init_i = 0;
	char arith_choose[15]={0};
	char cur_init[15] = {0};
	int function = 0;
	char param_call_type[15] = {0};
	int acc_semantic = 0;	
	char if_else_label[1000] = {0};
	int  if_else_flag = 0;
	char compare_type[3] = {0};
	int compare_num = 0;
	int while_flag = 0;
	int while_num = 0;
	char while_label[1000] = {0};
	char func_type[10] = {0};
	int RT_FP = 0;

	FILE *file; // To generate .j file for Jasmin

	typedef struct Entry Entry;
	struct Entry{
		int index;
		char name[1000];
		char E_T[1000];
		char D_T[1000];
		char attr[1000];
		int level;
		int depth;
		int func_def;
		int R_N;
		char func_assem[15];
		char func_param_type[15];
		float i_num;
		float f_num;
		char s_const[1000];
		Entry *next;
	};

	typedef struct Header Header;
	struct Header{
		Entry *root;
		Entry *tail;
		Header *pre;
	};

	typedef struct param_item param_item;
	struct param_item{
		char name[256];
		char type[256];
		param_item *next;
	};

	Header *cur_table;
	param_item *p_item;


	/* Symbol table function - you can add new function if needed. */
	int lookup_symbol(char name[], char type[], int choose, int choose_type);
	Header* create_symbol(char name[], char entry_type[], char data_type[], char att[], int func_def);
	void insert_symbol(char name[], char entry_type[], char data_type[], int D, char att[],int func_def);
	void dump_symbol();
	int get_stack_num(char name[], int D);
	void yyerror();
	void semantic(char msg[]);
	void test();
	char *get_type(char name[], int D);
	char *type_tran(char type[]);
	char *get_param(char name[]);
	void renew_func(char name[], char func[], char type[]);
	int check_float(char num[]);
	void check_param(char name[], char param[]);
	void renew_ID(char name[], float num);
	void renew_s_ID(char name[], char con[]);
	int get_i_num(char name[]);
	float get_f_num(char name[]);

	/* code generation functions, just an example! */
	void gencode_function();

	

#line 165 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INC = 258,
    DEC = 259,
    GE_OP = 260,
    LE_OP = 261,
    EQ_OP = 262,
    NE_OP = 263,
    ADD_ASSIGN = 264,
    SUB_ASSIGN = 265,
    MUL_ASSIGN = 266,
    DIV_ASSIGN = 267,
    MOD_ASSIGN = 268,
    PRINT = 269,
    IF = 270,
    ELSE = 271,
    SEMICOLON = 272,
    I_CONST = 273,
    F_CONST = 274,
    ID = 275,
    STRING_CONST = 276,
    NEWLINE = 277,
    BOOL = 278,
    INT = 279,
    FLOAT = 280,
    STRING = 281,
    VOID = 282,
    AND_OP = 283,
    OR_OP = 284,
    NOT = 285,
    FOR = 286,
    WHILE = 287,
    TRUE = 288,
    FALSE = 289,
    RETURN = 290,
    QUOTA = 291
  };
#endif
/* Tokens.  */
#define INC 258
#define DEC 259
#define GE_OP 260
#define LE_OP 261
#define EQ_OP 262
#define NE_OP 263
#define ADD_ASSIGN 264
#define SUB_ASSIGN 265
#define MUL_ASSIGN 266
#define DIV_ASSIGN 267
#define MOD_ASSIGN 268
#define PRINT 269
#define IF 270
#define ELSE 271
#define SEMICOLON 272
#define I_CONST 273
#define F_CONST 274
#define ID 275
#define STRING_CONST 276
#define NEWLINE 277
#define BOOL 278
#define INT 279
#define FLOAT 280
#define STRING 281
#define VOID 282
#define AND_OP 283
#define OR_OP 284
#define NOT 285
#define FOR 286
#define WHILE 287
#define TRUE 288
#define FALSE 289
#define RETURN 290
#define QUOTA 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 100 "compiler_hw3.y" /* yacc.c:355  */

	int i_val;
	float f_val;
	char* string;
	RULE_TYPE rule_type;

#line 284 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 301 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    48,     2,     2,
      39,    40,    46,    44,    43,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      50,    37,    49,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   129,   133,   134,   146,   147,   148,   150,
     154,   173,   257,   318,   318,   411,   411,   453,   462,   488,
     493,   496,   501,   507,   521,   532,   566,   597,   619,   641,
     647,   668,   704,   723,   726,   732,   748,   765,   780,   797,
     832,   832,   841,   845,   846,   853,   864,   865,   866,   867,
     871,   875,   884,   885,   904,   905,   909,   910,   911,   915,
     916,   917,   922,   923,   924,   925,   926,   930,   931,   935,
     938,   941,   944,   947,   950,   956,   959,   965,   968,   972,
     982,   993,  1003,  1013,  1026,  1257,  1260,  1264,  1270,  1274,
    1277,  1314,  1314,  1320,  1327,  1328,  1348,  1349,  1350,  1351,
    1352,  1356,  1384,  1388,  1394,  1404,  1407,  1408,  1407,  1441,
    1444,  1441,  1475,  1475,  1484,  1488,  1484
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INC", "DEC", "GE_OP", "LE_OP", "EQ_OP",
  "NE_OP", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "PRINT", "IF", "ELSE", "SEMICOLON", "I_CONST", "F_CONST",
  "ID", "STRING_CONST", "NEWLINE", "BOOL", "INT", "FLOAT", "STRING",
  "VOID", "AND_OP", "OR_OP", "NOT", "FOR", "WHILE", "TRUE", "FALSE",
  "RETURN", "QUOTA", "'='", "';'", "'('", "')'", "'{'", "'}'", "','",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'>'", "'<'", "$accept", "program",
  "stat", "declaration", "$@1", "$@2", "CompoundStmt", "StmtList",
  "deeper_scope", "shallow_scope", "param_list", "param",
  "arithmetic_expr", "term", "fact", "$@3", "param_call", "condition_list",
  "condition", "condition_type", "type", "initializer", "compare",
  "initializer_num", "ArithmeticList", "expression_stat", "$@4", "Factor",
  "print_func", "IF_ELSE", "if_else_cond", "$@5", "$@6", "$@7", "$@8",
  "$@9", "WHILESTMT", "$@10", "$@11", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    61,    59,    40,
      41,   123,   125,    44,    43,    45,    42,    47,    37,    62,
      60
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -56

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     288,   -33,   -23,     8,    77,  -144,  -144,  -144,  -144,  -144,
    -144,   -14,   190,   158,  -144,  -144,     9,  -144,  -144,  -144,
    -144,  -144,   116,  -144,  -144,    22,  -144,  -144,    31,    31,
      31,    31,    31,    31,    -6,    61,  -144,  -144,  -144,   118,
    -144,  -144,  -144,    31,    55,    10,    11,  -144,    66,  -144,
    -144,    45,    75,   125,   130,   131,   238,    74,  -144,  -144,
    -144,  -144,  -144,   137,  -144,  -144,   128,   110,   110,   110,
     110,   110,    33,  -144,  -144,   129,  -144,   238,   139,    80,
    -144,    69,  -144,  -144,     3,  -144,  -144,  -144,   238,  -144,
     135,   151,    -2,    60,  -144,  -144,  -144,    31,    31,   245,
     245,   245,  -144,   199,  -144,    70,   153,   167,   168,   173,
     185,   238,   172,  -144,  -144,  -144,    31,   182,   105,    -2,
     186,  -144,  -144,   221,  -144,  -144,  -144,  -144,  -144,  -144,
     262,   196,  -144,   228,  -144,  -144,  -144,    11,    11,    31,
    -144,  -144,  -144,   174,    73,   175,   197,   126,   210,  -144,
    -144,  -144,  -144,  -144,   203,  -144,  -144,  -144,   110,  -144,
     124,  -144,   207,  -144,  -144,   140,   110,  -144,  -144,   191,
      60,  -144,  -144,  -144,    22,   212,   136,  -144,    22,  -144,
    -144,  -144,  -144,    22,  -144,  -144,  -144,    22,   231,  -144,
      22,  -144,  -144,  -144,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   112,     0,     5,    64,    62,    63,    65,
      66,     0,     0,     0,     3,     4,     0,     6,     7,     8,
     105,     9,     0,   106,   109,     0,    77,    78,     0,     0,
       0,     0,     0,     0,     0,     0,   114,    35,    37,    39,
      44,    45,    86,     0,     0,     0,    29,    33,     0,     1,
       2,     0,     0,     0,     0,     0,     0,     0,    22,   113,
      21,    35,    37,    39,    44,    45,     0,    79,    80,    81,
      82,    83,     0,    35,    37,    39,    49,     0,     0,    60,
      33,     0,    48,    50,     0,    52,    67,    84,     0,    87,
      40,     0,     0,    29,    36,    38,    89,     0,     0,     0,
       0,     0,    85,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    38,    90,     0,     0,    61,    60,
       0,    93,    91,     0,    71,    72,    74,    73,    69,    70,
       0,     0,    42,     0,    88,    34,    43,    27,    28,     0,
      30,    31,    32,     0,     0,    15,     0,    24,     0,   103,
     104,   101,   102,   107,     0,    23,    20,    19,    53,    42,
       0,    58,     0,    47,    46,    39,    60,    51,   115,     0,
       0,    10,    11,    17,     0,    13,     0,    26,     0,   110,
      56,    92,    61,     0,    41,    16,    18,     0,     0,   108,
       0,   116,    14,    25,   111
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,   -10,  -144,  -144,  -144,  -143,  -144,  -144,  -144,
    -144,  -144,   -11,   -36,   -32,  -144,   -87,   -51,  -144,   122,
    -101,  -144,  -144,  -144,   -39,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,   187,   174,    59,   112,    60,   157,
     146,   147,    79,    46,    47,   133,    81,    82,    83,    84,
      16,    85,   130,    86,    35,    17,   162,    48,    18,    19,
      20,    56,   178,    57,   190,    25,    21,    88,   183
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    45,    80,    50,   148,   110,    22,    93,   124,   125,
     126,   127,    73,    74,    75,    76,    23,    67,    68,    69,
      70,    71,    72,    24,    80,    36,   120,    64,    65,    51,
     160,   185,    92,    77,    78,   189,   118,   131,   135,    66,
     191,    93,    97,    98,   192,    80,   169,   194,    96,    61,
      62,    63,   128,   129,    97,    98,    80,    99,   100,   101,
     154,   137,   138,    58,    64,    65,   119,   140,   141,   142,
      43,   115,   164,    94,    95,   188,    66,    97,    98,    80,
      26,    27,   103,   104,   105,    80,    28,    29,    30,    31,
      32,    80,   144,     6,     7,     8,     9,    10,    80,    87,
     136,    80,   156,   170,   102,   158,    99,   100,   101,   122,
     145,   172,   123,   111,    33,   106,    34,    97,    98,   166,
     -54,    26,    27,   -54,    97,    98,   182,    28,    29,    30,
      31,    32,    26,    27,    52,    53,    54,    55,    28,    29,
      30,    31,    32,    26,    27,   -55,   113,   114,   -55,    28,
      29,    30,    31,    32,    97,    98,    89,    90,    49,     6,
       7,     8,     9,    10,   180,   107,   116,   123,   117,   176,
     108,   109,     1,     2,     3,   132,    90,   121,     4,    90,
       5,     6,     7,     8,     9,    10,     1,     2,     3,   134,
      11,   149,     4,    12,     5,     6,     7,     8,     9,    10,
      73,    74,    75,    76,    11,   150,   151,    12,    37,    38,
      39,   152,   171,   173,   155,    64,    65,    61,    62,    63,
     143,    77,   159,    40,    41,   153,   161,    66,    42,    43,
     177,   184,    64,    65,   123,    44,   168,   175,    43,    73,
      74,    75,   163,   179,    66,   181,    73,    74,    75,    76,
     186,   193,   167,     0,    64,    65,    73,    74,    75,     0,
      77,    64,    65,    61,    62,    63,    66,    77,     0,     0,
       0,    64,    65,    66,     0,     0,     0,    77,    64,    65,
      61,    62,   165,    66,   139,     0,     0,     0,     0,     0,
      66,     0,     0,     0,     0,    64,    65,     0,     0,     0,
       0,    43,     1,     2,     3,     0,     0,    66,     4,     0,
       5,     6,     7,     8,     9,    10,     0,     0,     0,     0,
      11,     0,     0,    12
};

static const yytype_int16 yycheck[] =
{
      39,    12,    34,    13,   105,    56,    39,    43,     5,     6,
       7,     8,    18,    19,    20,    21,    39,    28,    29,    30,
      31,    32,    33,    15,    56,    39,    77,    33,    34,    20,
     117,   174,    43,    39,    40,   178,    75,    88,    40,    45,
     183,    77,    44,    45,   187,    77,   133,   190,    38,    18,
      19,    20,    49,    50,    44,    45,    88,    46,    47,    48,
     111,    97,    98,    41,    33,    34,    77,    99,   100,   101,
      39,    38,   123,    18,    19,   176,    45,    44,    45,   111,
       3,     4,    37,    38,    39,   117,     9,    10,    11,    12,
      13,   123,   103,    23,    24,    25,    26,    27,   130,    38,
      40,   133,   112,   139,    38,   116,    46,    47,    48,    40,
      40,    38,    43,    39,    37,    40,    39,    44,    45,   130,
      40,     3,     4,    43,    44,    45,   165,     9,    10,    11,
      12,    13,     3,     4,    18,    19,    20,    21,     9,    10,
      11,    12,    13,     3,     4,    40,    18,    19,    43,     9,
      10,    11,    12,    13,    44,    45,    38,    39,     0,    23,
      24,    25,    26,    27,    40,    40,    37,    43,    39,    43,
      40,    40,    14,    15,    16,    40,    39,    38,    20,    39,
      22,    23,    24,    25,    26,    27,    14,    15,    16,    38,
      32,    38,    20,    35,    22,    23,    24,    25,    26,    27,
      18,    19,    20,    21,    32,    38,    38,    35,    18,    19,
      20,    38,    38,    38,    42,    33,    34,    18,    19,    20,
      21,    39,    40,    33,    34,    40,    40,    45,    38,    39,
      20,    40,    33,    34,    43,    45,    40,    40,    39,    18,
      19,    20,    21,    40,    45,    38,    18,    19,    20,    21,
      38,    20,   130,    -1,    33,    34,    18,    19,    20,    -1,
      39,    33,    34,    18,    19,    20,    45,    39,    -1,    -1,
      -1,    33,    34,    45,    -1,    -1,    -1,    39,    33,    34,
      18,    19,    20,    45,    39,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      -1,    39,    14,    15,    16,    -1,    -1,    45,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    15,    16,    20,    22,    23,    24,    25,    26,
      27,    32,    35,    52,    53,    54,    71,    76,    79,    80,
      81,    87,    39,    39,    15,    86,     3,     4,     9,    10,
      11,    12,    13,    37,    39,    75,    39,    18,    19,    20,
      33,    34,    38,    39,    45,    63,    64,    65,    78,     0,
      53,    20,    18,    19,    20,    21,    82,    84,    41,    57,
      59,    18,    19,    20,    33,    34,    45,    63,    63,    63,
      63,    63,    63,    18,    19,    20,    21,    39,    40,    63,
      65,    67,    68,    69,    70,    72,    74,    38,    88,    38,
      39,    75,    63,    64,    18,    19,    38,    44,    45,    46,
      47,    48,    38,    37,    38,    39,    40,    40,    40,    40,
      68,    39,    58,    18,    19,    38,    37,    39,    75,    63,
      68,    38,    40,    43,     5,     6,     7,     8,    49,    50,
      73,    68,    40,    66,    38,    40,    40,    64,    64,    39,
      65,    65,    65,    21,    63,    40,    61,    62,    71,    38,
      38,    38,    38,    40,    68,    42,    53,    60,    63,    40,
      67,    40,    77,    21,    68,    20,    63,    70,    40,    67,
      64,    38,    38,    38,    56,    40,    43,    20,    83,    40,
      40,    38,    75,    89,    40,    57,    38,    55,    71,    57,
      85,    57,    57,    20,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      54,    54,    54,    55,    54,    56,    54,    54,    54,    57,
      58,    58,    59,    60,    61,    62,    62,    63,    63,    63,
      64,    64,    64,    64,    64,    65,    65,    65,    65,    65,
      66,    65,    65,    65,    65,    65,    67,    67,    67,    67,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    74,    75,    75,    75,
      75,    75,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    77,    76,    76,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    80,    82,    83,    81,    84,
      85,    81,    86,    81,    88,    89,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     3,     0,     7,     0,     6,     5,     6,     3,
       2,     0,     1,     1,     1,     4,     2,     3,     3,     1,
       3,     3,     3,     1,     3,     1,     2,     1,     2,     1,
       0,     5,     3,     3,     1,     1,     3,     3,     1,     1,
       1,     3,     1,     3,     1,     2,     4,     3,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     3,     3,     2,     3,     4,     3,
       4,     0,     6,     4,     1,     1,     1,     1,     2,     1,
       2,     5,     5,     5,     5,     1,     0,     0,     7,     0,
       0,     8,     0,     3,     0,     0,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 5:
#line 134 "compiler_hw3.y" /* yacc.c:1646  */
    {
	ERROR = 0;
	if(endline_dump == 1){
		dump_symbol(); 
		endline_dump = 0;
	}
	if(semantic_error == 1){
		semantic(semantic_msg);
		semantic_error = 0;
		memset(buf, 0, sizeof(buf));
	}
}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 148 "compiler_hw3.y" /* yacc.c:1646  */
    {
}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 154 "compiler_hw3.y" /* yacc.c:1646  */
    {
	
	if(cur_table == NULL){
		cur_table = create_symbol((yyvsp[-3].rule_type).id, "variable", (yyvsp[-4].string), "", 1);
	}
	else{	
		lookup_symbol((yyvsp[-3].rule_type).id, (yyvsp[-4].string), 0, 0);
		if(semantic_error==0){
			insert_symbol((yyvsp[-3].rule_type).id, "variable", (yyvsp[-4].string), depth, "", 1);
		}
	}
	fprintf(file, "ldc \"%s\"\n", (yyvsp[-1].rule_type).string);
	renew_s_ID((yyvsp[-3].rule_type).id, (yyvsp[-1].rule_type).string);
	(yyvsp[-3].rule_type).type = STRING_t;
	(yyvsp[-3].rule_type).string = (yyvsp[-1].rule_type).string;
	int stack_num = get_stack_num((yyvsp[-3].rule_type).id, depth);
	fprintf(file, "astore %d\n", stack_num-1);
}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 173 "compiler_hw3.y" /* yacc.c:1646  */
    {
	if(cur_table == NULL){
		cur_table = create_symbol((yyvsp[-3].rule_type).id, "variable", (yyvsp[-4].string), "", 1);
	}
	else{	
		lookup_symbol((yyvsp[-3].rule_type).id, (yyvsp[-4].string), 0, 0);
		if(semantic_error==0){
			insert_symbol((yyvsp[-3].rule_type).id, "variable", (yyvsp[-4].string), depth, "", 1);
		}
	}
	char type[15] = {0};
	strcpy(type, type_tran((yyvsp[-4].string)));
	if(depth == 0){
		if(!strcmp((yyvsp[-4].string), "float")){
			renew_ID((yyvsp[-3].rule_type).id, (yyvsp[-1].rule_type).f_val);
			(yyvsp[-3].rule_type).type = FLOAT_t;
			(yyvsp[-3].rule_type).f_val = (yyvsp[-1].rule_type).f_val;
			fprintf(file,   ".field public static %s %s = %f\n", (yyvsp[-3].rule_type).id, type, (yyvsp[-1].rule_type).f_val);
		}
		else if(!strcmp((yyvsp[-4].string), "string")){
			renew_s_ID((yyvsp[-3].rule_type).id, (yyvsp[-1].rule_type).string);
			(yyvsp[-3].rule_type).type = STRING_t;
			(yyvsp[-3].rule_type).string = (yyvsp[-1].rule_type).string;
		}
		else if(!strcmp((yyvsp[-4].string), "bool")){
			renew_ID((yyvsp[-3].rule_type).id, (yyvsp[-1].rule_type).i_val);
			(yyvsp[-3].rule_type).type = BOOL_t;
			(yyvsp[-3].rule_type).i_val = (yyvsp[-1].rule_type).i_val;
			fprintf(file,   ".field public static %s %s = %d\n", (yyvsp[-3].rule_type).id, type, (yyvsp[-1].rule_type).i_val);
		}
		else{
			renew_ID((yyvsp[-3].rule_type).id, (yyvsp[-1].rule_type).i_val);
			(yyvsp[-3].rule_type).type = INT_t;
			(yyvsp[-3].rule_type).i_val = (yyvsp[-1].rule_type).i_val;
			fprintf(file,   ".field public static %s %s = %d\n", (yyvsp[-3].rule_type).id, type, (yyvsp[-1].rule_type).i_val);
		}
	}
	else{
		int stack_num = get_stack_num((yyvsp[-3].rule_type).id, depth);
		if(!strcmp((yyvsp[-4].string), "float")){
			if((yyvsp[-1].rule_type).type == FLOAT_t){
				fprintf(file, "fstore %d\n", stack_num-1);
				renew_ID((yyvsp[-3].rule_type).id, (yyvsp[-1].rule_type).f_val);
				(yyvsp[-3].rule_type).type = FLOAT_t;
				(yyvsp[-3].rule_type).f_val = (yyvsp[-1].rule_type).f_val;
			}
			else{
				fprintf(file, "i2f\n");
				fprintf(file, "fstore %d\n", stack_num-1);
				renew_ID((yyvsp[-3].rule_type).id, (yyvsp[-1].rule_type).i_val);
				(yyvsp[-3].rule_type).type = FLOAT_t;
				(yyvsp[-3].rule_type).f_val = (yyvsp[-1].rule_type).i_val;
			}
		}
		else if(!strcmp((yyvsp[-4].string), "string")){
			fprintf(file, "istore %d\n", stack_num-1);
			renew_s_ID((yyvsp[-3].rule_type).id, (yyvsp[-1].rule_type).string);
			(yyvsp[-3].rule_type).type = STRING_t;
			(yyvsp[-3].rule_type).string = (yyvsp[-1].rule_type).string;
		}
		else if(!strcmp((yyvsp[-4].string), "bool")){
			fprintf(file, "istore %d\n", stack_num-1);
			renew_ID((yyvsp[-3].rule_type).id, (yyvsp[-1].rule_type).i_val);
			(yyvsp[-3].rule_type).type = BOOL_t;
			(yyvsp[-3].rule_type).i_val = (yyvsp[-1].rule_type).i_val;
		}
		else{
			if((yyvsp[-1].rule_type).type == FLOAT_t){
				fprintf(file, "f2i\n");
				fprintf(file, "istore %d\n", stack_num-1);
				renew_ID((yyvsp[-3].rule_type).id, (yyvsp[-1].rule_type).f_val);
				(yyvsp[-3].rule_type).type = INT_t;
				(yyvsp[-3].rule_type).i_val = (int)(yyvsp[-1].rule_type).f_val;
			}
			else{
				fprintf(file, "istore %d\n", stack_num-1);
				renew_ID((yyvsp[-3].rule_type).id, (yyvsp[-1].rule_type).i_val);
				(yyvsp[-3].rule_type).type = INT_t;
				(yyvsp[-3].rule_type).i_val = (yyvsp[-1].rule_type).i_val;
			}
		}
	}
}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 257 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(cur_table == NULL){
			cur_table = create_symbol((yyvsp[-1].rule_type).id, "variable", (yyvsp[-2].string), "", 1);
		}
		else{
			lookup_symbol((yyvsp[-1].rule_type).id, (yyvsp[-2].string), 0, 0);
			if(semantic_error==0){
				insert_symbol((yyvsp[-1].rule_type).id, "variable", (yyvsp[-2].string), depth, "", 1);
			}
		}
		char type[15] = {0};
		strcpy(type, type_tran((yyvsp[-2].string)));
			if(depth == 0){
				fprintf(file,   ".field public static %s %s\n", (yyvsp[-1].rule_type).id, type);
				if(!strcmp((yyvsp[-2].string), "float")){
					renew_ID((yyvsp[-1].rule_type).id, 0.0);
					(yyvsp[-1].rule_type).type = FLOAT_t;
				}
				else if(!strcmp((yyvsp[-2].string), "string")){
					renew_s_ID((yyvsp[-1].rule_type).id, "");
					(yyvsp[-1].rule_type).type = STRING_t;
				}
				else if(!strcmp((yyvsp[-2].string), "bool")){
					renew_ID((yyvsp[-1].rule_type).id, 1);
					(yyvsp[-1].rule_type).type = BOOL_t;
				}
				else{
					renew_ID((yyvsp[-1].rule_type).id, 0);
					(yyvsp[-1].rule_type).type = INT_t;
				}
			}
			else{
				int stack_num = get_stack_num((yyvsp[-1].rule_type).id, depth);
				if(!strcmp((yyvsp[-2].string), "float")){
					fprintf(file, "ldc 0.0\n");
					fprintf(file, "fstore %d\n", stack_num-1);
					renew_ID((yyvsp[-1].rule_type).id, 0);
				}
				else if(!strcmp((yyvsp[-2].string), "string")){
					fprintf(file, "istore %d\n", stack_num-1);
					renew_s_ID((yyvsp[-1].rule_type).id, "");
					(yyvsp[-1].rule_type).type = STRING_t;
				}
				else if(!strcmp((yyvsp[-2].string), "bool")){
					fprintf(file, "ldc 1\n");
					fprintf(file, "istore %d\n", stack_num-1);
					renew_ID((yyvsp[-1].rule_type).id, 1);
					(yyvsp[-1].rule_type).type = BOOL_t;
				}

				else{
					fprintf(file, "ldc 0\n");
					fprintf(file, "istore %d\n", stack_num-1);
					renew_ID((yyvsp[-1].rule_type).id, 0);
				}

				//printf("stack_num = %d\n", stack_num);
			}
	}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 318 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(cur_table){
			lookup_symbol((yyvsp[-3].rule_type).id, (yyvsp[-4].string), 0, 1);
			if(semantic_error==0){
				insert_symbol((yyvsp[-3].rule_type).id, "function", (yyvsp[-4].string), depth, param, 1);
				param_item *t = p_item;
				while(t!=NULL){
					lookup_symbol(t->name, t->type, 0, 0);
					insert_symbol(t->name, "parameter", t->type, depth+1, "", 1);
					t = t->next;
				}
				
			}



			char func_name[15] = {0};
			strcat(func_name, (yyvsp[-3].rule_type).id);
			strcat(func_name, "(");

			param_item *t = p_item;
			param_item *next;
			char type[256] = {0};
			while(t!=NULL){
				if(!strcmp(t->type, "int")){
					strcat(type, "I");
				}
				else if(!strcmp(t->type, "float")){
					strcat(type, "F");
				}
				next = t->next;
				free(t);
				t = next;
			}
			p_item = NULL;
			char return_type[15] = {0};
			strcpy(return_type, type_tran((yyvsp[-4].string)));
			strcat(func_name, type);
			strcat(func_name, ")");
			strcat(func_name, return_type);


			if(strcmp((yyvsp[-4].string), func_type) && strcmp(func_type, "")){
				//semantic_error = 1;
				//strcpy(semantic_msg, "the return type is not the same\n");
				RT_FP = 1;
			}

			renew_func((yyvsp[-3].rule_type).id, func_name, type);
			fprintf(file,  ".method public static %s(%s)%s\n.limit stack 50\n.limit locals 50\n", (yyvsp[-3].rule_type).id, type, return_type);
		}
		else{
			cur_table = create_symbol((yyvsp[-3].rule_type).id, "function", (yyvsp[-4].string), param, 1);
			param_item *t = p_item;
			while(t!=NULL){
				lookup_symbol(t->name, t->type, 0, 0);
				insert_symbol(t->name, "parameter", t->type, depth+1, "", 1);
				t = t->next;
			}
			
			char func_name[15] = {0};
			strcat(func_name, (yyvsp[-3].rule_type).id);
			strcat(func_name, "(");
			t = p_item;
			
			param_item *next;
			char type[256] = {0};
			while(t!=NULL){
				if(!strcmp(t->type, "int")){
					strcat(type, "I");
				}
				else if(!strcmp(t->type, "float")){
					strcat(type, "F");
				}
				next = t->next;
				free(t);
				t = next;
			}
			p_item = NULL;
			char return_type[15] = {0};
			strcpy(return_type, type_tran((yyvsp[-4].string)));
			strcat(func_name, type);
			strcat(func_name, ")");
			strcat(func_name, return_type);
			renew_func((yyvsp[-3].rule_type).id, func_name, type);
			fprintf(file,  ".method public static %s(%s)%s\n.limit stack 50\n.limit locals 50\n", (yyvsp[-3].rule_type).id, type, return_type);

		}

	}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 407 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, ".end method\n");
	}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 411 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(func_type, (yyvsp[-3].string));
		if(cur_table){
			int inserted = 0;
			Entry *temp = cur_table->root;
			while(temp!=NULL){
				if(temp->depth==0){
					if(!strcmp(temp->name, (yyvsp[-2].rule_type).id)){
						inserted = 1;
						break;
					}
				}
				temp = temp->next;
			}
			if(inserted==0){
				lookup_symbol((yyvsp[-2].rule_type).id, (yyvsp[-3].string), 0, 1);
				if(strcmp((yyvsp[-3].string), func_type) && strcmp(func_type, "")){
					//semantic_error = 1;
					//strcpy(semantic_msg, "the return type is not the same\n");
				}
				if(semantic_error==0){
					insert_symbol((yyvsp[-2].rule_type).id, "function", (yyvsp[-3].string), depth, "", 1);
				}
			}
		}
		else{
			cur_table = create_symbol((yyvsp[-2].rule_type).id, "function", (yyvsp[-3].string), "", 1);
		}
		if(!strcmp((yyvsp[-2].rule_type).id, "main")){
			fprintf(file,  ".method public static main([Ljava/lang/String;)V\n.limit stack 50\n.limit locals 50\n");
		}
		else{
			char return_type[15] = {0};
			strcpy(return_type, type_tran((yyvsp[-3].string)));
			fprintf(file,  ".method public static %s([Ljava/lang/String;)%s\n.limit stack 50\n.limit locals 50\n", (yyvsp[-3].string)
			, return_type);
		}
			
	}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 449 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fun_end = 1;
		fprintf(file, ".end method\n");
	}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 453 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(cur_table){
			lookup_symbol((yyvsp[-3].rule_type).id, (yyvsp[-4].string), 0, 1);
			if(semantic_error==0){
				insert_symbol((yyvsp[-3].rule_type).id, "function", (yyvsp[-4].string), depth, "", 0);
			}
		}

	}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 462 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(cur_table){
			lookup_symbol((yyvsp[-4].rule_type).id, (yyvsp[-5].string), 0, 1);
			if(semantic_error==0){
				insert_symbol((yyvsp[-4].rule_type).id, "function", (yyvsp[-5].string), depth, param, 0);
			}
		}
		else{
			cur_table = create_symbol((yyvsp[-4].rule_type).id, "function", (yyvsp[-5].string), "", 0);
		}
		param_item *t = p_item;
		param_item *next;
		while(t!=NULL){
			next = t->next;
			free(t);
			t = next;
		}
		p_item = NULL;


		
	}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 488 "compiler_hw3.y" /* yacc.c:1646  */
    {
	}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 493 "compiler_hw3.y" /* yacc.c:1646  */
    {
	}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 501 "compiler_hw3.y" /* yacc.c:1646  */
    {
		depth++;
	}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 507 "compiler_hw3.y" /* yacc.c:1646  */
    {
		//printf("%d: %s",yylineno, buf);
		//printf("-----");
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
		//dump_symbol();
		flag = 0;
		endline_dump = 1;
		do_depth = depth;
		depth--;
	}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 521 "compiler_hw3.y" /* yacc.c:1646  */
    {
	/*	param_item *t = p_item;
		while(t!=NULL){
			printf("t = %s\n", t->name);
			t = t->next;
		}*/
	}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 532 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(p_item == NULL){
			p_item = malloc(sizeof(param_item));
			p_item->next = NULL;
			strcpy(p_item->name, (yyvsp[0].rule_type).id);
			strcpy(p_item->type, (yyvsp[-1].string));
		}
		else{
			param_item *new = malloc(sizeof(param_item));
			new->next = NULL;
			strcpy(new->name, (yyvsp[0].rule_type).id);
			strcpy(new->type, (yyvsp[-1].string));

			param_item *temp = p_item;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = new;
		}
		//insert_symbol($4, "parameter", $3, depth+1, "");
		if(strlen(param)==0){
			strcat(param, (yyvsp[-1].string));
		}
		else{
			strcat(param, ", ");
			strcat(param, (yyvsp[-1].string));
		}
		//debug
		/*Entry *temp = cur_table->root;
		  while(temp!=NULL){
		  printf("temp = %s %d %d\n", temp->name, temp->index, temp->depth);
		  temp = temp->next;
		  }*/
	}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 566 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(p_item == NULL){
			p_item = malloc(sizeof(param_item));
			p_item->next = NULL;
			strcpy(p_item->name, (yyvsp[0].rule_type).id);
			strcpy(p_item->type, (yyvsp[-1].string));
		}
		else{
			param_item *new = malloc(sizeof(param_item));
			new->next = NULL;
			strcpy(new->name, (yyvsp[0].rule_type).id);
			strcpy(new->type, (yyvsp[-1].string));

			param_item *temp = p_item;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = new;
		}
		//insert_symbol($2, "parameter", $1, depth+1, "");
		if(strlen(param)==0){
			strcat(param, (yyvsp[-1].string));
		}
		else{
			strcat(param, ", ");
			strcat(param, (yyvsp[-1].string));
		}
	}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 597 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].rule_type).type == FLOAT_t && (yyvsp[0].rule_type).type == INT_t){
			fprintf(file, "i2f\n");
			fprintf(file, "fadd\n");
			(yyval.rule_type).type = FLOAT_t;
		}
		else if((yyvsp[-2].rule_type).type == INT_t && (yyvsp[0].rule_type).type == FLOAT_t){
			fprintf(file, "swap\n");
			fprintf(file, "i2f\n");
			fprintf(file, "fadd\n");
			(yyval.rule_type).type = FLOAT_t;
		}
		else if((yyvsp[-2].rule_type).type == INT_t && (yyvsp[0].rule_type).type == INT_t){
			fprintf(file, "iadd\n");
			(yyval.rule_type).type = INT_t;
		}
		else{
			fprintf(file, "fadd\n");
			(yyval.rule_type).type = FLOAT_t;
		}

	}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 619 "compiler_hw3.y" /* yacc.c:1646  */
    {
	if((yyvsp[-2].rule_type).type == FLOAT_t && (yyvsp[0].rule_type).type == INT_t){
			fprintf(file, "i2f\n");
			fprintf(file, "fsub\n");
			(yyval.rule_type).type = FLOAT_t;
		}
		else if((yyvsp[-2].rule_type).type == INT_t && (yyvsp[0].rule_type).type == FLOAT_t){
			fprintf(file, "swap\n");
			fprintf(file, "i2f\n");
			fprintf(file, "fsub\n");
			(yyval.rule_type).type = FLOAT_t;
		}
		else if((yyvsp[-2].rule_type).type == INT_t && (yyvsp[0].rule_type).type == INT_t){
			fprintf(file, "isub\n");
			(yyval.rule_type).type = INT_t;
		}
		else{
			fprintf(file, "fsub\n");
			(yyval.rule_type).type = FLOAT_t;
		}

}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 641 "compiler_hw3.y" /* yacc.c:1646  */
    {
	(yyval.rule_type) = (yyvsp[0].rule_type);
}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 647 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].rule_type).type == FLOAT_t && (yyvsp[0].rule_type).type == INT_t){
			fprintf(file, "i2f\n");
			fprintf(file, "fmul\n");
			(yyval.rule_type).type = FLOAT_t;
		}
		else if((yyvsp[-2].rule_type).type == INT_t && (yyvsp[0].rule_type).type == FLOAT_t){
			fprintf(file, "swap\n");
			fprintf(file, "i2f\n");
			fprintf(file, "fmul\n");
			(yyval.rule_type).type = FLOAT_t;
		}
		else if((yyvsp[-2].rule_type).type == INT_t && (yyvsp[0].rule_type).type == INT_t){
			fprintf(file, "imul\n");
			(yyval.rule_type).type = INT_t;
		}
		else{
			fprintf(file, "fmul\n");
			(yyval.rule_type).type = FLOAT_t;
		}
	}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 668 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if((yyvsp[0].rule_type).type == FLOAT_t){
			if((yyvsp[0].rule_type).f_val == 0){
				semantic_error = 1;
				acc_semantic++;
				strcpy(semantic_msg, "Divide by zero\n");
			}
		}
		else if((yyvsp[0].rule_type).type == INT_t){
			if((yyvsp[0].rule_type).i_val == 0){
				semantic_error = 1;
				acc_semantic++;
				strcpy(semantic_msg, "Divide by zero\n");
			}
		}
		if((yyvsp[-2].rule_type).type == FLOAT_t && (yyvsp[0].rule_type).type == INT_t){
			fprintf(file, "i2f\n");
			fprintf(file, "fdiv\n");
			(yyval.rule_type).type = FLOAT_t;
		}
		else if((yyvsp[-2].rule_type).type == INT_t && (yyvsp[0].rule_type).type == FLOAT_t){
			fprintf(file, "swap\n");
			fprintf(file, "i2f\n");
			fprintf(file, "fdiv\n");
			(yyval.rule_type).type = FLOAT_t;
		}
		else if((yyvsp[-2].rule_type).type == INT_t && (yyvsp[0].rule_type).type == INT_t){
			fprintf(file, "idiv\n");
			(yyval.rule_type).type = INT_t;
		}
		else{
			fprintf(file, "fdiv\n");
			(yyval.rule_type).type = FLOAT_t;
		}

	}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 704 "compiler_hw3.y" /* yacc.c:1646  */
    {

		if((yyvsp[-2].rule_type).type == INT_t && (yyvsp[0].rule_type).type == INT_t){
			if((yyvsp[0].rule_type).i_val == 0){
				semantic_error = 1;
				acc_semantic++;
				strcpy(semantic_msg, "Module operator with float poinr operands\n");
			}
			else{
				fprintf(file, "irem\n");
				(yyval.rule_type).type = INT_t;
			}
		}
		else{
			semantic_error = 1;
			acc_semantic++;
			strcpy(semantic_msg, "Divide by zero\n");
		}
	}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 723 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.rule_type) = (yyvsp[0].rule_type);
	}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 726 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.rule_type) = (yyvsp[-1].rule_type);
	}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 732 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyvsp[0].rule_type).type = INT_t;
		if(depth!=0){
			strcpy(cur_init, yytext);
			fprintf(file,"ldc %s\n", cur_init);
		}
		else{
			strcpy(cur_init, yytext);
		}

		if(function == 1){
			strcat(param_call_type, "I");
		}
		
		(yyval.rule_type) = (yyvsp[0].rule_type);
	}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 748 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyvsp[0].rule_type).type = INT_t;
		if(depth!=0){
			strcpy(cur_init, yytext);
			fprintf(file,"ldc -%s\n", cur_init);
		}
		else{
			strcpy(cur_init, yytext);
		}

		if(function == 1){
			strcat(param_call_type, "I");
		}
		
		(yyvsp[0].rule_type).i_val = -(yyvsp[0].rule_type).i_val;
		(yyval.rule_type) = (yyvsp[0].rule_type);
	}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 765 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyvsp[0].rule_type).type = FLOAT_t;
		if(depth!=0){
			strcpy(cur_init, yytext);
			fprintf(file,"ldc %s\n", cur_init);
		}
		else{
			strcpy(cur_init, yytext);
		}
		
		if(function == 1){
			strcat(param_call_type, "F");
		}
		(yyval.rule_type) = (yyvsp[0].rule_type);
	}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 780 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyvsp[0].rule_type).type = FLOAT_t;
		if(depth!=0){
			strcpy(cur_init, yytext);
			fprintf(file,"ldc -%s\n", cur_init);
		}
		else{
			strcpy(cur_init, yytext);
		}

		if(function == 1){
			strcat(param_call_type, "F");
		}
		
		(yyvsp[0].rule_type).f_val = -(yyvsp[0].rule_type).f_val;
		(yyval.rule_type) = (yyvsp[0].rule_type);
	}
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 797 "compiler_hw3.y" /* yacc.c:1646  */
    {
		lookup_symbol((yyvsp[0].rule_type).id, "", 1, 0);
		int stack_num = get_stack_num((yyvsp[0].rule_type).id, depth);
		/*for global*/
		if(stack_num == 0){
			fprintf(file, "getstatic compiler_hw3/%s I\n", (yyvsp[0].rule_type).id);
			if(!strcmp(get_type((yyvsp[0].rule_type).id, depth), "float")){
				(yyvsp[0].rule_type).type = FLOAT_t;
				(yyvsp[0].rule_type).f_val = get_f_num((yyvsp[0].rule_type).id);
			}
			else{
				(yyvsp[0].rule_type).type = INT_t;
				(yyvsp[0].rule_type).i_val = get_i_num((yyvsp[0].rule_type).id);
			}
		}
		else{
			if(!strcmp(get_type((yyvsp[0].rule_type).id, depth), "float")){
				fprintf(file, "fload %d\n", stack_num-1);
				(yyval.rule_type).type = FLOAT_t;
				(yyvsp[0].rule_type).type = FLOAT_t;
				(yyvsp[0].rule_type).f_val = get_f_num((yyvsp[0].rule_type).id);
			}
			else{
				fprintf(file, "iload %d\n", stack_num-1);
				(yyvsp[0].rule_type).type = INT_t;
				(yyvsp[0].rule_type).i_val = get_i_num((yyvsp[0].rule_type).id);
			}
		}
		if(function == 1){
			strcat(param_call_type, type_tran(get_type((yyvsp[0].rule_type).id, depth)));
		}
		(yyval.rule_type) = (yyvsp[0].rule_type);
	}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 832 "compiler_hw3.y" /* yacc.c:1646  */
    {function = 1;}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 832 "compiler_hw3.y" /* yacc.c:1646  */
    {
		lookup_symbol((yyvsp[-4].rule_type).id, "", 1, 1);
		char type[15] = {0};
		strcpy(type, get_param((yyvsp[-4].rule_type).id));
		int i, j;
		char c;
	//	check_param($1.id, param_call_type);
		fprintf(file, "invokestatic compiler_hw3/%s\n", get_param((yyvsp[-4].rule_type).id));
	}
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 841 "compiler_hw3.y" /* yacc.c:1646  */
    {
		lookup_symbol((yyvsp[-2].rule_type).id, "", 1, 1);
		fprintf(file, "invokestatic compiler_hw3/%s\n", get_param((yyvsp[-2].rule_type).id));
	}
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 846 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.rule_type).i_val = 1;
		(yyval.rule_type).type = BOOL_t;
		if(depth!=0){
			fprintf(file, "ldc 1\n");
		}
	}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 853 "compiler_hw3.y" /* yacc.c:1646  */
    {
		(yyval.rule_type).i_val = 0;
		(yyval.rule_type).type = BOOL_t;
		if(depth!=0){
			fprintf(file, "ldc 0\n");
		}
	}
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 875 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].rule_type).type == INT_t){
			fprintf(file, "isub\n");
		}
		else{
			fprintf(file, "fsub\n");
			fprintf(file, "f2i\n");
		}
	}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 885 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int stack_num = get_stack_num((yyvsp[-2].rule_type).id, depth);
		if(stack_num == 0){
			if(!strcmp(get_type((yyvsp[-2].rule_type).id, depth), "float")){
				fprintf(file, "getstatic compiler_hw3/%s F\n", (yyvsp[-2].rule_type).id);
				(yyvsp[-2].rule_type).type = FLOAT_t;
				(yyvsp[-2].rule_type).f_val = (yyvsp[0].rule_type).f_val;
			}
			else{
				fprintf(file, "getstatic compiler_hw3/%s I\n", (yyvsp[-2].rule_type).id);
				(yyvsp[-2].rule_type).type = INT_t;
				(yyvsp[-2].rule_type).i_val = (yyvsp[0].rule_type).i_val;
			}
			
		}
		else{
			fprintf(file, "iload %d", stack_num-1);
		}
	}
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 905 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int stack_num = get_stack_num((yyvsp[-1].rule_type).id, depth);
		fprintf(file, "iload %d\n", stack_num-1); 
	}
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 922 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup("int"); }
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 923 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup("float");}
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 924 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup("bool"); }
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 925 "compiler_hw3.y" /* yacc.c:1646  */
    {  (yyval.string) = strdup("string"); }
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 926 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup("void"); }
#line 2481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 935 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(compare_type, ">");
	}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 938 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(compare_type, "<");
	}
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 941 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(compare_type, ">=");
	}
#line 2505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 944 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(compare_type, "<=");
	}
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 947 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(compare_type, "!=");
	}
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 950 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(compare_type, "==");
	}
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 956 "compiler_hw3.y" /* yacc.c:1646  */
    { //cur_init_f = $1;
			strcpy(cur_init, yytext);
				}
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 959 "compiler_hw3.y" /* yacc.c:1646  */
    { //cur_init_f = $1; }
			strcpy(cur_init, yytext);
			}
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 965 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(arith_choose, "INC");
	}
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 968 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(arith_choose, "DEC");
	}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 972 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(arith_choose, "ADD_ASSIGN");
		(yyval.rule_type).type = (yyvsp[0].rule_type).type;
		if((yyvsp[0].rule_type).type == FLOAT_t){
			(yyval.rule_type).f_val = (yyvsp[0].rule_type).f_val;
		}
		else{
			(yyval.rule_type).i_val = (yyvsp[0].rule_type).i_val;
		}
	}
#line 2576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 982 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(arith_choose, "SUB_ASSIGN");
		(yyval.rule_type).type = (yyvsp[0].rule_type).type;
		if((yyvsp[0].rule_type).type == FLOAT_t){
			(yyval.rule_type).f_val = (yyvsp[0].rule_type).f_val;
		}
		else{
			(yyval.rule_type).i_val = (yyvsp[0].rule_type).i_val;
		}
	}
#line 2591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 993 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(arith_choose, "MUL_ASSIGN");
		(yyval.rule_type).type = (yyvsp[0].rule_type).type;
		if((yyvsp[0].rule_type).type == FLOAT_t){
			(yyval.rule_type).f_val = (yyvsp[0].rule_type).f_val;
		}
		else{
			(yyval.rule_type).i_val = (yyvsp[0].rule_type).i_val;
		}
	}
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1003 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(arith_choose, "DIV_ASSIGN");
		(yyval.rule_type).type = (yyvsp[0].rule_type).type;
		if((yyvsp[0].rule_type).type == FLOAT_t){
			(yyval.rule_type).f_val = (yyvsp[0].rule_type).f_val;
		}
		else{
			(yyval.rule_type).i_val = (yyvsp[0].rule_type).i_val;
		}
	}
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1013 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(arith_choose, "MOD_ASSIGN");
		(yyval.rule_type).type = (yyvsp[0].rule_type).type;
		if((yyvsp[0].rule_type).type == FLOAT_t){
			(yyval.rule_type).f_val = (yyvsp[0].rule_type).f_val;
		}
		else{
			(yyval.rule_type).i_val = (yyvsp[0].rule_type).i_val;
		}
	}
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1026 "compiler_hw3.y" /* yacc.c:1646  */
    {
		lookup_symbol((yyvsp[-2].rule_type).id, "", 1, 0);	
		int stack_num = get_stack_num((yyvsp[-2].rule_type).id, depth);
		if(!strcmp(get_type((yyvsp[-2].rule_type).id, depth), "float")){
			(yyvsp[-2].rule_type).type = FLOAT_t;
			fprintf(file, "fload %d\n", stack_num-1);
		}
		else{
			(yyvsp[-2].rule_type).type = INT_t;
			fprintf(file, "iload %d\n", stack_num-1);
		}
		
		/*for global*/
		if(stack_num == -1){
			/*wait to handle*/
		}
		else{
			if(!strcmp(arith_choose, "INC")){
				fprintf(file, "ldc 1\n");
				if((yyvsp[-2].rule_type).type == FLOAT_t){
					fprintf(file , "i2f\n");
					fprintf(file, "fadd\n");
					fprintf(file, "fstore ");
				}
				else{
					fprintf(file, "iadd\n");
					fprintf(file, "istore ");
				}
				int stack_num = get_stack_num((yyvsp[-2].rule_type).id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
			else if(!strcmp(arith_choose, "DEC")){
				fprintf(file, "ldc 1\n");
				if((yyvsp[-2].rule_type).type == FLOAT_t){
					fprintf(file , "i2f\n");
					fprintf(file, "fsub\n");
					fprintf(file, "fstore ");
				}
				else{
					fprintf(file, "ldc 1\n");
					fprintf(file, "isub\n");
					fprintf(file, "istore ");
				}
				int stack_num = get_stack_num((yyvsp[-2].rule_type).id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
			else if(!strcmp(arith_choose, "ADD_ASSIGN")){
				if((yyvsp[-2].rule_type).type == INT_t){
					if((yyvsp[-1].rule_type).type == INT_t){
						fprintf(file, "iadd\n");
						fprintf(file, "istore ");
					}
					else{
						fprintf(file ,"i2f\n");
						fprintf(file, "fadd\n");
						fprintf(file, "f2i\n");
						fprintf(file, "istore ");
					}
				}
				else{
					if((yyvsp[-1].rule_type).type == INT_t){
						fprintf(file, "swap\n");
						fprintf(file, "i2f\n");
						fprintf(file, "fadd\n");
						fprintf(file, "fstore ");
					}
					else{
						fprintf(file, "fadd\n");
						fprintf(file, "fstore ");
						
					}
				}
				int stack_num = get_stack_num((yyvsp[-2].rule_type).id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
			else if(!strcmp(arith_choose, "SUB_ASSIGN")){
				if((yyvsp[-2].rule_type).type == INT_t){
					if((yyvsp[-1].rule_type).type == INT_t){
						fprintf(file, "swap\n");
						fprintf(file, "isub\n");
						fprintf(file, "istore ");
					}
					else{
						fprintf(file ,"i2f\n");
						fprintf(file, "swap\n");
						fprintf(file, "fsub\n");
						fprintf(file, "f2i\n");
						fprintf(file, "istore ");
					}
				}
				else{
					if((yyvsp[-1].rule_type).type == INT_t){
						fprintf(file, "swap\n");
						fprintf(file, "i2f\n");
						fprintf(file, "swap\n");
						fprintf(file, "fsub\n");
						fprintf(file, "fstore ");
					}
					else{
						fprintf(file, "swap\n");
						fprintf(file, "fsub\n");
						fprintf(file, "fstore ");
						
					}
				}
				int stack_num = get_stack_num((yyvsp[-2].rule_type).id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
			else if(!strcmp(arith_choose, "MUL_ASSIGN")){
				if((yyvsp[-2].rule_type).type == INT_t){
					if((yyvsp[-1].rule_type).type == INT_t){
						fprintf(file, "imul\n");
						fprintf(file, "istore ");
					}
					else{
						fprintf(file ,"i2f\n");
						fprintf(file, "fmul\n");
						fprintf(file, "f2i\n");
						fprintf(file, "istore ");
					}
				}
				else{
					if((yyvsp[-1].rule_type).type == INT_t){
						fprintf(file, "swap\n");
						fprintf(file, "i2f\n");
						fprintf(file, "fmul\n");
						fprintf(file, "fstore ");
					}
					else{
						fprintf(file, "fmul\n");
						fprintf(file, "fstore ");
						
					}
				}
				int stack_num = get_stack_num((yyvsp[-2].rule_type).id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);

			}
			else if(!strcmp(arith_choose, "DIV_ASSIGN")){
				if((yyvsp[-2].rule_type).type == FLOAT_t){
					if((yyvsp[-1].rule_type).type == INT_t){
						if((yyvsp[-1].rule_type).i_val == 0){
							semantic_error = 1;
							acc_semantic++;
							strcpy(semantic_msg, "Divide by zero\n");
						}
						else{
							fprintf(file, "swap\n");
							fprintf(file, "i2f\n");
							fprintf(file, "fdiv\n");
							fprintf(file, "fstore ");
						}
					}
					else{
						if((yyvsp[-1].rule_type).f_val == 0){
							semantic_error = 1;
							acc_semantic++;
						}
						else{
							fprintf(file, "swap\n");
							fprintf(file, "fdiv\n");
							fprintf(file, "fstore ");
						}
					}
				}
				else{
					if((yyvsp[-1].rule_type).type == INT_t){
						if((yyvsp[-1].rule_type).i_val == 0){
							semantic_error = 1;
							acc_semantic++;
							strcpy(semantic_msg, "Divide by zero\n");
						}
						else{
							fprintf(file, "swap\n");
							fprintf(file, "idiv\n");
							fprintf(file, "istore ");
						}
					}
					else{
						if((yyvsp[-1].rule_type).f_val == 0){
							semantic_error = 1;
							acc_semantic++;
						}
						else{
							fprintf(file, "i2f\n");
							fprintf(file, "swap\n");
							fprintf(file, "fdiv\n");
							fprintf(file, "f2i\n");
							fprintf(file, "istore ");
						}
					}

				}
				int stack_num = get_stack_num((yyvsp[-2].rule_type).id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
			else if(!strcmp(arith_choose, "MOD_ASSIGN")){
				if((yyvsp[-2].rule_type).type == INT_t && (yyvsp[-1].rule_type).type == INT_t){
					if((yyvsp[-1].rule_type).i_val == 0){
						semantic_error = 1;
						acc_semantic++;
						strcpy(semantic_msg, "Divide by zero\n");
					}
					fprintf(file, "swap\n");
					fprintf(file, "irem\n");
					fprintf(file, "istore ");
				}
				else{
					semantic_error = 1;
					acc_semantic++;
					strcpy(semantic_msg, "Module operator with float poinr operands\n");
				}
				int stack_num = get_stack_num((yyvsp[-2].rule_type).id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
		}
	}
#line 2872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1257 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "ireturn\n");
	}
#line 2880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1260 "compiler_hw3.y" /* yacc.c:1646  */
    {
		strcpy(if_else_label, "goto EXIT_0\n");
		fprintf(file, "return\n");
	}
#line 2889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1264 "compiler_hw3.y" /* yacc.c:1646  */
    {
		lookup_symbol((yyvsp[-1].rule_type).id, "", 1, 0);
		int stack_num = get_stack_num((yyvsp[-1].rule_type).id, depth);
		fprintf(file, "iload %d\n", stack_num-1);
		fprintf(file, "ireturn\n");
	}
#line 2900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1270 "compiler_hw3.y" /* yacc.c:1646  */
    {
		lookup_symbol((yyvsp[-2].rule_type).id, "", 1, 0);
		fprintf(file, "return\n");
	}
#line 2909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1274 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "return\n");
	}
#line 2917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1277 "compiler_hw3.y" /* yacc.c:1646  */
    {
		lookup_symbol((yyvsp[-3].rule_type).id, "", 1, 0);
		int stack_num = get_stack_num((yyvsp[-3].rule_type).id, depth);
		//printf("stack_num = %d\n", stack_num);
		if(stack_num == 0){
			if(!strcmp(get_type((yyvsp[-3].rule_type).id, depth), "float")){
				fprintf(file, "putstatic compiler_hw3/%s F\n", (yyvsp[-3].rule_type).id);
				//$$.type = FLOAT_t;
			}
			else{
				fprintf(file, "putstatic compiler_hw3/%s I\n", (yyvsp[-3].rule_type).id);
			//	$$.type = INT_t;
			}
		}
		else{
			int stack_num = get_stack_num((yyvsp[-3].rule_type).id, depth);
			if(!strcmp(get_type((yyvsp[-3].rule_type).id, depth), "float")){
				if((yyvsp[-1].rule_type).type == FLOAT_t){
					fprintf(file, "fstore %d\n", stack_num-1);
				}
				else{
					fprintf(file, "i2f\n");
					fprintf(file, "fstore %d\n", stack_num-1);
				}
			}
			else{
				if((yyvsp[-1].rule_type).type == FLOAT_t){
					fprintf(file, "f2i\n");
					fprintf(file, "istore %d\n", stack_num-1);
				}
				else{
					fprintf(file, "istore %d\n", stack_num-1);
				}
			}
		}
}
#line 2958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1314 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		lookup_symbol((yyvsp[-3].rule_type).id, "", 1, 1);
		char type[15] = {0};
		strcpy(type, get_param((yyvsp[-3].rule_type).id));
		fprintf(file, "invokestatic compiler_hw3/%s\n", get_param((yyvsp[-3].rule_type).id));
	}
#line 2969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1320 "compiler_hw3.y" /* yacc.c:1646  */
    {
		lookup_symbol((yyvsp[-3].rule_type).id, "", 1, 1);
		fprintf(file, "invokestatic compiler_hw3/%s()%s\n", (yyvsp[-3].rule_type).id, get_type((yyvsp[-3].rule_type).id, 0));
	}
#line 2978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1328 "compiler_hw3.y" /* yacc.c:1646  */
    {
		Entry *temp = cur_table->root;
		int get = 0;
		while(temp->next!=NULL){
			if(temp->depth <= depth){
				if(!strcmp(temp->name, (yyvsp[0].rule_type).id)){
					get = 1;
					break;
				}
			}
			temp = temp->next;
		}
		if(get == 0){
			semantic_error = 1;
			strcpy(semantic_msg, "Undeclared variable");
			strcat(semantic_msg, " ");
			strcat(semantic_msg, (yyvsp[0].rule_type).id);
		}

	}
#line 3003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1356 "compiler_hw3.y" /* yacc.c:1646  */
    {
		lookup_symbol((yyvsp[-2].rule_type).id, "", 1, 0);
		
		int stack_num = get_stack_num((yyvsp[-2].rule_type).id, depth);
		if(!strcmp(get_type((yyvsp[-2].rule_type).id, depth), "float")){
			if(stack_num == 0){
				fprintf(file, "getstatic compiler_hw3/%s F\n", (yyvsp[-2].rule_type).id);
			}
			else{
				fprintf(file, "fload %d\n", stack_num-1);
			}
			fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(F)V\n");
		}
		else if(!strcmp(get_type((yyvsp[-2].rule_type).id, depth), "string")){
			fprintf(file, "aload %d\n", stack_num-1);
			fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
		}
		else{
			if(stack_num == 0){
				fprintf(file, "getstatic compiler_hw3/%s I\n", (yyvsp[-2].rule_type).id);
			}
			else{
				fprintf(file, "iload %d\n", stack_num-1);
			}

			fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
		}
	}
#line 3036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1384 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "ldc \"%s\"\n", (yyvsp[-2].rule_type).string);
		fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
	}
#line 3045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1388 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char I[10] = {0};
		sprintf(I, "%d", (yyvsp[-2].rule_type).i_val);
		fprintf(file, "ldc %s\n", I);
		fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
	}
#line 3056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1394 "compiler_hw3.y" /* yacc.c:1646  */
    {
	
		char I[10] = {0};
		sprintf(I, "%f", (yyvsp[-2].rule_type).f_val);
		fprintf(file, "ldc %s\n", I);
		fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(F)V\n");
	}
#line 3068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1407 "compiler_hw3.y" /* yacc.c:1646  */
    {
	}
#line 3075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1408 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(!strcmp(compare_type, ">")){
			fprintf(file, "ifle LABEL_%d_%d\n", compare_num, depth);
			
		}
		else if(!strcmp(compare_type, "<")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "ifge LABEL_%d_%d\n", compare_num, depth);
		}
		else if(!strcmp(compare_type, "==")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "ifne LABEL_%d_%d\n", compare_num, depth);
		}
		else if(!strcmp(compare_type, ">=")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "iflt LABEL_%d_%d\n", compare_num, depth);
		}
		else if(!strcmp(compare_type, "<=")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "ifgt LABEL_%d_%d\n", compare_num, depth);
		}

	}
#line 3107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1434 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "goto EXIT_0\n");
		fprintf(file, "LABEL_%d_%d:\n", compare_num, depth);
		compare_num++;
		if_else_flag = 1;
	}
#line 3118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1441 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(if_else_flag == 1){
		}
	}
#line 3127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1444 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(!strcmp(compare_type, ">")){
			fprintf(file, "ifle LABEL_%d_%d\n", compare_num, depth);
			
		}
		else if(!strcmp(compare_type, "<")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "ifge LABEL_%d_%d\n", compare_num, depth);
		}
		else if(!strcmp(compare_type, "==")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "ifne LABEL_%d_%d\n", compare_num, depth);
		}
		else if(!strcmp(compare_type, ">=")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "iflt LABEL_%d_%d\n", compare_num, depth);
		}
		else if(!strcmp(compare_type, "<=")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "ifgt LABEL_%d_%d\n", compare_num, depth);
		}

	}
#line 3159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1470 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "LABEL_%d_%d:\n", compare_num, depth);
		compare_num++;
	}
#line 3168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1475 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "goto EXIT_0\n");
		fprintf(file, "LABEL_%d_%d:\n", compare_num, depth);
	}
#line 3177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1478 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "EXIT_0:\n");
	}
#line 3185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1484 "compiler_hw3.y" /* yacc.c:1646  */
    {
		while_num++;
		fprintf(file, "LABEL_BEGIN%d:\n", while_num);
	}
#line 3194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1488 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(!strcmp(compare_type, ">")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "ifle LABEL_%d_%d\n", while_num, depth);
			
		}
		else if(!strcmp(compare_type, "<")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "ifge LABEL_%d_%d\n", while_num, depth);
		}
		else if(!strcmp(compare_type, "==")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "ifne LABEL_%d_%d\n", while_num, depth);
		}
		else if(!strcmp(compare_type, ">=")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "iflt LABEL_%d_%d\n", while_num, depth);
		}
		else if(!strcmp(compare_type, "<=")){
			char conv[10] = {0};
			sprintf(conv, "%d", compare_num);
			fprintf(file, "ifgt LABEL_%d_%d\n", while_num, depth);
		}

		//fprintf(file, "goto LABEL_FALSE_%d_%d", while_num, depth);
		
	}
#line 3230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1518 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char conv[10] = {0};
		fprintf(file, "goto LABEL_BEGIN%d\n", while_num);
		fprintf(file, "LABEL_%d_%d:\n", while_num, depth);
		while_num--;
	
	}
#line 3242 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3246 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1527 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
    file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");
                   // ".method public static main([Ljava/lang/String;)V\n");
	
	strcat(if_else_label, "goto EXIT_0\n");
    yyparse();
	if(acc_semantic>0){
		remove("compiler_hw3.j");
	}

	flag = 0;
	do_depth = 0;
		dump_symbol();
		printf("\nTotal lines: %d \n",yylineno);
/*
    fprintf(file, "\treturn\n"
                  ".end method\n");
*/
    fclose(file);

    return 0;
}

/*
void yyerror()
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("\n| Unmatched token: %s", yytext);
    printf("\n|-----------------------------------------------|\n");
    exit(-1);
}*/

void yyerror(char *s)
{
	ERROR = 1;
}

void test(){
	printf("\n|-----------------------------------------------|\n");
	printf("| Error found in line %d: %s\n", yylineno, buf);
	printf("| %s", "syntax error");
	printf("\n|-----------------------------------------------|\n\n");
}

void semantic(char msg[]){
	printf("\n|-----------------------------------------------|\n");
	printf("| Error found in line %d: %s\n", yylineno, buf);
	printf("| %s", msg);
	printf("\n|-----------------------------------------------|\n\n");
}

Header* create_symbol(char name[], char entry_type[], char data_type[], char att[], int func_def) {

	Header *H = malloc(sizeof(Header));
	H->root = malloc(sizeof(Entry));
	H->root->next = NULL;
	//printf("Create a symbol table with depth = %d\n", H->depth);
	H->tail = H->root;
	H->pre = NULL;
	H->root->index = 0;
	H->root->depth = depth;
	H->root->R_N = 0;
	strcpy(H->root->name, name);
	strcpy(H->root->E_T, entry_type);
	strcpy(H->root->D_T, data_type);
	strcpy(H->root->attr, att);
	strcpy(H->root->s_const, "");
	H->root->func_def = func_def;
	return H;
}

void insert_symbol(char name[], char entry_type[], char data_type[], int D, char att[], int func_def) {

	Entry *ptr = cur_table->root;
	Entry *temp = ptr;
	Entry *new = malloc(sizeof(Entry));
	int i = 0;
	while(ptr != NULL){
		temp = ptr;
		i = ptr->index;
		ptr = ptr->next;
	}
	new->index = i+1;
	new->depth = D;
	temp->next = new;
	new->next = NULL;
	strcpy(new->name, name);
	strcpy(new->E_T, entry_type);
	strcpy(new->D_T, data_type);
	strcpy(new->attr, att);
	strcpy(new->s_const, "");
	new->func_def = func_def;
	if(!strcmp(new->E_T, "variable") && depth != 0){
		new->R_N = temp->R_N + 1;
	}
	else if( !strcmp(new->E_T, "parameter")){
		new->R_N = temp->R_N + 1;
	}
	else{
		new->R_N = 0;
	}
	return;
}


int lookup_symbol(char name[], char type[], int choose, int choose_type) {

	if(choose == 1){//Undeclared
		Entry *temp = cur_table->root;
		int get = 0;
		while(temp!=NULL){
			if(temp->depth <= depth){
				if(!strcmp(temp->name, name)){
					get = 1;
					break;
				}
			}
			temp = temp->next;
		}
		if(get == 0){
			semantic_error = 1;
			acc_semantic++;	
			if(choose_type == 0){
				strcpy(semantic_msg, "Undeclared variable");
			}
			else{
				strcpy(semantic_msg, "Undeclared function");
			}
			strcat(semantic_msg, " ");
			strcat(semantic_msg, name);
		}
	}
	else{//Redeclared
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(!strcmp(temp->name, name) && temp->depth == depth){
				if(temp->func_def == 1){
					semantic_error = 1;
					acc_semantic++;	
					if(choose_type == 0){
						strcpy(semantic_msg, "Redeclared variable");
					}
					else{
						strcpy(semantic_msg, "Redeclared function");
					}
					strcat(semantic_msg, " ");
					strcat(semantic_msg, name);
				}
				else{
					temp->func_def = 1;
					strcpy(func_type, temp->D_T);
				}
			}
			temp = temp->next;
		}
	}
}

void dump_symbol() {
	if(cur_table){
		Entry *temp = cur_table->root;
		Entry *pre = NULL;
		num = 0;
		int do_dump = 0;
		while(temp!=NULL){
			if(temp->depth==do_depth){
				do_dump = 1;
				break;
			}
			temp = temp->next;
		}
		temp = cur_table->root;
		if(do_dump){
			while(temp!=NULL){
				if(flag == 0){
					printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
							"Index", "Name", "Kind", "Type", "Scope", "Attribute");
					flag = 1;
				}
				if(temp->depth == do_depth){
					if(!strcmp(temp->attr, "")){
					printf("%-10d%-10s%-12s%-10s%-10d\n",
							num, temp->name, temp->E_T, temp->D_T, temp->depth);
					}
					else{
						printf("%-10d%-10s%-12s%-10s%-10d%s\n",
								num, temp->name, temp->E_T, temp->D_T, temp->depth, temp->attr);
					}
					num++;
				}
				temp = temp->next;
			}
			printf("\n");
			/*delete*/
			int Time = num;
			while(Time > 0){
				temp = cur_table->root;
				while(temp != NULL){
					if(temp->depth == do_depth){
						break;
					}
					pre = temp;
					temp = temp->next;
				}
				if(temp == cur_table->root){
					cur_table->root = temp->next;
					free(temp);
				}
				else{
					pre->next = temp->next;
					free(temp);
				}
				Time--;
			}
		}
	}
}

/*get stack number*/
int get_stack_num(char name[], int D){
	if(cur_table){	
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(!strcmp(temp->name, name) && temp->depth<=D){
				if(temp->depth == 0){
					return 0;
				}
				return temp->R_N;	
			}
			temp = temp->next;
		}
		return -1;
	}
}

char *get_type(char name[], int D){

	if(cur_table){
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(!strcmp(temp->name, name) && temp->depth <= D){
				return temp->D_T;
			}
			temp = temp->next;
		}
		return "";
	}

}

char *type_tran(char type[]){

	
	if(!strcmp(type, "int")){
		return "I";			
	}
	else if(!strcmp(type, "float")){
		return "F";
	}
	else if(!strcmp(type, "bool")){
		return "Z";
	}
	else if(!strcmp(type, "void")){
		return "V";
	}
}

char *get_param(char name[]){
	if(cur_table){
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(!strcmp(temp->name, name)){
				return temp->func_assem;
			}
			temp = temp->next;
		}
		return "";
	}

}

void renew_func(char name[], char func[], char type[]){
	if(cur_table){
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(!strcmp(temp->name, name) && temp->depth == 0){
				strcpy(temp->func_assem, func);
				strcpy(temp->func_param_type, type);
				return;
			}
			temp = temp->next;
		}
		return;
	}

}

int check_float(char num[]){
	int i=0;
	for(i=0;i<strlen(num);i++){
		if(num[i]=='.'){
			return 1;
		}
	}
	return 0;
}

void check_param(char name[], char param[]){
	if(cur_table){
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(!strcmp(temp->name, name) && temp->depth == 0){
				if(strlen(temp->func_param_type) != strlen(param)){
					semantic_error = 1;
					acc_semantic++;	
					if(RT_FP == 1){
						strcat(semantic_msg, "function formal parameter is not the same");
					}
					else{
						strcpy(semantic_msg, "function formal parameter is not the same");
					}
					return;

				}
				else if(strcmp(temp->func_param_type, param)){
					semantic_error = 1;
					acc_semantic++;	
					if(RT_FP == 1){
						strcat(semantic_msg, "function formal parameter is not the same");
					}
					else{
						strcpy(semantic_msg, "function formal parameter is not the same");
					}
					return;
				}
				return;
			}
			temp = temp->next;
		}
	}

}

void renew_ID(char name[], float num){
	if(cur_table){
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(!strcmp(temp->name, name)){
				if(!strcmp(temp->D_T, "float")){	
					temp->f_num = num;
				}
				else if(!strcmp(temp->D_T, "bool")){
					temp->i_num = num;
				}
				else{
					temp->i_num = (int)num;
				}
				return;
			}
			temp = temp->next;
		}
	}
}

void renew_s_ID(char name[], char con[]){
	if(cur_table){
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(!strcmp(temp->name, name)){
				if(!strcmp(temp->D_T, "string")){	
					strcpy(temp->s_const, con);
					return;
				}
			}
			temp = temp->next;
		}
	}
}

int get_i_num(char name[]){
	if(cur_table){
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(!strcmp(temp->name, name)){
				return temp->i_num;
			}
			temp = temp->next;
		}
	}

}

float get_f_num(char name[]){
	if(cur_table){
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(!strcmp(temp->name, name)){
				return temp->f_num;
			}
			temp = temp->next;
		}
	}
}

/* code generation functions */
void gencode_function() {}
