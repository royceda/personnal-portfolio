#ifndef PARSER_H
#define PARSER_H

struct type_s{
  char is_int_float_void; // 0, 1 ou 2
  char is_pointeur;
  char is_tab;
  char is_fun;
  int size;

  struct type_s *params;
};

#endif
