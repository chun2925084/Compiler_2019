/*	Definition section */
%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
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

void test();

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
//void dump_symbol(int Index, char* Name, char* Kind, char* Type, int Scope, char* Attribute);
void dump_symbol();
void yyerror();
void semantic(char msg[]);

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
	int i_val;
	float f_val;
	char* string;

}

/* Token without return */
%token PRINT 
%token IF ELSE FOR WHILE

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STRING TRUE FALSE STRING_CONST
%token <string> ID NEWLINE
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token AND_OP OR_OP
%token GE_OP LE_OP EQ_OP NE_OP
%token <string> INC DEC
%token VOID INT FLOAT BOOL RETURN

/* Nonterminal with return, which need to sepcify type */
%type <f_val> initializer_num
%type <string> type
%type <string> declaration param_list param StmtList expression_stat  
%type <string>  WHILESTMT 
%type <string> print_func
%type <string> if_else_cond

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
	: program stat
	| stat
;

stat
	: declaration
	| expression_stat
	| print_func
	| NEWLINE{
			// printf("===%d==depth = %d", endline_dump, depth);
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
		/*	 if(endline_dump == 1 && depth != 0){
			 	dump_symbol(); 
				printf("call dump\n");
				endline_dump = 0;
			 	printf("fun_end = %d\n", fun_end);
				if(fun_end!=1){
					printf("\n%d: ", yylineno); 
					memset(buf, 0, sizeof(buf));
				}
			}
			else{
			 	printf("\n%d: ", yylineno); 
			 	memset(buf, 0, sizeof(buf));
			}*/
		}
	| WHILESTMT
	| if_else_cond
	| error NEWLINE {
		printf("pp\n");
		test();
			
	}
;

