#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *buffer ="";
	char buff;
	while (read(fd, &buff, 1))
	{
		strcat(buffer, &buff);
		if (buff == '\n')
			return (buffer);
	}
	return (NULL);
}
