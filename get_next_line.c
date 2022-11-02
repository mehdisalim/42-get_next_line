#include "get_next_line.h"
#include <stdio.h>

char	*ft_getbuffer(char *lstr)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (lstr[i] && lstr[i] != '\n')
		i++;
	if (!lstr[i])
	{
		free(lstr);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(lstr) - i + 1));
	if (!str)
	{
		free(lstr);
		return (NULL);
	}
	i++;
	j = 0;
	while (lstr[i])
		str[j++] = lstr[i++];
	str[j] = '\0';
	free(lstr);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	char	buff[BUFFER_SIZE + 1];
	int		n;
	char	*newline;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
			n = 0;
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

