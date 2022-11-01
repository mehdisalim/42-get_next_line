#include "get_next_line.h"

char *getfull_line(int fd, char *stc)
{
	int			readsize = 1;
	char		*buff;
	char		*tmp;

	buff = (char *)malloc(sizeof(char ) * BUFFER_SIZE + 1);
	while (readsize != 0)
	{
		readsize = read(fd, buff, BUFFER_SIZE);
		if (readsize <= 0)
			break ;
		buff[readsize] = 0;
		if (!stc)
			stc = ms_strdup("");
		tmp = ms_strjoin(stc, buff);
		free(stc);
		stc = tmp;
		if (ms_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (stc);
}

char *pack(char *string)
{
	char *stc;
	int i = 0;
	if (string == 0)
		return (0);
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	stc = ms_substr(string, i + 1, ms_strlen(string) - i);
	if(!*stc)
		return 0;
	string[i + 1] = 0;
	return stc;
}

char	*get_next_line(int fd)
{
	static char	*stc;
	// char		*line;
	char		*string;
	(void) fd;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = getfull_line(fd,stc);
	stc = pack(string);
	return (string);
}