declaration
	: type ID '=' initializer ';'
	{
		if(!strcmp($1, "int")){
			//printf("%s", buf);
			//memset(buf, 0, sizeof(buf));
			if(cur_table == NULL){
				cur_table = create_symbol($2, "variable", $1, "", 1);
			}
			else{
				lookup_symbol($2, $1, 0, 0);
				if(semantic_error==0){
					insert_symbol($2, "variable", $1, depth, "", 1);
				}
			}
		}
		else if(!strcmp($1, "float")){
			//printf("%s", buf);
			//memset(buf, 0, sizeof(buf));
			if(cur_table == NULL){
				cur_table = create_symbol($2, "variable", $1, "", 1);
			}
			else{
				lookup_symbol($2, $1, 0, 0);
				if(semantic_error==0){
					insert_symbol($2, "variable", $1, depth, "", 1);
				}
			}
		}
		else if(!strcmp($1, "string")){
			//printf("%s", buf);
			//memset(buf, 0, sizeof(buf));
			if(cur_table == NULL){
				cur_table = create_symbol($2, "variable", $1, "", 1);
			}
			else{
				lookup_symbol($2, $1, 0, 0);
				if(semantic_error==0){
					insert_symbol($2, "variable", $1, depth, "", 1);
				}
			}
		}
		else if(!strcmp($1, "bool")){
			//printf("%s", buf);
			//memset(buf, 0, sizeof(buf));
			if(cur_table == NULL){
				cur_table = create_symbol($2, "variable", $1, "", 1);
			}
			else{
				lookup_symbol($2, $1, 0, 0);
				if(semantic_error==0){
					insert_symbol($2, "variable", $1, depth, "", 1);
				}
			}
		}

	}
	| type ID '=' arithmetic_expr ';'{
		if(!strcmp($1, "int")){
			//printf("%s", buf);
			//memset(buf, 0, sizeof(buf));
			if(cur_table == NULL){
				cur_table = create_symbol($2, "variable", $1, "", 1);
			}
			else{
				lookup_symbol($2, $1, 0, 0);
				if(semantic_error==0){
					insert_symbol($2, "variable", $1, depth, "", 1);
				}
			}
		}
		else if(!strcmp($1, "float")){
			//printf("%s", buf);
			//memset(buf, 0, sizeof(buf));
			if(cur_table == NULL){
				cur_table = create_symbol($2, "variable", $1, "", 1);
			}
			else{
				lookup_symbol($2, $1, 0, 0);
				if(semantic_error==0){
					insert_symbol($2, "variable", $1, depth, "", 1);
				}
			}
		}

	}

	/*define/declare var by func call*/
	| type ID '=' ID '(' param_call ')' ';'{
		lookup_symbol($2, $1, 0, 0);
		lookup_symbol($4, "", 1, 1);
		if(semantic_error == 0){
			insert_symbol($2, "variable", $1, depth, "", 1);
		}
	}
	/*special for string assign*/
	| type ID '=' STRING_CONST ';'{
		lookup_symbol($2, $1, 0, 0);
		if(semantic_error==0){
			insert_symbol($2, "variable", $1, depth, "", 1);
		}
		//printf("%d: %s",yylineno, buf);
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
	}
	| type ID ';'{
		if(!strcmp($1, "int")){
			//printf("%s", buf);
			//memset(buf, 0, sizeof(buf));
			if(cur_table == NULL){
				cur_table = create_symbol($2, "variable", $1, "", 1);
			}
			else{
				lookup_symbol($2, $1, 0, 0);
				if(semantic_error==0){
					insert_symbol($2, "variable", $1, depth, "", 1);
				}
			}
		}
		else{
			//printf("%d: %s",yylineno, buf);
			//printf("%s", buf);
			//memset(buf, 0, sizeof(buf));
			if(cur_table == NULL){
				cur_table = create_symbol($2, "variable", $1, "", 1);
			}
			else{
				lookup_symbol($2, $1, 0, 0);
				if(semantic_error==0){
					insert_symbol($2, "variable", $1, depth, "", 1);
				}
			}
		}

	}
	/* special for function */
	| type ID '(' param_list ')'{
		lookup_symbol($2, $1, 0, 1);
		if(semantic_error==0){
			insert_symbol($2, "function", $1, depth, param, 1);
			param_item *t = p_item;
			while(t!=NULL){
				lookup_symbol(t->name, t->type, 0, 0);
				insert_symbol(t->name, "parameter", t->type, depth+1, "", 1);
				t = t->next;
			}
			
		}
		param_item *t = p_item;
		param_item *next;
		while(t!=NULL){
			next = t->next;
			free(t);
			t = next;
		}
		p_item = NULL;

		/*	if(p_item==NULL){
			printf("p_item = %s\n", p_item->name);
		}*/

	} CompoundStmt {
		//printf("%d: %s",yylineno, buf);
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
		/*int inserted = 0;
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(temp->depth==0){
				if(!strcmp(temp->name, $2)){
					inserted = 1;
					break;
				}
			}
			temp = temp->next;
		}
		if(inserted==0){*/
		//}
	}
	| type ID '(' ')' CompoundStmt {
		//printf("%d: %s",yylineno, buf);
		//printf("%s", buf);
		int inserted = 0;
		Entry *temp = cur_table->root;
		while(temp!=NULL){
			if(temp->depth==0){
				if(!strcmp(temp->name, $2)){
					inserted = 1;
					break;
				}
			}
			temp = temp->next;
		}
		if(inserted==0){
			lookup_symbol($2, $1, 0, 1);
			if(semantic_error==0){
				insert_symbol($2, "function", $1, depth, "", 1);
			}
		}
		fun_end = 1;
	}
	| type ID '(' ')' ';'{
		lookup_symbol($2, $1, 0, 1);
		if(semantic_error==0){
			insert_symbol($2, "function", $1, depth, "", 0);
		}
	}
	| type ID '(' param_list ')' ';'{
		lookup_symbol($2, $1, 0, 1);
		if(semantic_error==0){
			insert_symbol($2, "function", $1, depth, param, 0);
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
;

/* actions can be taken when meet the token or rule */
type
	: INT { $$ = strdup("int"); }
	| FLOAT { $$ = strdup("float");}
	| BOOL  { $$ = strdup("bool"); }
	| STRING { $$ = strdup("string"); }
	| VOID { $$ = strdup("void"); }
;

initializer
	: initializer_num
	| ID{
		lookup_symbol($1, "", 1, 0);	
	}
	| TRUE
	| FALSE
;

initializer_num
	: I_CONST
	| '-' I_CONST 
	| F_CONST  
	| '-' F_CONST 
;

param_list
	: param{
	/*	param_item *t = p_item;
		while(t!=NULL){
			printf("t = %s\n", t->name);
			t = t->next;
		}*/
	}

;

param
	: param ',' type ID {
		if(p_item == NULL){
			p_item = malloc(sizeof(param_item));
			p_item->next = NULL;
			strcpy(p_item->name, $4);
			strcpy(p_item->type, $3);
		}
		else{
			param_item *new = malloc(sizeof(param_item));
			new->next = NULL;
			strcpy(new->name, $4);
			strcpy(new->type, $3);
			
			param_item *temp = p_item;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = new;
		}
		//insert_symbol($4, "parameter", $3, depth+1, "");
		if(strlen(param)==0){
			strcat(param, $3);
		}
		else{
			strcat(param, ", ");
			strcat(param, $3);
		}
		//debug 
		/*Entry *temp = cur_table->root;	
		  while(temp!=NULL){
		  printf("temp = %s %d %d\n", temp->name, temp->index, temp->depth);
		  temp = temp->next;
		  }*/
	}
	| type ID{
		if(p_item == NULL){
			p_item = malloc(sizeof(param_item));
			p_item->next = NULL;
			strcpy(p_item->name, $2);
			strcpy(p_item->type, $1);
		}
		else{
			param_item *new = malloc(sizeof(param_item));
			new->next = NULL;
			strcpy(new->name, $2);
			strcpy(new->type, $1);
			
			param_item *temp = p_item;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = new;
		}
		//insert_symbol($2, "parameter", $1, depth+1, "");
		if(strlen(param)==0){
			strcat(param, $1);
		}
		else{
			strcat(param, ", ");
			strcat(param, $1);
		}
	}
;

CompoundStmt
	: deeper_scope StmtList shallow_scope{
	}
;

deeper_scope
	: '{' {
		depth++;
		//printf("%d: %s",yylineno, buf);
		//printf("11111111111111111111%s", buf);
		//memset(buf, 0, sizeof(buf));
	}
;

shallow_scope
	: '}'  {
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
;
StmtList
	: StmtList stat{
	}
	
	|
;

WHILESTMT
	: WHILE '(' condition_list ')' CompoundStmt{
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
	}
;

condition_list
	: condition_list AND_OP condition
	| condition_list OR_OP condition{
	}
	| '!' condition_list
	| condition
;

condition
	: condition_type compare condition_type
	| initializer
	| ID '=' arithmetic_expr
	| arithmetic_expr
	| ID ArithmeticList
	| ID '(' param_call ')'
	| ID '(' ')'
	| '(' condition_list ')'
;

condition_type
	: fact
	| arithmetic_expr
	| ID ArithmeticList
;

compare
	: '>'
	| '<'
	| GE_OP
	| LE_OP
	| NE_OP
	| EQ_OP
;

expression_stat
	: ID ArithmeticList ';'{
		//printf("%d: %s",yylineno, buf);
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
		//printf("depth = %d\n", depth);
		lookup_symbol($1, "", 1, 0);	
	}
	| RETURN Factor ';'{
		//printf("%d: %s",yylineno, buf);
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
	}
	| RETURN ID ';'{
		//printf("%d: %s",yylineno, buf);
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
		lookup_symbol($2, "", 1, 0);
	}
	| RETURN ID ArithmeticList ';'{
		lookup_symbol($2, "", 1, 0);
	}
	| RETURN arithmetic_expr ';'
	| ID '=' arithmetic_expr ';'{
		//printf("%d: %s",yylineno, buf);
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
		lookup_symbol($1, "", 1, 0);
	}
	| ID '(' param_call ')' { 
		//printf("%d: %s",yylineno, buf);
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
		lookup_symbol($1, "", 1, 1);
	} ';'
	| ID '(' ')' ';'{
		lookup_symbol($1, "", 1, 1);
	}
;

param_call
	: param_call ',' condition_list
	| param_call ',' STRING_CONST
	| condition_list
	| STRING_CONST
;

ArithmeticList
	: INC	
	| DEC
	| ADD_ASSIGN fact
	| SUB_ASSIGN fact
	| MUL_ASSIGN fact
	| DIV_ASSIGN fact
	| MOD_ASSIGN fact
;

arithmetic_expr
: arithmetic_expr '+' term
| arithmetic_expr '-' term
| term
;

term
	: term '*' fact
	| term '/' fact
	| term '%' fact
	| fact
	| '(' arithmetic_expr ')'
;

fact
	: I_CONST
	| '-' I_CONST
	| F_CONST
	| '-' F_CONST
	| ID {
		lookup_symbol($1, "", 1, 0);
	}
	| ID '(' param_call ')'{
		lookup_symbol($1, "", 1, 1);
	}
	| ID '(' ')'{
		lookup_symbol($1, "", 1, 1);
	}
	| '(' term ')'
;

Factor
	: TRUE
	| ID{
		Entry *temp = cur_table->root;
		int get = 0;
		while(temp->next!=NULL){
			if(temp->depth <= depth){
				if(!strcmp(temp->name, $1)){
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
			strcat(semantic_msg, $1);
		}

	}
	| FALSE
	| I_CONST
	| '-' I_CONST
	| F_CONST
	| '-' F_CONST
;

print_func
	: PRINT '(' ID ')' ';'{
		lookup_symbol($3, "", 1, 0);
		//printf("%d: %s",yylineno, buf);
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
	}
	| PRINT '(' STRING_CONST ')' ';'{
		//printf("%d: %s",yylineno, buf);
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
	}
;

if_else_cond
	: IF '(' condition_list ')' CompoundStmt{
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
	}
	| ELSE IF '(' condition_list ')' CompoundStmt
	| ELSE CompoundStmt{
		//printf("%s", buf);
		//memset(buf, 0, sizeof(buf));
	}
;
%%
/* C code section */
int main(int argc, char** argv)
{
	yylineno = 0;
	//printf("%d: ", yylineno);
	yyparse();
	Entry *temp = cur_table->root;
	num = 0;
	flag = 0;
	do_depth = 0;
	if(ERROR==0){
		dump_symbol();
		printf("\nTotal lines: %d \n",yylineno);
	}
	return 0;
}

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
	strcpy(H->root->name, name);
	strcpy(H->root->E_T, entry_type);
	strcpy(H->root->D_T, data_type);
	strcpy(H->root->attr, att);
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
	new->func_def = func_def;
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
				}
			}
			temp = temp->next;
		}
	}
}
void dump_symbol() {
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
