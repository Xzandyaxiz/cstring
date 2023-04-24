#include <cstring.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  CString *my_string = String_Init();

  String_Destroy(my_string);
}