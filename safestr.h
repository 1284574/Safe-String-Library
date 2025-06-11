/* safestr.h */
#define _GNU_SOURCE // for assert_perror() function
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#define uninit(x)        free(x)

// string struct (definition of a string)
struct s_string
{
     unsigned int count; // how large string is in terms of contents
     char data[0];  // array to store data/contents
};
typedef struct s_string String;

void copy(void*, const void*, const unsigned int);
char *fold(String*);
unsigned int length(const char*);
String *init(const char*);
bool concat(String*, const char*);
int main(int, char**);