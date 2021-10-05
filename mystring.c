#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mystring.h"

int mystrlen(char *s)
{
    int len = 0;
    while (*s) //checking if value equals to zero
    {
        len++;
        s++;
    }

    return len;
}
char *mystrncpy(char *dest, char *source, int n)
{
}
char *mystrcat(char *dest, char *source)
{
}
int mystrcmp(char *s1, char *s2)
{
}
char *mystrchr(char *s, char c)
{
}