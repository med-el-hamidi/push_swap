/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:35:09 by mel-hami          #+#    #+#             */
/*   Updated: 2025/02/27 12:35:16 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_stack *a)
{
	int	min;

	min = a->nbr;
	while (a)
	{
		if (min > a->nbr)
			return (0);
		min = a->nbr;
		a = a->next;
	}
	return (1);
}

t_instruct	*ft_lstnew_(char *str)
{
	t_instruct	*node;

	node = (t_instruct *)malloc(sizeof(t_instruct));
	if (!node)
		return (NULL);
	node->str = ft_strdup(str);
	if (!node->str)
		return (NULL);
	node->next = NULL;
	return (node);
}

static t_instruct	*ft_lstlast_(t_instruct *lst)
{
	t_instruct	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

void	ft_lstadd_back_(t_instruct **lst, t_instruct *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast_(*lst)->next = new;
	else
		*lst = new;
}

void	ft_lstclear_(t_instruct **lst)
{
	t_instruct	*tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		if ((*lst)->str)
			free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
}
