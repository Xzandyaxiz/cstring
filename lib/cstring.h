#ifndef cstring
  #define cstring

typedef struct {
  unsigned long size;
  unsigned long capacity;
  char *data;
} String;

extern String *String_Init();

extern int String_Push(String *__s, char *__value);

extern void String_Destroy(String *__s);

#endif