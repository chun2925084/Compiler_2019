/* Definition section */
%{
	#include <stdio.h>
	#include <stdlib.h>

	int n_comment = 0;
	int n_code = 0;
%}

/* Define regular expression label */

letter [a-zA-Z]
digit [0-9]
space " "
id {letter}+({letter}|{digit})*
number {digit}+
float {number}+"."+{number}*
slash "/"
star "*"
comment "/*"|"//"
comment_stop "*/"
%s COMMENT1 COMMENT2 C_END STRING

/* Rules section */
%%

{comment} {
			printf("%s", yytext);
			if(!strcmp(yytext, "/*"))
				BEGIN COMMENT1;
			else
				BEGIN COMMENT2;}

<COMMENT1>{
{comment_stop} printf("*/ \t C Comment\n");n_comment++;BEGIN C_END;
\n n_comment++;printf("\n");
}

<C_END>{
\n BEGIN INITIAL;
}

<COMMENT2>{
\n n_comment++;printf(" \t C++ Comment\n");BEGIN INITIAL;
}

<COMMENT1,COMMENT2>{
"+" printf("%s",yytext);
"-" printf("%s", yytext);
"/" printf("%s", yytext);
"%" printf("%s", yytext);
"++" printf("%s", yytext);
"--" printf("%s", yytext);
">" printf("%s", yytext);
"<" printf("%s", yytext);
">=" printf("%s", yytext);
"<=" printf("%s", yytext);
"==" printf("%s", yytext);
"!=" printf("%s", yytext);
"[" printf("%s", yytext);
"]" printf("%s", yytext);
"," printf("%s", yytext);
";" printf("%s", yytext);
"\"" printf("%s", yytext);
"print" printf("%s", yytext);
"if" printf("%s", yytext);
"else" printf("%s", yytext);
"for" printf("%s", yytext);
"while" printf("%s", yytext);
"string" printf("%s", yytext);
"int" printf("%s", yytext);
"float" printf("%s", yytext);
"=" printf("%s", yytext);
"+=" printf("%s", yytext);
"-=" printf("%s", yytext);
"*=" printf("%s", yytext);
"/=" printf("%s", yytext);
"%=" printf("%s", yytext);
"&&" printf("%s", yytext);
"||" printf("%s", yytext);
"!" printf("%s", yytext);
"(" printf("%s", yytext);
")" printf("%s", yytext);
"{" printf("%s", yytext);
"}" printf("%s", yytext);
"void" printf("%s", yytext);
"bool" printf("%s", yytext);
"true" printf("%s", yytext);
"false" printf("%s", yytext);
"return" printf("%s", yytext);
"continue" printf("%s", yytext);
"break" printf("%s", yytext);
{number} printf("%s", yytext);
{float} printf("%s", yytext);
{id} printf("%s", yytext);
{star} printf("%s",yytext);
{space} printf(" ");
}

<STRING>{
{letter}+("\\"+"\""+{space}+{id})*+"\"" printf("%s \t STR_CONST\n", yytext);
}


"+" 	{ printf("%s \t ADD\n", yytext); }
"-"	{ printf("%s \t SUB\n", yytext); }
"*" 	{ printf("%s \t MUL\n", yytext); }
"/" 	{ printf("%s \t DIV\n", yytext); }
"%" 	{ printf("%s \t MOD\n", yytext); }
"++" 	{ printf("%s \t INC\n", yytext); }
"--" 	{ printf("%s \t DEC\n", yytext); }
">" 	{ printf("%s \t MT\n", yytext); }
"<" 	{ printf("%s \t LT\n", yytext); }
"\>=" 	{ printf("%s \t MTE\n", yytext); }
"\<=" 	{ printf("%s \t LTE\n", yytext); }
"\==" 	{ printf("%s \t EQ\n", yytext); }
"\!=" 	{ printf("%s \t NE\n", yytext); }
"[" 	{ printf("%s \t LSB\n", yytext); }
"]" 	{ printf("%s \t RSB\n", yytext); }
"," 	{ printf("%s \t COMMA\n", yytext); }
";" 	{ printf("%s \t SEMICOLON\n", yytext); }

\"([^\\\"]|\\.)*\" 	{ printf("\" \t QUOTA\n");
					  int i = 0;
					  for(i = 1;i<strlen(yytext)-1;i++){
					  	printf("%c",yytext[i]);
					  }
					  printf(" \t STR_CONST\n");
					  printf("\" \t QUOTA\n");
					}
"print" { printf("%s \t PRINT\n", yytext); }
"if" { printf("%s \t IF\n", yytext); }
"else" { printf("%s \t ELSE\n", yytext); }
"for" { printf("%s \t FOR\n", yytext); }
"while" { printf("%s \t WHILE\n", yytext); }
"string(keywords)" { printf("%s \t STRING\n", yytext); }
"int" { printf("%s \t INT\n", yytext); }
"float" { printf("%s \t FLOAT\n", yytext); }
"=" { printf("%s \t ASGN\n", yytext); }
"\+=" { printf("%s \t ADDASGN\n", yytext); }
"\-=" { printf("%s \t SUBASGN\n", yytext); }
"\*=" { printf("%s \t MULASGN\n", yytext); }
"\/=" { printf("%s \t DIVASGN\n", yytext); }
"\%=" { printf("%s \t MODASGN\n", yytext); }
"\&&" { printf("%s \t AND\n", yytext); }
"\||" { printf("%s \t OR\n", yytext); }
"!" { printf("%s \t NOT\n", yytext); }
"(" { printf("%s \t LB\n", yytext); }
")" { printf("%s \t RB\n", yytext); }
"{" { printf("%s \t LCB\n", yytext); }
"}" { printf("%s \t RCB\n", yytext); }
"void" { printf("%s \t VOID\n", yytext); }
"bool" { printf("%s \t BOOL\n", yytext); }
"true" { printf("%s \t TRUE\n", yytext); }
"false" { printf("%s \t FALSE\n", yytext); }
"return" { printf("%s \t RET\n", yytext); }
"continue" { printf("%s \t CONT\n", yytext); }
"break" { printf("%s \t BREAK\n", yytext); }
"string" { printf("%s \t STRING\n", yytext); }
{space} {;}
{number} { printf("%s \t I_CONST\n", yytext); }
{float} { printf("%s \t F_CONST\n", yytext);}
{id}	{ printf("%s \t ID\n", yytext); }
\n {n_code++;}
			
%%

/*	C Code section */
int yywrap(void)
{
    return 1;
}

int main(int argc,char *argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	printf("\nParse over, the line number is %d.\n\n", n_comment+n_code);
	printf("comment: %d lines\n\n", n_comment);

	return 0;
}
