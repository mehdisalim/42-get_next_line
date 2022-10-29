#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "unistd.h"
#include "string.h"
#include "stdio.h"
#include "fcntl.h"
#include "stdlib.h"

char	*ms_substr(char const *s, unsigned int start, size_t len);
char	*ms_strjoin(char const *s1, char const *s2);
char	*ms_strdup(const char *s1);
char	*ms_strchr(const char *str, int c);
char	*get_next_line(int fd);

#endif
