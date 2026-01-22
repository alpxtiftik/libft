/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:28:09 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/17 14:20:59 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char f(unsigned int i, char c)
{
	if (i % 2 == 0 && (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')))
	{
		if ('A' <= c && c <= 'Z')
			return (c + 32);
		if ('a' <= c && c <= 'z')
			return (c - 32);
	}
	return c;
}
//
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	size_t		i;
	char		*ns;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	ns = (char *) malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (NULL);
	while (i < len)
	{
		ns[i] = f((unsigned int)i, s[i]);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}

#include <stdio.h>

int main()
{
	char *s = "ahmet alp tiftik";
	char *strmapi = ft_strmapi(s, f);
	printf("%s", strmapi);
	free(strmapi); 
}