// BROKEN GNL


#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
    int i = 0;
    while (s[i] != '\0')
	{
		if (s[i] == (char)c)
        	return ((char *)(s + i));
		i++;	
	}
    return NULL;
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;
	while (i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		++i;
	}
	return dest;
}

size_t ft_strlen(char *s)
{
    size_t i = 0;

	if (!s)
		return(0);
    while (s[i] != '\0')
		++i;
    return (i);
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i = 0;
	unsigned char *d = dest;
	const unsigned char *s = src;

	if (!dest || !src)
		return (0);
	if (d == s)
		return (dest);	
	else if(d > s && d > s + n)
		while (n--)
			d[n] = s[n];
	else 
	{
		while (i < n)
		{
			d[i] = s[i];
			++i;
		}
	}
	dest = d;
	return (dest);
}


void ft_strdup (char *dest, char *src)
{
	int i = 0;
	while (src[i] != '\0')
		++i;
	
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return;

	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';

	return;
		
	
}


// int str_append_mem(char **s1, char *s2, size_t size2)
// {
//     size_t size1 = ft_strlen(*s1);

//     char *tmp = malloc(size2 + size1 + 1);
//     if (!tmp)
//         return 0;
//     ft_memcpy(tmp, *s1, size1);
//     ft_memcpy(tmp + size1, s2, size2);
//     tmp[size1 + size2] = 0;
//     free(*s1);
//     *s1 = tmp;
//     return 1;
// }

char *extract_line(char *buffer)
{
	char *newline;
	int i = 0;
	int n = 0;

	while (buffer[i] != '\0' || buffer[i] != '\n')
	{
		++i;
		if (buffer[i] == '\n')
		++i;
	}
	newline = malloc (sizeof (char) * (i + 1));

	while (n < i)
	{
		newline[n] = buffer[n];
		++n;
	}
	newline[n] = '\0';
	return (newline);

}


void cut_buffer(char *buffer)
{
	char *start = NULL;
	char *pole = NULL;

	if (!buffer)
		return;
	
	start = ft_strchr(buffer, '\n');
	if (! start)
	{ 
		free (buffer);
		return;
	}
	start++;
	ft_strdup (pole, start);
	free(buffer);
	buffer = pole; 
	return;
}

char *join_buffer(char *buffer, char *maly_buffer)
{
	int i = 0;
	int j = 0;

	while (buffer[i] != '\0')
		++i;
	while (maly_buffer[j] != '\0')
		++j;

	char *pole = malloc (sizeof(char) * (i + j + 1));
	if (!pole)
		return (NULL);
	i = 0;
	j = 0;

	while (buffer[i] != '\0')
	{
		pole[i] = buffer[i];
		++i;
	}
	while (maly_buffer[j] != '\0')
	{
		pole[i] = maly_buffer[j];
		++i;
		++j;
	}
	pole[i] = '\0';

	free(buffer);
	free(maly_buffer);

	buffer = pole;
	return (buffer);
	

}


char *get_next_line(int fd)
{
    static char *buffer = NULL;
	char maly_buffer[BUFFER_SIZE + 1];
    char *line = NULL;

    char *is_new_line = ft_strchr(buffer, '\n');
	ssize_t byte_read;

    while (!is_new_line)
    {
        byte_read = read(fd, maly_buffer, BUFFER_SIZE + 1);
        if (! byte_read)
			return(NULL);

 		if (!join_buffer(buffer, maly_buffer))
            return NULL;
	}
	line = extract_line (buffer);
	cut_buffer(buffer);

    return (line);
}

int main(int argc, char *argv[])
{
	int fd;
    char *line;
  	if (argc < 2)
	return (0);

    fd = open(argv[1], O_RDONLY);

    if (fd < 0)
    {
        perror("open");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}