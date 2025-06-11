/* safestr.c */
#include "safestr.h"

// return data/contents of specified string
char* fold(String* str)
{
    return str->data;
}

// custom memcpy function
void copy(void* dst, const void *src, const unsigned int n)
{
    const char* psrc; // source string
    char* pdst; // destination string
    unsigned int x; // number of bytes of string
    // loop and copy contents over to dst pointer
    for(x=n, psrc=(const char*)src, pdst=(char*)dst; x; psrc++, pdst++, x--)
    {
        *pdst = *psrc; // set each element of pdst to psrc
    }

    return;
}
// length function of string
unsigned int length(const char *str)
{
     int n;
     const char *p;
     // loop until p reaches '0'
     for(n = 0, p=str; *p; p++, n++);
     return n;
}
// custom string concatenation function
bool concat(String* dst, const char *src)
{
    unsigned int n, cursize, size;
    char* cp;
    String *p;
    n = length(src);
    cursize = (dst->count + 1) + sizeof(struct s_string); // current siz of dst string buffer
    size = cursize + n; // add n to cursize for number of bytes in string to concatenate or length of src
    p = (String*) realloc(dst, size); // realloc dst string to size
    // check if realloc failed
    if(!p)
    {
        return false;
    }
    // end of old segement, is where we put new data
    cp = p->data + p->count;
    copy(cp, src, n); // copy src into cp
    p->count += n; //  increment count by n
    cp = p->data + p->count;
    cp = 0;
    return true;

}
// intialize string
String *init(const char* str)
{
    unsigned int size, n;
    n = length(str);
    String *p;
    size = (n + 1) + sizeof(struct s_string);
    p = (String*) malloc(size); // allocate memory for string*
    assert(p);
    *p = (String) {};
    // copy p->data into str for n bytes (length of str) buffer
    copy(p->data, str, n);
    p->count = n; // set count of output string to n
    return p;

}

int main(int argc, char *argv[])
{
    String* str;
    char buf1[16], buf2[16];
    str = init("Hello ");
    printf("'%s'\n", str->data);
    concat(str, "There");
    printf("%s\n", fold(str));
    uninit(str);
    return 0;
}