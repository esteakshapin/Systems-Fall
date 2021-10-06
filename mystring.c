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
    int a;
    for (a = 0; a < n; a++)
    {
        *(dest + a) = *(source + a);
    }

    return dest;
}
char *mystrcat(char *dest, char *source)
{
    int destLength = strlen(dest);

    int counter = 0;
    while (*source)
    {
        *(dest + destLength + counter) = *source;
        source++;
        counter++;
    }
    *(dest + destLength + counter) = 0;

    return dest;
}

int mystrcmp(char *s1, char *s2)
{
    int sumS1 = 0;
    while (*s1)
    {
        sumS1 += (int)*s1;
        s1++;
    }

    int sumS2 = 0;
    while (*s2)
    {
        sumS2 += (int)*s2;
        s2++;
    }

    return sumS1 - sumS2;
}

char *mystrchr(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
        {
            return s;
        }
        s++;
    }
    if (c == 0)
    {
        return s++;
    }
    return NULL;
}