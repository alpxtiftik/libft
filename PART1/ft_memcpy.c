/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:14:43 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/23 21:36:49 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdest = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	while (n--)
		*pdest++ = *psrc++;
	return (dest);
}


void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n-- > 0)
		*p++ = (unsigned char) c;
	return (s);
}
int main()
{
	char a[10] = {'1', '2', '3', '4', '5'};
	char b[10];

	ft_memcpy(b, a, 5);
	int i = 0;
	while(i<5)
	{
		printf("%c", b[i]);
		i++;
	}
}
