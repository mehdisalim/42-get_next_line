#include "get_next_line.h"

static size_t	ms_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

static size_t	ms_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	int		length;

	i = 0;
	length = ms_strlen(src);
	if (n == 0)
		return (length);
	while (src[i] && --n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (length);
}

char	*ms_strchr(const char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ms_strlen(str);
	while (i <= len)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}

char	*ms_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = ms_strlen((char *)s1) + 1;
	dest = (char *)malloc(len);
	if (!dest)
		return (0);
	ms_strlcpy(dest, (char *)s1, len);
	return (dest);
}

char	*ms_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	d = (char *)malloc(ms_strlen(s1) + ms_strlen(s2) + 1);
	if (!d)
		return (0);
	while (*s1)
		d[i++] = *s1++;
	while (*s2)
		d[i++] = *s2++;
	d[i] = 0;
	return (d);
}

char	*ms_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	slen;

	if (!s)
		return (0);
	slen = ms_strlen(s);
	if (len > slen)
		len = slen;
	d = (char *)malloc(len + 1);
	if (!d)
		return (0);
	if (start < ms_strlen(s))
		ms_strlcpy(d, &s[start], len + 1);
	d[len + 1] = 0;
	return (d);
}