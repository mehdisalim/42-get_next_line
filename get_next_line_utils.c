#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

static size_t	ft_strlcpy(char *dst, char *src, size_t n)
{
	size_t	i;
	int		length;

	i = 0;
	length = ft_strlen(src);
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
char	*ft_strjoin(char *lstr, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!lstr)
		lstr = ft_strdup("");
	if (!lstr || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(lstr) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (lstr[++i] != '\0')
		str[i] = lstr[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(lstr) + ft_strlen(buff)] = '\0';
	free(lstr);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	slen;

	if (!s || !*s)
		return (0);
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	d = (char *)malloc(len + 1);
	if (!d)
		return (0);
	if (start < ft_strlen(s))
		ft_strlcpy(d, &s[start], len + 1);
	return (d);
}
char	*ft_strdup(char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen((char *)s1) + 1;
	dest = (char *)malloc(len);
	if (!dest)
		return (0);
	ft_strlcpy(dest, (char *)s1, len);
	return (dest);
}