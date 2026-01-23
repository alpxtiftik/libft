/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:41:07 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/23 20:16:40 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n-- > 0)
		*p++ = (unsigned char) c;
	return (s);
}

#include <stdio.h>

int main()
{
	int *a = malloc(sizeof(int)); // 4 Byte
	if(!a)
		return (1);
	ft_memset(a, 1, 2);
	ft_memset(a, 0, 1);
	printf("%d", a[0]);
}
