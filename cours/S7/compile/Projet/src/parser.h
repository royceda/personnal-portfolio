#ifndef __PARSER_H__
#define __PARSER_H__


typedef enum{ SCALAR_T,ARRAY_T, FUNCTION_T} Kind_t;

typedef enum{ INT_T, FLOAT_T, VOID_T} btype_t;

struct type_s {
	Kind_t  kind;
	btype_t bt;
	char    is_pointer;
	int     size;
	struct  types* params;
};
//Pb de pointeur, separation de champs


#endif
