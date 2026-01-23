/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:18:35 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/23 16:32:28 by ahtiftik         ###   ########.fr       */
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

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		ft_lstadd_front(lst, new);
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void    del(void *content)
{
    free(content);
}
//

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

#include <stdio.h>
#include <string.h>

int main()
{
	t_list *head;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	char *s1 = strdup("tiftik");
	char *s2 = strdup("ahmet");
	char *s3 = strdup("alp");

	node1 = ft_lstnew(s1);
	node2 = ft_lstnew(s2);
	node3 = ft_lstnew(s3);

	head = node1;
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	printf("Deger: %s. Adres:%p\n", (head)->content, (head));//tiftik
	printf("Deger: %s. Adres:%p\n", (head)->next->content, (head)->next);//ahmet
	printf("Deger: %s. Adres:%p\n", (head)->next->next->content, (head)->next->next);//alp

	ft_lstclear(&head, del);

	// Listeyi sildik, artik head NULL olmalı.
    if (head == NULL)
        printf("Liste basariyla silindi. Head artik NULL.\n");
    else
        printf("Hata! Head NULL degil.\n");
    // head->content ERIŞIMI YASAK! Sadece pointer adresini yazdirabilirsin:
    printf("Head Adresi: %p\n", head);
}
