#ifndef cstring
  #define cstring

typedef struct {
  unsigned long size;
  unsigned long capacity;
  char *data;
} CString;

#define string_of(str) ((str->data != NULL) ? str->data : "Null")

extern CString *String_Init();

extern int String_Push(CString *__s, char *__value);

extern void String_Destroy(CString *__s);

#endif