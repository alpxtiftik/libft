/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:49:15 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/23 16:36:09 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
//

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}

#include <stdio.h>

#include <stdio.h>
#include "libft.h"

int main()
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

    printf("%s\n", (char *)head->content);       // ahmet
    printf("%s\n", (char *)head->next->content); // alp
    printf("%s\n", (char *)head->next->next->content); // tiftik
    
    printf("%d", ft_lstsize(head)); // 3
    
    return (0);
}

