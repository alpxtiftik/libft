/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:33:49 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/23 22:10:27 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
int main()
{
	char *s = (char *) malloc(sizeof(char) * 5);
	s = "ahmet";
	char *s2 = (char *) malloc(sizeof(char) * 5);
	s2 = "ahmed";
	printf("%d", ft_memcmp(s, s2, 5));
	
}
