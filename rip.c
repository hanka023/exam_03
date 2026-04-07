// Assignment name: rip
// Expected files: *.c *.h
// Allowed functions: puts, write
// --------------------------------------------------------------------------------
// Write a program that will take as argument a string containing only parenthesis.
// If parenthesis are unbalanced (for example "())") your program shall remove the
// minimum number of parenthesis for the expression to be balanced.
// By removing we mean replacing by spaces.
// You will print all the solutions (can be more than one).
// The order of the solutions is not important.
// For example this should work:
// (For readability reasons the '_' means space and the spaces are for readability only.)
// $> ./rip '( ( )' | cat -e
// _ ( ) $
// ( _ ) $
// $> ./rip '( ( ( ) ( ) ( ) ) ( ) )' | cat -e
// ( ( ( ) ( ) ( ) ) ( ) ) $
// $> ./rip '( ) ( ) ) ( )' | cat -e
// ( ) ( ) _ ( ) $
// ( ) ( _ ) ( ) $
// ( _ ( ) ) ( ) $
// $> ./rip '( ( ) ( ( ) (' | cat -e
// ( ( ) _ _ ) _ $
// ( _ ) ( _ ) _ $
// ( _ ) _ ( ) _ $
// _ ( ) ( _ ) _ $
// _ ( ) _ ( ) _ $

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void putstr(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		++str;
	}
	write (1, "\n", 1);
	return ;
}

int ft_strlen(char *str)
{
    int i = 0;
    while (*str)
    {
        ++i;
        ++str;
    }
    return (i);
}

char *array(char *str)
{
    char *start;
    int len = ft_strlen(str);
    char *s = malloc(sizeof (char) * (len + 1));
    if (!s)
        return (0);
    s[len] = '\0';
    start = s;

    while (*str)
    {
        *s = *str;
        ++s;
        ++str;
    }
    s = start;
    return (s);
}


int parity(char *str)
{
    int left = 0; 

    while(*str)
    {
        if (*str == '(')
            ++left;
        if (*str == ')')
        {  
			 if (left <= 0)
                return (0);
            --left;
        }
        ++str;
    }
	if (left == 0)
		return (1);  //parity OK
	else
		return (0);
}

int to_remove(char *str)
{
    int left = 0; 
	int removal = 0;

    while(*str)
    {
        if (*str == '(')
            ++left;
        else if (*str == ')')
        {   
			if (left <= 0)
            	++removal;  
			else 
				--left;
		}
        ++str;
    }
	removal = removal + left;
	//printf ("%d \n", removal);
    return (removal);   //(if left == 0) parity OK
}

void backtrack(char *str, int dif, int len, int i)
{
    
    int par = parity(str); 
    char c;

    if (dif == 0)
	{
		if (parity (str))
        	putstr(str);
		return;
	}	
    if (i == len)
        return;
  	backtrack(str, dif, len, i + 1);
   	if (dif > 0)
  	{
	    c = str[i]; 
	    str[i] = '_';
	    backtrack(str, dif - 1, len, i + 1);
	    str[i] = c;
  	} 
}

void pars(char *str)
{
    int left = 0; 
    int right = 0;
    int i = 0;
    char *start = str;
    int len = strlen(str);
   	int dif = to_remove(str);  //kolik zavorek smazu
    int par = parity(str);  //jestli jsou uzavrene a muzu tisknout

    backtrack(str, dif, len, i);

    return;
}

int main (int argc, char *argv[])
{

    if (argc != 2)
        return (0);

    char *str = array(argv[1]);

    pars(str);

    free(str);
    return (0);
}