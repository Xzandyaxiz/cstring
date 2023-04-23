#include "cstring.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ASSERT(__e, ...) if(!(__e) || (__e == NULL)) { fprintf(stderr, __VA_ARGS__); exit(1); }

extern String *String_Init() {
  String *string_vec_ret = calloc(1, sizeof(String));
  string_vec_ret->capacity = 4;
  string_vec_ret->size = 1;
  string_vec_ret->data = NULL;

  return string_vec_ret;
}

static int String_Resize(String *__s) {
  char *new_data = realloc(__s->data, sizeof(char) * __s->capacity);

  ASSERT(
    new_data,
    "Could not increase string size.\n"
  );

  __s->data = new_data;
}

extern int String_Push(String *__s, char *__value) {
  if (__s->size + (strlen(__value) + 1) < __s->capacity) {
    strcat(__s->data, __value),

    __s->size += strlen(__value);
    
    __s->capacity = __s->size;
    String_Resize(__s);

    return EXIT_SUCCESS;
  }

  else {
    __s->capacity *= 3;
    char *new_data = realloc(__s->data, sizeof(char) * __s->capacity);

    String_Resize(__s);

    String_Push(__s, __value);
    return EXIT_SUCCESS;
  }
}

extern void String_Destroy(String *__s) {
  free(__s->data);
  free(__s);
}