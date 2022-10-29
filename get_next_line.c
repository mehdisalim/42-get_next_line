#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			readsize = 1;
	static char	*stc;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	char		*line;
	char		*newline;
	int 		i = 0;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, buff, 0) < 0)
		return (NULL);
	while (readsize > 0)
	{
		readsize = read(fd, buff, BUFFER_SIZE);
		if (!readsize)
			break ;
		buff[readsize] = 0;
		if (!stc)
			stc = ms_strdup(buff);
		else
		{
			tmp = ms_strjoin(stc, buff);
			free(stc);
			stc = tmp;
		}
		if ((newline = ms_strchr(stc, '\n')))
		{
			i = 0;
			break ;
		}
		i++;
	}
	if (readsize == 0 && i > 0)
		return (ms_strdup(stc));
	else if (readsize && i == 0)
	{
		line = ms_substr(stc, 0, newline - stc + 1);
		if(*line == 0)
		{
			free(line);
			return 0;
		}
		free(stc);
		stc = ms_strdup(newline + 1);
		return (line);
	}
	else
	{
		free(stc);
		return (0);
	}
}
