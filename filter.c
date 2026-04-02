#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	char c;
	char buffer[1024];
	ssize_t bytes_read;

	if (argc != 2)
		return (0);

	char *buf = buffer; 


	char *s = argv[1];

	while (*s)
	{
		write (1, s , 1);
		++s;
	}
	write (1, "\n", 1);

	while ((bytes_read = read(0, buffer, sizeof(buffer))) > 0)
	{
		write (1, buffer, bytes_read);
	}
	return (0);
}