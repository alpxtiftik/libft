/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:43:45 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/23 16:35:35 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//
#include <string.h>

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

void    del(void *content)
{
    free(content);
}

void	*f_modify(void *content)
{
	char	*new;
	char	*old;
	int		i;

	old = (char *)content;
	new = strdup(old);
	if(!new)
		return (NULL);
	i = 0;
	while (new[i])
	{
		if (new[i] >= 'a' && new[i] <= 'z')
			new[i] -= 32;
		i++;
	}
	return(new);
}
//

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!(new_node))
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
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

	t_list *new_head = ft_lstmap(head, f_modify, del);
	printf("%s\n", (char *)new_head->content);       // ahmet
    printf("%s\n", (char *)new_head->next->content); // alp
    printf("%s\n", (char *)new_head->next->next->content); // tiftik
	
    return (0);
}