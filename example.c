#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[])
{
     char *str;
     str = init("Hello"); // intializes data strctures required
     concat(str, " there!"); // concatenates str with specified string
     // handles memory allocation

     printf("%s\n", fold(str)); // folds a string to a specific length

     uninit(str); // deintialize data structures required
}