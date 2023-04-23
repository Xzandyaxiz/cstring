#include "lib/cstring.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  CString *my_string = String_Init();

  String_Push(my_string, "sdsd");

  printf("%s\n", string_of(my_string));

  String_Destroy(my_string);
}