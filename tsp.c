// Assignment name			: tsp
// Expected files			: *.c *.h
// Allowed functions   : write, sqrtf, getline, fseek, fscanf, ferror, feof, fabsf, memcpy, fprintf, fclose, malloc, calloc, realloc, free, fopen, errno, stderr, stdin, stdout
// -------------------------------------------------------

// The first publication referring to this problem as the "traveling salesman 
// problem" is found in the 1949 RAND Corporation report by Julia Robinson, 
// "On the Hamiltonian game (a traveling salesman problem)."

// Here is how she defines the problem:

// "The purpose of this note is to give a method for solving a problem related
// to the traveling salesman problem. It seems worthwhile to give a description
// of the original problem. One formulation is to find the shortest route for a
// salesman starting from Washington, visiting all the state capitals and then
// returning to Washington.

// More generally, to find the shortest CLOSED CURVE containing n given points 
// in the plane."

// for example with the following set of cities:
// 0, 0
// 1, 0
// 2, 0
// 0, 1
// 1, 1
// 2, 1
// 1, 2
// 2, 2
// which can be presented as follows:
// + + +
// + + +
//   + +
// the shortest path is:
//  _____
// |__   |
//    |__|

// so you should print the length of this path that is:
// 8.00

// Write a program that will read a set of city coordinates in the form 
// '%f, %f\n' from the standard input and will print the length of the shortest
// possible path containing all these cities under the form '%.2f'.

// Your program will not be tested with more than 11 cities.

// You will find in this directory a file tsp.c containing all the boring parts of
// this exercise and example files to help you test your program.

// hint: in order to use sqrtf, add -lm at the end of your compilation command.

// For example this should work:
// $> cat square.txt
// 1, 1
// 0, 1
// 1, 0
// 0, 0
// $> ./tsp < square.txt | cat -e
// 4.00$

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <float.h>


typedef struct{
	float x;
	float y;
} city;

float delka(city city1, city city2)
{
	float len = 0;
	float tmp = 0;

	if (city1.y == city2.y)
		len = fabsf(city2.x - city1.x);
	else if (city1.y == city2.y)
		len == fabs(city2.x - city1.x);
	else
	{
		tmp = ((city2.x - city1.x) * (city2.x - city1.x) + (city2.y - city1.y) * (city2.y - city1.y));
		len = sqrt(tmp);
	}
	//printf ("delka %.2f", len);
	return (len);
}

void swap(city *a, city *b)
{
	city tmp = *a;
	*a = *b;
	*b = tmp;
}

void way_len(city *start, city *cities1, city *cities2, float *len, float *min_len, int city_number, int i)
{
	float dist = 0;
	float tmp = 0;
	float cesta_domu;
	

	// if (!cities1 || !cities2)
	// 	return;
		
	dist = (delka (*cities1, *cities2));
	*len = *len + dist;

	//printf ("kontrola %.2f %.2f", cities1[i].x, cities1[i].y );

	if (i == city_number)
	{ 
		cesta_domu =  delka(start[0], *cities2);
	
		*len = *len + cesta_domu;
		if ((*min_len == -1) || (*len < *min_len))
		*min_len = *len;

		printf ("min len %.2f \n", *min_len);
		return;
	}
	swap(cities1, cities2);
	way_len(start, cities1, cities2 , len, min_len, city_number, i+1);
	swap(cities1, cities2);
	*len = *len -dist;
}

int main (int argc, char *argv[])
{
	FILE *ftpr;
	int i = 0;
	float len = 0;
	float min_len = -1;
	

	ftpr = fopen("file.txt", "r");
	if (ftpr == NULL)
	{
		printf ("nebezi ftpr\n");
		return (0);
	}
	char output [50];

	float f = 0;
	i = 0;

	float a;
	float b;
	while (i < 11 && (fscanf(ftpr, " %f, %f ", &a, &b)) == 2)
		++i;
	
	i = 0;
	rewind(ftpr);

	city *cities = malloc (sizeof (city) * 12);
		if (!cities)
		{
			printf ("malloc selhal\n");
			   fclose(ftpr);
			   return (0);
		}
			
	while (i < 11 && (fscanf(ftpr, " %f, %f ", &cities[i].x, &cities[i].y)) == 2)
	{
		printf("Mesto %d: x=%.0f, y=%.0f\n", i, cities[i].x, cities[i].y);
		++i;
	}
	int city_number = i;
	i = 0;
	way_len(cities, &cities[i], &cities[i + 1], &len, &min_len, city_number, i);


fclose(ftpr);
free(cities);
return (0);

}

