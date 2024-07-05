/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:44:01 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/10 14:51:49 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (0);
	new->content = value;
	new->index = -1;
	new->next = 0;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new, int i)
{
	t_list	*tmp;

	if (lst)
	{
		if (i == 1)
			(*lst) = new;
		else
		{
			tmp = ft_lstlast(lst);
			tmp->next = new;
			new->next = NULL;
		}
	}
}

t_list	*ft_lstlast(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (ft_lstsize(*lst) == 1)
		return (tmp);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
