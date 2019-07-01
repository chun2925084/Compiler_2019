/*	Definition section */
%{
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

	%}

%union {
	int i_val;
	float f_val;
	char* string;
	RULE_TYPE rule_type;
}

/* Token without return */
%token INC DEC
%token GE_OP LE_OP EQ_OP NE_OP
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token PRINT IF ELSE
%token SEMICOLON
%token <rule_type> I_CONST 
%token <rule_type> F_CONST ID STRING_CONST
%token <string> NEWLINE 
%token BOOL INT FLOAT STRING VOID
%token AND_OP OR_OP NOT FOR WHILE TRUE FALSE RETURN QUOTA 
%type <rule_type> fact term arithmetic_expr ArithmeticList condition_type
%type <string> declaration type param_list param 
%type <f_val> initializer_num
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
| NEWLINE{
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
| expression_stat
| print_func
| IF_ELSE{
}
| WHILESTMT
;

declaration
: type ID '=' STRING_CONST ';'{
	
	if(cur_table == NULL){
		cur_table = create_symbol($2.id, "variable", $1, "", 1);
	}
	else{	
		lookup_symbol($2.id, $1, 0, 0);
		if(semantic_error==0){
			insert_symbol($2.id, "variable", $1, depth, "", 1);
		}
	}
	fprintf(file, "ldc \"%s\"\n", $4.string);
	renew_s_ID($2.id, $4.string);
	$2.type = STRING_t;
	$2.string = $4.string;
	int stack_num = get_stack_num($2.id, depth);
	fprintf(file, "astore %d\n", stack_num-1);
}

| type ID '=' arithmetic_expr ';'{
	if(cur_table == NULL){
		cur_table = create_symbol($2.id, "variable", $1, "", 1);
	}
	else{	
		lookup_symbol($2.id, $1, 0, 0);
		if(semantic_error==0){
			insert_symbol($2.id, "variable", $1, depth, "", 1);
		}
	}
	char type[15] = {0};
	strcpy(type, type_tran($1));
	if(depth == 0){
		if(!strcmp($1, "float")){
			renew_ID($2.id, $4.f_val);
			$2.type = FLOAT_t;
			$2.f_val = $4.f_val;
			fprintf(file,   ".field public static %s %s = %f\n", $2.id, type, $4.f_val);
		}
		else if(!strcmp($1, "string")){
			renew_s_ID($2.id, $4.string);
			$2.type = STRING_t;
			$2.string = $4.string;
		}
		else if(!strcmp($1, "bool")){
			renew_ID($2.id, $4.i_val);
			$2.type = BOOL_t;
			$2.i_val = $4.i_val;
			fprintf(file,   ".field public static %s %s = %d\n", $2.id, type, $4.i_val);
		}
		else{
			renew_ID($2.id, $4.i_val);
			$2.type = INT_t;
			$2.i_val = $4.i_val;
			fprintf(file,   ".field public static %s %s = %d\n", $2.id, type, $4.i_val);
		}
	}
	else{
		int stack_num = get_stack_num($2.id, depth);
		if(!strcmp($1, "float")){
			if($4.type == FLOAT_t){
				fprintf(file, "fstore %d\n", stack_num-1);
				renew_ID($2.id, $4.f_val);
				$2.type = FLOAT_t;
				$2.f_val = $4.f_val;
			}
			else{
				fprintf(file, "i2f\n");
				fprintf(file, "fstore %d\n", stack_num-1);
				renew_ID($2.id, $4.i_val);
				$2.type = FLOAT_t;
				$2.f_val = $4.i_val;
			}
		}
		else if(!strcmp($1, "string")){
			fprintf(file, "istore %d\n", stack_num-1);
			renew_s_ID($2.id, $4.string);
			$2.type = STRING_t;
			$2.string = $4.string;
		}
		else if(!strcmp($1, "bool")){
			fprintf(file, "istore %d\n", stack_num-1);
			renew_ID($2.id, $4.i_val);
			$2.type = BOOL_t;
			$2.i_val = $4.i_val;
		}
		else{
			if($4.type == FLOAT_t){
				fprintf(file, "f2i\n");
				fprintf(file, "istore %d\n", stack_num-1);
				renew_ID($2.id, $4.f_val);
				$2.type = INT_t;
				$2.i_val = (int)$4.f_val;
			}
			else{
				fprintf(file, "istore %d\n", stack_num-1);
				renew_ID($2.id, $4.i_val);
				$2.type = INT_t;
				$2.i_val = $4.i_val;
			}
		}
	}
}

	|type ID ';'{
		if(cur_table == NULL){
			cur_table = create_symbol($2.id, "variable", $1, "", 1);
		}
		else{
			lookup_symbol($2.id, $1, 0, 0);
			if(semantic_error==0){
				insert_symbol($2.id, "variable", $1, depth, "", 1);
			}
		}
		char type[15] = {0};
		strcpy(type, type_tran($1));
			if(depth == 0){
				fprintf(file,   ".field public static %s %s\n", $2.id, type);
				if(!strcmp($1, "float")){
					renew_ID($2.id, 0.0);
					$2.type = FLOAT_t;
				}
				else if(!strcmp($1, "string")){
					renew_s_ID($2.id, "");
					$2.type = STRING_t;
				}
				else if(!strcmp($1, "bool")){
					renew_ID($2.id, 1);
					$2.type = BOOL_t;
				}
				else{
					renew_ID($2.id, 0);
					$2.type = INT_t;
				}
			}
			else{
				int stack_num = get_stack_num($2.id, depth);
				if(!strcmp($1, "float")){
					fprintf(file, "ldc 0.0\n");
					fprintf(file, "fstore %d\n", stack_num-1);
					renew_ID($2.id, 0);
				}
				else if(!strcmp($1, "string")){
					fprintf(file, "istore %d\n", stack_num-1);
					renew_s_ID($2.id, "");
					$2.type = STRING_t;
				}
				else if(!strcmp($1, "bool")){
					fprintf(file, "ldc 1\n");
					fprintf(file, "istore %d\n", stack_num-1);
					renew_ID($2.id, 1);
					$2.type = BOOL_t;
				}

				else{
					fprintf(file, "ldc 0\n");
					fprintf(file, "istore %d\n", stack_num-1);
					renew_ID($2.id, 0);
				}

				//printf("stack_num = %d\n", stack_num);
			}
	}

/* special for function */
	| type ID '(' param_list ')'{
		if(cur_table){
			lookup_symbol($2.id, $1, 0, 1);
			if(semantic_error==0){
				insert_symbol($2.id, "function", $1, depth, param, 1);
				param_item *t = p_item;
				while(t!=NULL){
					lookup_symbol(t->name, t->type, 0, 0);
					insert_symbol(t->name, "parameter", t->type, depth+1, "", 1);
					t = t->next;
				}
				
			}



			char func_name[15] = {0};
			strcat(func_name, $2.id);
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
			strcpy(return_type, type_tran($1));
			strcat(func_name, type);
			strcat(func_name, ")");
			strcat(func_name, return_type);


			if(strcmp($1, func_type) && strcmp(func_type, "")){
				//semantic_error = 1;
				//strcpy(semantic_msg, "the return type is not the same\n");
				RT_FP = 1;
			}

			renew_func($2.id, func_name, type);
			fprintf(file,  ".method public static %s(%s)%s\n.limit stack 50\n.limit locals 50\n", $2.id, type, return_type);
		}
		else{
			cur_table = create_symbol($2.id, "function", $1, param, 1);
			param_item *t = p_item;
			while(t!=NULL){
				lookup_symbol(t->name, t->type, 0, 0);
				insert_symbol(t->name, "parameter", t->type, depth+1, "", 1);
				t = t->next;
			}
			
			char func_name[15] = {0};
			strcat(func_name, $2.id);
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
			strcpy(return_type, type_tran($1));
			strcat(func_name, type);
			strcat(func_name, ")");
			strcat(func_name, return_type);
			renew_func($2.id, func_name, type);
			fprintf(file,  ".method public static %s(%s)%s\n.limit stack 50\n.limit locals 50\n", $2.id, type, return_type);

		}

	} CompoundStmt {
		fprintf(file, ".end method\n");
	}

	| type ID '(' ')'{
		strcpy(func_type, $1);
		if(cur_table){
			int inserted = 0;
			Entry *temp = cur_table->root;
			while(temp!=NULL){
				if(temp->depth==0){
					if(!strcmp(temp->name, $2.id)){
						inserted = 1;
						break;
					}
				}
				temp = temp->next;
			}
			if(inserted==0){
				lookup_symbol($2.id, $1, 0, 1);
				if(strcmp($1, func_type) && strcmp(func_type, "")){
					//semantic_error = 1;
					//strcpy(semantic_msg, "the return type is not the same\n");
				}
				if(semantic_error==0){
					insert_symbol($2.id, "function", $1, depth, "", 1);
				}
			}
		}
		else{
			cur_table = create_symbol($2.id, "function", $1, "", 1);
		}
		if(!strcmp($2.id, "main")){
			fprintf(file,  ".method public static main([Ljava/lang/String;)V\n.limit stack 50\n.limit locals 50\n");
		}
		else{
			char return_type[15] = {0};
			strcpy(return_type, type_tran($1));
			fprintf(file,  ".method public static %s([Ljava/lang/String;)%s\n.limit stack 50\n.limit locals 50\n", $1
			, return_type);
		}
			
	} CompoundStmt {
		fun_end = 1;
		fprintf(file, ".end method\n");
	}
	| type ID '(' ')' ';'{
		if(cur_table){
			lookup_symbol($2.id, $1, 0, 1);
			if(semantic_error==0){
				insert_symbol($2.id, "function", $1, depth, "", 0);
			}
		}

	}
	| type ID '(' param_list ')' ';'{
		if(cur_table){
			lookup_symbol($2.id, $1, 0, 1);
			if(semantic_error==0){
				insert_symbol($2.id, "function", $1, depth, param, 0);
			}
		}
		else{
			cur_table = create_symbol($2.id, "function", $1, "", 0);
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


CompoundStmt
	: deeper_scope StmtList shallow_scope{
	}
;

StmtList
	: StmtList stat{
	}

	|
;


deeper_scope
	: '{' {
		depth++;
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
			strcpy(p_item->name, $4.id);
			strcpy(p_item->type, $3);
		}
		else{
			param_item *new = malloc(sizeof(param_item));
			new->next = NULL;
			strcpy(new->name, $4.id);
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
			strcpy(p_item->name, $2.id);
			strcpy(p_item->type, $1);
		}
		else{
			param_item *new = malloc(sizeof(param_item));
			new->next = NULL;
			strcpy(new->name, $2.id);
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

arithmetic_expr
	: arithmetic_expr '+' term{
		if($1.type == FLOAT_t && $3.type == INT_t){
			fprintf(file, "i2f\n");
			fprintf(file, "fadd\n");
			$$.type = FLOAT_t;
		}
		else if($1.type == INT_t && $3.type == FLOAT_t){
			fprintf(file, "swap\n");
			fprintf(file, "i2f\n");
			fprintf(file, "fadd\n");
			$$.type = FLOAT_t;
		}
		else if($1.type == INT_t && $3.type == INT_t){
			fprintf(file, "iadd\n");
			$$.type = INT_t;
		}
		else{
			fprintf(file, "fadd\n");
			$$.type = FLOAT_t;
		}

	}
| arithmetic_expr '-' term{
	if($1.type == FLOAT_t && $3.type == INT_t){
			fprintf(file, "i2f\n");
			fprintf(file, "fsub\n");
			$$.type = FLOAT_t;
		}
		else if($1.type == INT_t && $3.type == FLOAT_t){
			fprintf(file, "swap\n");
			fprintf(file, "i2f\n");
			fprintf(file, "fsub\n");
			$$.type = FLOAT_t;
		}
		else if($1.type == INT_t && $3.type == INT_t){
			fprintf(file, "isub\n");
			$$.type = INT_t;
		}
		else{
			fprintf(file, "fsub\n");
			$$.type = FLOAT_t;
		}

}
| term{
	$$ = $1;
}
;

term
	: term '*' fact{
		if($1.type == FLOAT_t && $3.type == INT_t){
			fprintf(file, "i2f\n");
			fprintf(file, "fmul\n");
			$$.type = FLOAT_t;
		}
		else if($1.type == INT_t && $3.type == FLOAT_t){
			fprintf(file, "swap\n");
			fprintf(file, "i2f\n");
			fprintf(file, "fmul\n");
			$$.type = FLOAT_t;
		}
		else if($1.type == INT_t && $3.type == INT_t){
			fprintf(file, "imul\n");
			$$.type = INT_t;
		}
		else{
			fprintf(file, "fmul\n");
			$$.type = FLOAT_t;
		}
	}
	| term '/' fact{
		if($3.type == FLOAT_t){
			if($3.f_val == 0){
				semantic_error = 1;
				acc_semantic++;
				strcpy(semantic_msg, "Divide by zero\n");
			}
		}
		else if($3.type == INT_t){
			if($3.i_val == 0){
				semantic_error = 1;
				acc_semantic++;
				strcpy(semantic_msg, "Divide by zero\n");
			}
		}
		if($1.type == FLOAT_t && $3.type == INT_t){
			fprintf(file, "i2f\n");
			fprintf(file, "fdiv\n");
			$$.type = FLOAT_t;
		}
		else if($1.type == INT_t && $3.type == FLOAT_t){
			fprintf(file, "swap\n");
			fprintf(file, "i2f\n");
			fprintf(file, "fdiv\n");
			$$.type = FLOAT_t;
		}
		else if($1.type == INT_t && $3.type == INT_t){
			fprintf(file, "idiv\n");
			$$.type = INT_t;
		}
		else{
			fprintf(file, "fdiv\n");
			$$.type = FLOAT_t;
		}

	}
	| term '%' fact{

		if($1.type == INT_t && $3.type == INT_t){
			if($3.i_val == 0){
				semantic_error = 1;
				acc_semantic++;
				strcpy(semantic_msg, "Module operator with float poinr operands\n");
			}
			else{
				fprintf(file, "irem\n");
				$$.type = INT_t;
			}
		}
		else{
			semantic_error = 1;
			acc_semantic++;
			strcpy(semantic_msg, "Divide by zero\n");
		}
	}
	| fact{
		$$ = $1;
	}
	| '(' arithmetic_expr ')'{
		$$ = $2;
	}
;

fact
	: I_CONST{
		$1.type = INT_t;
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
		
		$$ = $1;
	}
	| '-' I_CONST{
		$2.type = INT_t;
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
		
		$2.i_val = -$2.i_val;
		$$ = $2;
	}
	| F_CONST{
		$1.type = FLOAT_t;
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
		$$ = $1;
	}
	| '-' F_CONST{
		$2.type = FLOAT_t;
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
		
		$2.f_val = -$2.f_val;
		$$ = $2;
	}
	| ID {
		lookup_symbol($1.id, "", 1, 0);
		int stack_num = get_stack_num($1.id, depth);
		/*for global*/
		if(stack_num == 0){
			fprintf(file, "getstatic compiler_hw3/%s I\n", $1.id);
			if(!strcmp(get_type($1.id, depth), "float")){
				$1.type = FLOAT_t;
				$1.f_val = get_f_num($1.id);
			}
			else{
				$1.type = INT_t;
				$1.i_val = get_i_num($1.id);
			}
		}
		else{
			if(!strcmp(get_type($1.id, depth), "float")){
				fprintf(file, "fload %d\n", stack_num-1);
				$$.type = FLOAT_t;
				$1.type = FLOAT_t;
				$1.f_val = get_f_num($1.id);
			}
			else{
				fprintf(file, "iload %d\n", stack_num-1);
				$1.type = INT_t;
				$1.i_val = get_i_num($1.id);
			}
		}
		if(function == 1){
			strcat(param_call_type, type_tran(get_type($1.id, depth)));
		}
		$$ = $1;
	}

	/*special for function call*/
	| ID '(' {function = 1;}param_call ')'{
		lookup_symbol($1.id, "", 1, 1);
		char type[15] = {0};
		strcpy(type, get_param($1.id));
		int i, j;
		char c;
	//	check_param($1.id, param_call_type);
		fprintf(file, "invokestatic compiler_hw3/%s\n", get_param($1.id));
	}
	| ID '(' ')'{
		lookup_symbol($1.id, "", 1, 1);
		fprintf(file, "invokestatic compiler_hw3/%s\n", get_param($1.id));
	}
	| '(' term ')'
	| TRUE{
		$$.i_val = 1;
		$$.type = BOOL_t;
		if(depth!=0){
			fprintf(file, "ldc 1\n");
		}
	}
	| FALSE{
		$$.i_val = 0;
		$$.type = BOOL_t;
		if(depth!=0){
			fprintf(file, "ldc 0\n");
		}
	}

;

param_call
	: param_call ',' condition_list
	| param_call ',' STRING_CONST
	| condition_list
	| STRING_CONST
;

condition_list
	: condition
;

condition
	: condition_type compare condition_type{
		if($1.type == INT_t){
			fprintf(file, "isub\n");
		}
		else{
			fprintf(file, "fsub\n");
			fprintf(file, "f2i\n");
		}
	}
	| initializer
	| ID '=' arithmetic_expr{
		int stack_num = get_stack_num($1.id, depth);
		if(stack_num == 0){
			if(!strcmp(get_type($1.id, depth), "float")){
				fprintf(file, "getstatic compiler_hw3/%s F\n", $1.id);
				$1.type = FLOAT_t;
				$1.f_val = $3.f_val;
			}
			else{
				fprintf(file, "getstatic compiler_hw3/%s I\n", $1.id);
				$1.type = INT_t;
				$1.i_val = $3.i_val;
			}
			
		}
		else{
			fprintf(file, "iload %d", stack_num-1);
		}
	}
	| arithmetic_expr
	| ID ArithmeticList{
		int stack_num = get_stack_num($1.id, depth);
		fprintf(file, "iload %d\n", stack_num-1); 
	}
	| ID '(' param_call ')'
	| ID '(' ')'
	| '(' condition_list ')'
;

condition_type
	: fact
	| arithmetic_expr
	| ID ArithmeticList
;

/* actions can be taken when meet the token or rule */
type
	: INT { $$ = strdup("int"); }
	| FLOAT { $$ = strdup("float");}
	| BOOL  { $$ = strdup("bool"); }
	| STRING {  $$ = strdup("string"); }
	| VOID { $$ = strdup("void"); }
	;

initializer
	: initializer_num
	| ID
;

compare
	: '>'{
		strcpy(compare_type, ">");
	}
	| '<'{
		strcpy(compare_type, "<");
	}
	| GE_OP{
		strcpy(compare_type, ">=");
	}
	| LE_OP{
		strcpy(compare_type, "<=");
	}
	| NE_OP{
		strcpy(compare_type, "!=");
	}
	| EQ_OP{
		strcpy(compare_type, "==");
	}
;

initializer_num
	: I_CONST { //cur_init_f = $1;
			strcpy(cur_init, yytext);
				}
	| F_CONST { //cur_init_f = $1; }
			strcpy(cur_init, yytext);
			}
;

ArithmeticList
	: INC{
		strcpy(arith_choose, "INC");
	}
	| DEC{
		strcpy(arith_choose, "DEC");
	}

	| ADD_ASSIGN arithmetic_expr{
		strcpy(arith_choose, "ADD_ASSIGN");
		$$.type = $2.type;
		if($2.type == FLOAT_t){
			$$.f_val = $2.f_val;
		}
		else{
			$$.i_val = $2.i_val;
		}
	}
	| SUB_ASSIGN arithmetic_expr{
		strcpy(arith_choose, "SUB_ASSIGN");
		$$.type = $2.type;
		if($2.type == FLOAT_t){
			$$.f_val = $2.f_val;
		}
		else{
			$$.i_val = $2.i_val;
		}
	}

	| MUL_ASSIGN arithmetic_expr{
		strcpy(arith_choose, "MUL_ASSIGN");
		$$.type = $2.type;
		if($2.type == FLOAT_t){
			$$.f_val = $2.f_val;
		}
		else{
			$$.i_val = $2.i_val;
		}
	}
	| DIV_ASSIGN arithmetic_expr{
		strcpy(arith_choose, "DIV_ASSIGN");
		$$.type = $2.type;
		if($2.type == FLOAT_t){
			$$.f_val = $2.f_val;
		}
		else{
			$$.i_val = $2.i_val;
		}
	}
	| MOD_ASSIGN arithmetic_expr{
		strcpy(arith_choose, "MOD_ASSIGN");
		$$.type = $2.type;
		if($2.type == FLOAT_t){
			$$.f_val = $2.f_val;
		}
		else{
			$$.i_val = $2.i_val;
		}
	}
;

expression_stat
	: ID ArithmeticList ';'{
		lookup_symbol($1.id, "", 1, 0);	
		int stack_num = get_stack_num($1.id, depth);
		if(!strcmp(get_type($1.id, depth), "float")){
			$1.type = FLOAT_t;
			fprintf(file, "fload %d\n", stack_num-1);
		}
		else{
			$1.type = INT_t;
			fprintf(file, "iload %d\n", stack_num-1);
		}
		
		/*for global*/
		if(stack_num == -1){
			/*wait to handle*/
		}
		else{
			if(!strcmp(arith_choose, "INC")){
				fprintf(file, "ldc 1\n");
				if($1.type == FLOAT_t){
					fprintf(file , "i2f\n");
					fprintf(file, "fadd\n");
					fprintf(file, "fstore ");
				}
				else{
					fprintf(file, "iadd\n");
					fprintf(file, "istore ");
				}
				int stack_num = get_stack_num($1.id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
			else if(!strcmp(arith_choose, "DEC")){
				fprintf(file, "ldc 1\n");
				if($1.type == FLOAT_t){
					fprintf(file , "i2f\n");
					fprintf(file, "fsub\n");
					fprintf(file, "fstore ");
				}
				else{
					fprintf(file, "ldc 1\n");
					fprintf(file, "isub\n");
					fprintf(file, "istore ");
				}
				int stack_num = get_stack_num($1.id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
			else if(!strcmp(arith_choose, "ADD_ASSIGN")){
				if($1.type == INT_t){
					if($2.type == INT_t){
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
					if($2.type == INT_t){
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
				int stack_num = get_stack_num($1.id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
			else if(!strcmp(arith_choose, "SUB_ASSIGN")){
				if($1.type == INT_t){
					if($2.type == INT_t){
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
					if($2.type == INT_t){
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
				int stack_num = get_stack_num($1.id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
			else if(!strcmp(arith_choose, "MUL_ASSIGN")){
				if($1.type == INT_t){
					if($2.type == INT_t){
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
					if($2.type == INT_t){
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
				int stack_num = get_stack_num($1.id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);

			}
			else if(!strcmp(arith_choose, "DIV_ASSIGN")){
				if($1.type == FLOAT_t){
					if($2.type == INT_t){
						if($2.i_val == 0){
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
						if($2.f_val == 0){
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
					if($2.type == INT_t){
						if($2.i_val == 0){
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
						if($2.f_val == 0){
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
				int stack_num = get_stack_num($1.id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
			else if(!strcmp(arith_choose, "MOD_ASSIGN")){
				if($1.type == INT_t && $2.type == INT_t){
					if($2.i_val == 0){
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
				int stack_num = get_stack_num($1.id, depth);
				char stack_num_s[3] = {0};
				sprintf(stack_num_s, "%d", stack_num-1);
				fprintf(file, "%s\n", stack_num_s);
			}
		}
	}
	| RETURN Factor ';'{
		fprintf(file, "ireturn\n");
	}
	| RETURN ';'{
		strcpy(if_else_label, "goto EXIT_0\n");
		fprintf(file, "return\n");
	}
	| RETURN ID ';'{
		lookup_symbol($2.id, "", 1, 0);
		int stack_num = get_stack_num($2.id, depth);
		fprintf(file, "iload %d\n", stack_num-1);
		fprintf(file, "ireturn\n");
	}
	| RETURN ID ArithmeticList ';'{
		lookup_symbol($2.id, "", 1, 0);
		fprintf(file, "return\n");
	}
	| RETURN arithmetic_expr ';'{
		fprintf(file, "return\n");
	}
	| ID '=' arithmetic_expr ';'{
		lookup_symbol($1.id, "", 1, 0);
		int stack_num = get_stack_num($1.id, depth);
		//printf("stack_num = %d\n", stack_num);
		if(stack_num == 0){
			if(!strcmp(get_type($1.id, depth), "float")){
				fprintf(file, "putstatic compiler_hw3/%s F\n", $1.id);
				//$$.type = FLOAT_t;
			}
			else{
				fprintf(file, "putstatic compiler_hw3/%s I\n", $1.id);
			//	$$.type = INT_t;
			}
		}
		else{
			int stack_num = get_stack_num($1.id, depth);
			if(!strcmp(get_type($1.id, depth), "float")){
				if($3.type == FLOAT_t){
					fprintf(file, "fstore %d\n", stack_num-1);
				}
				else{
					fprintf(file, "i2f\n");
					fprintf(file, "fstore %d\n", stack_num-1);
				}
			}
			else{
				if($3.type == FLOAT_t){
					fprintf(file, "f2i\n");
					fprintf(file, "istore %d\n", stack_num-1);
				}
				else{
					fprintf(file, "istore %d\n", stack_num-1);
				}
			}
		}
}
/*special for function call without assign*/
	| ID '(' param_call ')' { 
		lookup_symbol($1.id, "", 1, 1);
		char type[15] = {0};
		strcpy(type, get_param($1.id));
		fprintf(file, "invokestatic compiler_hw3/%s\n", get_param($1.id));
	} ';'
	| ID '(' ')' ';'{
		lookup_symbol($1.id, "", 1, 1);
		fprintf(file, "invokestatic compiler_hw3/%s()%s\n", $1.id, get_type($1.id, 0));
	}
;

Factor
	: TRUE
	| ID{
		Entry *temp = cur_table->root;
		int get = 0;
		while(temp->next!=NULL){
			if(temp->depth <= depth){
				if(!strcmp(temp->name, $1.id)){
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
			strcat(semantic_msg, $1.id);
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
		lookup_symbol($3.id, "", 1, 0);
		
		int stack_num = get_stack_num($3.id, depth);
		if(!strcmp(get_type($3.id, depth), "float")){
			if(stack_num == 0){
				fprintf(file, "getstatic compiler_hw3/%s F\n", $3.id);
			}
			else{
				fprintf(file, "fload %d\n", stack_num-1);
			}
			fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(F)V\n");
		}
		else if(!strcmp(get_type($3.id, depth), "string")){
			fprintf(file, "aload %d\n", stack_num-1);
			fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
		}
		else{
			if(stack_num == 0){
				fprintf(file, "getstatic compiler_hw3/%s I\n", $3.id);
			}
			else{
				fprintf(file, "iload %d\n", stack_num-1);
			}

			fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
		}
	}
	| PRINT '(' STRING_CONST ')' ';'{
		fprintf(file, "ldc \"%s\"\n", $3.string);
		fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
	}
	| PRINT '(' I_CONST ')' ';' {
		char I[10] = {0};
		sprintf(I, "%d", $3.i_val);
		fprintf(file, "ldc %s\n", I);
		fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
	}
	| PRINT '(' F_CONST ')' ';' {
	
		char I[10] = {0};
		sprintf(I, "%f", $3.f_val);
		fprintf(file, "ldc %s\n", I);
		fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(F)V\n");
	}
;

IF_ELSE
	: if_else_cond

if_else_cond
	: IF '('{
	} condition_list ')' {
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

	}CompoundStmt{
		fprintf(file, "goto EXIT_0\n");
		fprintf(file, "LABEL_%d_%d:\n", compare_num, depth);
		compare_num++;
		if_else_flag = 1;
	}

	| ELSE IF {
		if(if_else_flag == 1){
		}
	}'(' condition_list ')'{
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

	} CompoundStmt{
		fprintf(file, "LABEL_%d_%d:\n", compare_num, depth);
		compare_num++;
	}

	| ELSE {
		fprintf(file, "goto EXIT_0\n");
		fprintf(file, "LABEL_%d_%d:\n", compare_num, depth);
	}  CompoundStmt{
		fprintf(file, "EXIT_0:\n");
	}
;

WHILESTMT
	: WHILE '('{
		while_num++;
		fprintf(file, "LABEL_BEGIN%d:\n", while_num);
	}
	condition_list ')'{
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
		
	} CompoundStmt{
		char conv[10] = {0};
		fprintf(file, "goto LABEL_BEGIN%d\n", while_num);
		fprintf(file, "LABEL_%d_%d:\n", while_num, depth);
		while_num--;
	
	}
;

%%

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
