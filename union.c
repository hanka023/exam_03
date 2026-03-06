#include <stdio.h>
#include <unistd.h>


char ft_union(char *str1, char *str2)
{
	char tab[256] = {0};

	int a = 0;
	while(str1[a])
	{
		if (tab[(int)str1[a]] == 0)
		{
			tab[(int)str1[a]] = 1;
			write (1, &str1[a], 1);
		}
			a++;
	}
	a = 0;

	while (str2[a])
	{
		if(tab[(int)str2[a]] == 0)
		{
			tab[(int)str2[a]] = 1;
			write (1, &str2[a], 1);
		}
		a++;
	}
}


int main(int ac, char **av)
{
	if (ac !=3)
		return (0);
	
	char *str1 = av[1];
	char *str2 = av[2];

	ft_union(str1, str2);
	write (1, "\n", 1);
	return (0);
}