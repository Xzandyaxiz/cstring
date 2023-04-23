#include "lib/cstring.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  String *my_string = String_Init();

  String_Push(my_string, "This is a longer string, should be fine...right?");

  printf("%s\n", my_string->data);

  String_Destroy(my_string);
}