# CString
CString is a C library that features an easy to use string type.

## Installation
On a linux based system, you could either clone the repository and run `install.sh` or do the following:
* Download the `libcstring.so` file and copy it to a directory where your linker path is set to, for example `/usr/lib`.
* Download the `cstring.h` header file and copy it to `/usr/include`.

## Examples
Create a string using the `CString` type:
```c
CString *my_string = String_Init();
```
Concatenate strings using the `String_Push()` function:
```c
String_Push(my_string, "this is a very informative message.");
```
Print the string to the stdout:
```c
printf("%s\n", my_string->data);
```
Note that you can also use the `string_of()` macro.

Free the string from memory using String_Destroy() function:
```c
String_Destroy(my_string);

## Installation
On a linux based system, you could either clone the repository and run `install.sh` or do the following:
* Download the `libcstring.so` file and copy it to a directory where your linker path is set to, for example `/usr/lib`.
* Download the `cstring.h` header file and copy it to `/usr/include`.

## Examples
Create a string using the `CString` type:
```c
CString *my_string = String_Init();
```
Concatenate strings using the `String_Push()` function:
```c
String_Push(my_string, "this is a very informative message.");
```
Print the string to the stdout:
```c
printf("%s\n", my_string->data);
```
Note that you can also use the `string_of()` macro.

Free the string from memory using String_Destroy() function:
```c
String_Destroy(my_string);
```