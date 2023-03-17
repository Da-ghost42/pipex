#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

char	ft_substr(char *s,  int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		str[i] = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	return (str[j] = 0, str);
}
static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free (strs[j]);
	free (strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	word = ft_count_word(s, c);
	strs = (char **)malloc((word + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		strs[j] = ft_substr((char *)s, i, size);
		if (strs == NULL)
			return (ft_free(strs, j), NULL);
		i += size;
	}
	return (strs[j] = 0, strs);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		len_s1;
	int		len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = (char *)malloc(len_s1 + len_s2 + 1);
	if (!p)
		return (NULL);
	ft_strcpy (p, (char *) s1);
	ft_strcat (p, s2);
	return (p);
}
char	*ft_strdup(const char *s)
{
	char	*q;
	size_t	n;

	n = -1;
	q = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!q)
		return (NULL);
	while (s[++n])
		q[n] = s[n];
	return (q[n] = '\0',q);
}