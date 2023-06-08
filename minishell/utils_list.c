/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:16:30 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/06/02 11:13:36 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstdelone_v2(t_arg_list **lst)
{
	if (!lst)
		return ;
	free((*lst)->content);
	free(*lst);
}

void	ft_lstclear_v2(t_arg_list **lst)
{
	t_arg_list	*tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone_v2(lst);
		*lst = tmp;
	}
	lst = NULL;
}

t_arg_list	*ft_lstnew_v2(char *content, char flag)
{
	t_arg_list	*new_element;

	new_element = malloc(sizeof(t_arg_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	(*new_element).flag = flag;
	new_element->next = NULL;
	return (new_element);
}

void	ft_lstadd_back_v2(t_arg_list **lst, t_arg_list *new)
{
	t_arg_list	*last;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
