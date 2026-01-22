/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:47:00 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/17 18:50:55 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

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
//
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

void    del(void *content)
{
    free(content);
}

//
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

#include <stdio.h>
#include <string.h>
#include "libft.h" // Libft header'ini eklemeyi unutma

// Test için del fonksiyonu
void del(void *content)
{
    free(content);
}

int main()
{
    t_list *head = NULL;
    t_list *node1;
    t_list *node2;
    t_list *node3;
    t_list *node4;

    char *s1 = strdup("tiftik");
    char *s2 = strdup("ahmet");
    char *s3 = strdup("alp");
    char *s4 = strdup("silinecek");

    node1 = ft_lstnew(s1);
    head = node1; // Head artik node1'i gosteriyor (tek yildiz)

    node2 = ft_lstnew(s2);
    node3 = ft_lstnew(s3);
    node4 = ft_lstnew(s4);

    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);
    ft_lstadd_back(&head, node4);

    printf("Deger: %s. Adres:%p\n", (char *)head->content, head); // tiftik
    printf("Deger: %s. Adres:%p\n", (char *)head->next->content, head->next); // ahmet
    printf("Deger: %s. Adres:%p\n", (char *)head->next->next->content, head->next->next); // alp
    printf("Deger: %s. Adres:%p\n", (char *)head->next->next->next->content, head->next->next->next); // silinecek

    // Node4'ü siliyoruz
    ft_lstdelone(node4, del);

    // Zinciri onariyoruz (node3'un next'ini null yapiyoruz)
    head->next->next->next = NULL;
    node4 = NULL; // Dangling pointer'i temizliyoruz

    if (head->next->next->next == NULL)
        printf("Zincir koptu, artik 4. eleman yok.\n");
    else
        printf("Bunu goremezsin.\n");
        
    printf("Silindi. Pointer artik NULL: %p\n", node4);
    
    return (0);
}

