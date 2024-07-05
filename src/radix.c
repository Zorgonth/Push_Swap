/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:56:00 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/06 15:55:24 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		i;

	i = 0;
	head = *stack;
	min = NULL;
	while (head)
	{
		if ((head->index == -1) && (i == 0 || head->content < min->content))
		{
			min = head;
			i = 1;
		}
		head = head->next;
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

void	sortit(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = get_max(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 0)
				push(stack_b, stack_a, "pb\n");
			else
				rotate(stack_a, "ra\n");
		}
		while (ft_lstsize(*stack_b) != 0)
			push2(stack_b, stack_a, "pa\n");
		i++;
	}
}

long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	return (res * sign);
}
