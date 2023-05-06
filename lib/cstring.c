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
  CString_vec_ret->data = malloc(4);

  return CString_vec_ret;
}

static int String_Resize(CString *__s) {
  char *new_data = realloc(__s->data, __s->capacity * 3);

  ASSERT(
    new_data,
    "Could not resize CString.\n"
  )
  
  __s->data = new_data;
  __s->capacity *= 3;

  return EXIT_SUCCESS;
}

extern int String_Clear(CString *__s) {
  free(__s->data);
  __s->data = malloc(4);
  __s->capacity = 4;
  __s->size = 1;
  __s->data[0] = '\0';

  return EXIT_SUCCESS;
}

extern int String_Push_Char(CString *__s, char __value) {
  if (__s->size >= __s->capacity) {
    String_Resize(__s);
  }

  __s->data[__s->size - 1] = __value;
  __s->data[__s->size] = '\0';
  __s->size++;

  return EXIT_SUCCESS;
}

extern int String_Insert(CString *__s, char __value, int __pos) {
  int iter = __s->size;
  
  if (iter < __pos)
    return EXIT_FAILURE;

  if (__s->size + 1 >= __s->capacity) {
    String_Resize(__s);
  }

  while(iter >= __pos) {
    __s->data[iter + 1] = __s->data[iter];
    iter --;
  }

  __s->data[iter + 1] = __value;
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

    String_Resize(__s);
    String_Push(__s, __value);
  }
}

extern void String_Destroy(CString *__s) {
  free(__s->data);
  free(__s);
}