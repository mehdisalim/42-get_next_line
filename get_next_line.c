#include "get_next_line.h"

char	*ft_getbuffer(char *lstr)
{
	char	*str;
	char	*newline;

	newline = ft_strchr(lstr, '\n');
	free(lstr);
	if (!newline)
		return (NULL);
	str = ft_strdup(newline + 1);
	return (str);
}


char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	char	buff[BUFFER_SIZE + 1];
	int		n;
	char	*newline;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, buff, 0) < 0)
		return (0);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		buff[n] = '\0';
		str = ft_strjoin(str, buff);
		if(ft_strchr(buff, '\n'))
			break ;
	}
	newline = ft_strchr(str, '\n');
	if (!str[0])
		line = 0;
	else if (!newline)
		line = ft_strdup(str);
	else
		line = ft_substr(str, 0, newline - str + 1);	
	str = ft_getbuffer(str);
	return (line);
}

