#include "get_next_line.h"

char	*getfull_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	// char	*tmp;
	int readsize = 1;

	while (readsize)
	{
		readsize = read(fd, buffer, BUFFER_SIZE);
		if (!readsize)
			break ;
		buffer[readsize] = 0;
		if (!line)
			line = ms_strdup(buffer);
		else
			line = ms_strjoin(line, buffer);
		if(ms_strchr(buffer, '\n'))
			break;
	}
	return line;
}



char	*get_next_line(int fd)
{
	// char	*buffer = getfull_line(fd);
	printf("%s", getfull_line(fd));
		printf("%s", getfull_line(fd));
	return (0);
}
