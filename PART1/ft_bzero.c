/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:13:02 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/23 20:33:12 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n-- > 0)
	{
		*p++ = 0;
	}
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
	int *a = (int *)malloc(sizeof(int));
	ft_bzero(a, 4);
	printf("%d\n", a[0]);
	ft_memset(a, 1, 1);
	printf("%d", a[0]);
}
