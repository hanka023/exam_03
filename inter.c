#include <stdio.h>
#include <unistd.h>

void iter(char *str2, char *str1)
{
	int i = 0;
	int j = 0;
	char tab[256] = {0};

	while (str1[i])
	{
		tab[str1[i]] = 1;
		++i;
	}
	i = 0;
	while(str2[i])
	{
		if (tab[str2[i]] == 1)
		{
			write (1, &str2[i], 1);
			tab[str2[i]] = 2;
			
		}
		++i;
	}
	return ;
}


int main (int ac, char **av)
{
	if (ac != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	char *str1 = av[1];
	char *str2 = av[2];

	iter(str1, str2);
	write (1, "\n", 1);
	return (0);
	
}