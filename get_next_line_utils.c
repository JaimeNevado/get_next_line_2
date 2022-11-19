#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;
	
	i = 0;
	j = 0;
	if (!s1)
		return (0);
	str = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	strleng;

	strleng = ft_strlen(s);
	i = 0;
	if (start > strleng)
		return (ft_strdup(""));
	if (len == strleng && start < len)
		str = malloc((len - start) + 1);
	if (len > strleng)
		str = malloc(strleng + 1);
	if (len < strleng)
		str = malloc(len + 1);
	if (!s || !str)
		return (ft_strdup(""));
	while (len-- && s[start] != '\0')
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = ft_strlen((char *)s1);
	str = malloc((size * sizeof(char)) + 1);
	if (!str)
		return (0);
	while (i < size)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{	
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

