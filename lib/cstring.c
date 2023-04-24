#include <cstring.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ASSERT(__e, ...) if(!(__e) || (__e == NULL)) {    \
    fprintf(stderr, __VA_ARGS__);                         \
    return EXIT_FAILURE;                                  \
}

extern CString *String_Init() {
  CString *CString_vec_ret = calloc(1, sizeof(CString));
  CString_vec_ret->capacity = 4;
  CString_vec_ret->size = 1;
  CString_vec_ret->data = NULL;

  return CString_vec_ret;
}

static int String_Resize(CString *__s) {
  char *new_data = realloc(__s->data, sizeof(char) * __s->capacity);

  ASSERT(
    new_data,
    "Could not resize CString.\n"
  )
  
  __s->data = new_data;

  return EXIT_SUCCESS;
}

extern int String_Push(CString *__s, char *__value) {
  if (__s->size + (strlen(__value) + 1) < __s->capacity) { 
    strcat(__s->data, __value),
    __s->size += strlen(__value) + 1;

    __s->capacity = __s->size;
    String_Resize(__s);

    return EXIT_SUCCESS;
  }

  else {
    __s->capacity *= 3;
    
    ASSERT(
      realloc(__s->data, sizeof(char) * __s->capacity),
      "Could not resize string"
    )

    String_Resize(__s);
    String_Push(__s, __value);

    return EXIT_SUCCESS;
  }
}

extern void String_Destroy(CString *__s) {
  free(__s->data);
  free(__s);
}