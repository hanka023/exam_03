#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFERSIZE 1024

char * gnl(FILE * file) {
	int ret;
	static char buffer[BUFFERSIZE];
	if (!buffer)
		exit(1);
	char * line;
	while ((ret = read(file, &buffer, BUFFERSIZE)))
	{
		if (ret == -1)
			return 1;
		/* code */
		int size = strchr(buffer, '\n');
		if (size) {
			line = malloc(size * sizeof(char));
			memcpy(line, &buffer, size );
			memmove(&buffer, (buffer + size), ret - size);
			buffer[ret - size] = '\0';
			return(line);
		} else {
			
		}
			

	}
	
}

int main(int argc, char ** argv) {

	FILE * file = fopen(argv[1], "r");
	char * ret;
	while((ret = gnl(file))) {
		printf("%s", ret);
	}

	return 0;
}