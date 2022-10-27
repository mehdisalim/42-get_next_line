#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			readsize;
	static char	*s;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	char		*line;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	while ((readsize = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[readsize] = 0;
		if (!s)
			s = my_strdup(buff);
		else
		{
			tmp = my_strjoin(s, buff);
			free(s);
			s = tmp;
		}
		if ((newline = my_strchr(s, '\n')))
			break ;
	}
	if (readsize > 0)
	{
		line = my_substr(s, 0, newline - s + 1);
		s = my_strdup(newline + 1);
		return (line);
	}
	else
	{
		free(s);
		return (NULL);
	}
}
