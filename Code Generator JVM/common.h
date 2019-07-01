#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef enum { INT_t, FLOAT_t, STRING_t, BOOL_t } SEMTYPE;

typedef struct rule_type{
	int i_val, reg, id_or_val;
	double f_val;
	char* id;
	char* string;
	SEMTYPE type;
} RULE_TYPE;

#endif
