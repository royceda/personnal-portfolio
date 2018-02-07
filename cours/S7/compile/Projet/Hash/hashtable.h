#ifndef __HASHTABLE__
#define __HASHTABLE__


struct type_s{
  char is_int_float_void;//0, 1 ou 2
  char is_pointer;
  char is_tab;
  char is_fun;
  int  size;

  struct type_s *params;
  //  struct type_s *ret;
};


struct Hashtable{
  struct type_s **table;
};





//Hash



#endif
