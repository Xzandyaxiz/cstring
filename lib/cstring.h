#ifndef cstring
  #define cstring

typedef struct {
  unsigned long size;
  unsigned long capacity;
  char *data;
} CString;

#define string_of(str) ((str->data != NULL) ? str->data : "Null")
#define String CString*

extern CString *String_Init();

extern int String_Push(CString *__s, char *__value);
extern int String_Push_Char(CString *__s, char __value);
extern int String_Insert(CString *__s, char __value, int __pos);

extern int String_Clear(CString *__s);
extern void String_Destroy(CString *__s);

#endif