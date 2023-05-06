#include "lib/cstring.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  CString *my_string = String_Init();

  String_Push_Char(my_string, 'y');
  String_Push_Char(my_string, 'e');
  String_Push_Char(my_string, 'a');
  String_Push_Char(my_string, 'h');
  String_Insert(my_string, 'w', 4);
  printf("%s\n", string_of(my_string));

  String_Destroy(my_string);
}