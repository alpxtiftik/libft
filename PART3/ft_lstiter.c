/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:36:15 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/23 16:34:36 by ahtiftik         ###   ########.fr       */
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

void	f_modify(void *content)
{
	char	*str;
	int		i;

	// 1. void pointer'ı char pointer'a çeviriyoruz ki işlem yapabilelim
	str = (char *)content;
	i = 0;
	while (str[i])
	{
		// Küçük harfse büyüt (ASCII -32 mantığı)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}
//

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}


#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
    t_list *head = NULL;
    t_list *node1;
    t_list *node2;
    t_list *node3;

    char *s1 = strdup("tiftik");
    char *s2 = strdup("alp");
    char *s3 = strdup("ahmet");

    node1 = ft_lstnew(s1);
    head = node1;

    node2 = ft_lstnew(s2);
    node3 = ft_lstnew(s3);

    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node3);

    // Sira: ahmet -> alp -> tiftik
    printf("%s\n", (char *)head->content);       // ahmet
    printf("%s\n", (char *)head->next->content); // alp
    printf("%s\n", (char *)head->next->next->content); // tiftik

	ft_lstiter(head, f_modify);
	printf("%s\n", (char *)head->content);       // ahmet
    printf("%s\n", (char *)head->next->content); // alp
    printf("%s\n", (char *)head->next->next->content); // tiftik
	
    return (0);
}
