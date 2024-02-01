#include "monty.h"

int custom_strmatch(char *s1, const char *s2)
{
    char *src;
    char *dst;

    for (src = dst = s1; *src != '\0'; src++)
    {
        if (strchr(s2, *src) != NULL) {
            *dst++ = *src;
        }
    }

    *dst = '\0';

    return (0);
}