/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:43:20 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/23 16:30:27 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
//

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	t_list *head = NULL;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	char *s1 = "tiftik";
	char *s2 = "alp";
	char *s3 = "ahmet";

	node1 = ft_lstnew(s1);
	head = node1;

	node2 = ft_lstnew(s2);
	node3 = ft_lstnew(s3);

	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);

	// Sira: ahmet -> alp -> tiftik
	printf("%s\n", (char *)head->content);             // ahmet
	printf("%s\n", (char *)head->next->content);       // alp
	printf("%s\n", (char *)head->next->next->content); // tiftik
	return (0);
}