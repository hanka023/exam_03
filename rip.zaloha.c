// https://github.com/tdanielsousa/42_school_new_exams_rank_03/tree/main/level2/rip


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



int ft_strlen(char *str)
{
	int i = 0;

	while(*str)
	{
		++i;
		++str;
	}

	return (i);
}

char *arrow(char *str)
{
	char *s;
	int len = ft_strlen (str);
	
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s[len] = '\0';
	
	char *start = s;

	while (*str)
	{
		*s = *str;
		++s;
		++str;
	}
	return(start);
}



int min_to_remove(char *str)
{
	int open = 0;
	int close = 0;

	while (*str)
	{
		if (*str == '(')
		{
			if (open >= close)
				++open;
			else if (open < close)
				--close;
		}
		
		else if (*str == ')')
		{
			if (close >= open)
				++close;
			else if (close < open)
				--open;
		}
		++str;
	}
	printf ("open: %d\nclose %d\n", open, close);
	return (close + open);
}



void pars(char *arr)
{
	int i = min_to_remove(arr);

	if (min_to_remove(arr) == 0)
	{
		printf ("%s\n", arr);
	}
	printf ("pocet zavorek na smazani %d\n", i);
}





int main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);

	char *str = arrow(argv[1]);

	pars (str);

	printf ("%s\n", str);

	free(str);
	return(0);
}
