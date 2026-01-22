/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:11:32 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/16 21:27:05 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//
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
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

#include <stdio.h>

int main()
{
	char *s = "ahmet alp tiftik";
	printf("%s", s);
	ft_striteri(s, f);
	printf("%s", s);
}