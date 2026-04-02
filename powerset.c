// https://github.com/tdanielsousa/42_school_new_exams_rank_03/tree/main/level2


// Assignment name : powerset
// Expected files : *.c *.h
// Allowed functions : atoi, printf, malloc, calloc, realloc, free.
// ---------------------------------------------------------------

// Write a program that will take as argument an integer n follow by a set of integers,
// your program should display all the subsets of whose sum of elements is n.

// In case of a malloc error your program will exit with the code 1.
// We will not test invalid test(for example '1 1 2')
// hint: the empty set is a subset of anyset.


// For example this should work:
// $> ./powerset 3 1 0 2 4 5 3 | cat -e
// 3$
// 0 3$
// 1 2$
// 1 0 2$
// $> ./powerset 12 5 2 1 8 4 3 7 11 | cat -e
// 8 4$
// 1 11$
// 1 4 7$
// 2 3 7$
// 5 4 3$
// 5 7$
// 5 2 1 4$
// $> ./powerset 7 3 8 2| cat -e
// $
// $> ./powerset 0 1 -1| cat -e
// 1 -1$

// The order of lines is not important, but the order of the element in a subset is.
// You must not have any duplicates (for example 2 1, 1 2)
// $> ./powerset 5 1 2 3 4 5| cat -e
// valid:
// 1 4$
// 2 3$
// 5$

// or:
// 2 3$
// 5$
// 1 4$
// not valid:
// 4 1$
// 3 2$
// 5$ 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void print_miniarr(int *mini_arr, int len)
{
    int i = 0;
    while (i < len)
    {
        printf ("%d ", mini_arr[i]);
        ++i;
    }
    printf("\n");
    return;    
}


/* * * * * *  uplne nechutna logika * * * * * * */

void power(int *arr, int *mini_arr, int big_num, int len, int sum, int i, int j)
{
    if (i == len)
    {
        if (sum == big_num)
        {
            print_miniarr(mini_arr, j);
        }
        return;   
    }
    mini_arr[j] = arr[i];
    power(arr, mini_arr, big_num, len, sum + arr[i], i+1, j+1);
    
    power(arr, mini_arr, big_num, len, sum, i + 1, j); 
}

/* * * * * * * * * * * * * * * * * * * * * * * * */

void power_number(int *pole,int big_num,int len)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int *mini_arr = (calloc( len, sizeof (int)));

    power(pole, mini_arr, big_num, len, sum, i, j);

    free(mini_arr);
    return;
}


int *make_arr(char **pole, int len)
{
    int i;
    int *array_int;

    array_int = malloc (sizeof(int) * (len));
    if (!array_int)
        return (0);
   // printf("%d",len);
    i = 0;
    while (i < len)
    {
        array_int[i] = atoi(pole[i + 2]);
        //printf("%d ", array_int[i]);
        ++i; 
    }
    return(array_int);
}


int main (int argc, char *argv[])
{
    int num;
    int len = argc - 2;
    char *s;
    int i = 0;
    int big_num;

    if (argc < 2)
        return (0);

    big_num = atoi(argv[1]);

    int *array_number = make_arr(argv, len);
   
    power_number(array_number, big_num, len);
    
    free(array_number);
   
    return (0);
}
