/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:50:33 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/10 14:10:30 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotate(t_list **stack, char *c)
{
	t_list	*head;
	t_list	*last;

	if (ft_lstsize(*stack) == 1)
		return (0);
	head = *stack;
	last = ft_lstlast(stack);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	write(1, c, ft_strlen(c));
	return (0);
}

void	push(t_list **stack1, t_list **stack2, char *c)
{
	t_list	*tmp;

	if (!*stack2)
		return ;
	tmp = (*stack2)->next;
	(*stack2)->next = *stack1;
	*stack1 = *stack2;
	*stack2 = tmp;
	write(1, c, ft_strlen(c));
}

void	push2(t_list **s1, t_list **s2, char *c)
{
	t_list	*tmp;

	if (!*s1)
		return ;
	tmp = (*s1)->next;
	(*s1)->next = *s2;
	*s2 = *s1;
	*s1 = tmp;
	write(1, c, ft_strlen(c));
}

char	*ft_r(char *s)
{
	s = (char *)malloc(2 * sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '1';
	s[1] = '\0';
	return (s);
}
