#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "unistd.h"
#include "string.h"
#include "stdio.h"
#include "fcntl.h"
#include "stdlib.h"

char	*my_substr(char const *s, unsigned int start, size_t len);
char	*my_strjoin(char const *s1, char const *s2);
char	*my_strdup(const char *s1);
char	*my_strchr(const char *str, int c);
char	*get_next_line(int fd);

#endif
