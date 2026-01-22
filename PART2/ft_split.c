/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:30:03 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/17 15:14:09 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//
//
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(s);
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*tmp;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - (size_t)start)
		len = s_len - (size_t)start;
	tmp = ((char *) malloc(sizeof(char) * (len + 1)));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s + start, len + 1);
	return (tmp);
}
//

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**free_arr(char **sp, size_t i)
{
	while (i > 0)
	{
		i--;
		free(sp[i]);
	}
	free(sp);
	return (NULL);
}

static char	**fill(char **sp, char const *s, char c, size_t cw)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (i < cw)
	{
		while (s[j] && s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		sp[i] = ft_substr(s, start, j - start);
		if (!sp[i])
			return (free_arr(sp, i));
		i++;
	}
	sp[i] = NULL;
	return (sp);
}

char	**ft_split(char const *s, char c)
{
	size_t	cw;
	char	**sp;

	if (!s)
		return (NULL);
	cw = count_words(s, c);
	sp = (char **) malloc(sizeof(char *) * (cw + 1));
	if (!sp)
		return (NULL);
	if (!fill(sp, s, c, cw))
		return (NULL);
	return (sp);
}

#include <stdio.h>

int main()
{
	char *s = "Ahmet Alp Tiftik";
	char **split = ft_split(s, ' ');
	int i = 0;
	while(split[i])
	{
		while(split[i])
		{
			printf("%s\n", split[i]);
			i++;
		}
	}
	
/*
	printf("%s\n", split[0]);
	printf("%s\n", split[1]);
	printf("%s\n", split[2]);
*/
	free(split);	

}