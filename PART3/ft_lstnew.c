/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:35:25 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/23 16:35:46 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

#include <stdio.h>

int main()
{
	t_list *node1;
	t_list *node2;
	char *s = "alp";
	int i = 3;

	node1 = ft_lstnew(s);
	printf("%s\n", (node1->content));
	node2 = ft_lstnew(&i);
	printf("%d\n", *(int *)(node2->content));
}