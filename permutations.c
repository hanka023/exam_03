// Assignment name : permutations

// Expected files : *.c *.h
// Allowed functions : puts, malloc, calloc, realloc, free, write
// ---------------------------------------------------------------

// Write a program that will print all the permutations of a string given as argument.

// The solutions must be given in alphabetical order.

// We will not try your program with strings containing duplicates (eg: 'abccd')

// For example this should work:
// $> ./permutations a | cat -e
// a$
// $> ./permutations ab | cat -e
// ab$
// ba$
// $> ./permutations abc | cat -e
// abc$
// acb$
// bac$
// bca$
// cab$
// cba$

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int len = 0;

    char *s = str;
    while (*s)
    {
        ++s;
        ++len;
    }
    return (len);
}

char *allocate_string(int len)
{
    char *str;

    str = malloc (sizeof (char) * (len + 1));
    if (!str)
        return (0);
    str[len] = '\0';

    return (str);
}

void copy_string(char *str1, char *str2)
{
    while (*str2)
    {
        *str1 = *str2;
        ++str1;
        ++str2;
    }
   return ;
}

void write_str(char *s, char *start)
{
    char *str;
    
    str = start;
    while (*str)
    {
        write (1, str, 1);
        ++str;
    }
    write (1, "\n", 1);
    return;
}

void swap (char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

void perm(char *str, char *s, char *start)
{

    if (*str == '\0')
    {
        write_str(s, start); // vypis na konci
        return;
    }

 /*  DIVNA LOGIKA  - NAUCIT SE NAZPAMET !!! */

    s = str;
    while (*s != '\0')
    { 
        swap (s, str);
        perm (str + 1, s , start);
        swap (s, str);
        ++s;
    }

/* * * * * * * * * * * * * * * * * * * * */
  
}


int main (int argc, char *argv[])
{
    char *str;
    char *s;
    char *start;
    int len;

    if (argc != 2)
        return (0);

    str = argv[1];
    len = ft_strlen (argv[1]);
    s = allocate_string(len);
    copy_string (s, str);
    start = str;
    write_str(str, start);
    perm (str, s, start);
    free (s);
    write (1, "\n", 1);
    return (0);

}