/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 100 "compiler_hw3.y" /* yacc.c:1909  */

	int i_val;
	float f_val;
	char* string;
	RULE_TYPE rule_type;

#line 133 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
