/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:26:06 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/16 21:30:19 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

#include <stdio.h>
int main()
{
	ft_putchar_fd('a', 0);
	printf("\n");
	ft_putchar_fd('a', 1);
	printf("\n");
	ft_putchar_fd('a', 2);
	printf("\n");
	ft_putchar_fd('a', 3);
	printf("\n");
	ft_putchar_fd('a', 4);
}