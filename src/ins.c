/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:46:14 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/05 10:57:59 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	r(int *stack, int argc, char *c)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack[0];
	while (i < argc - 2)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
	write(1, c, ft_strlen(c));
}

void	s(int *stack, char *c)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	write(1, c, ft_strlen(c));
}

void	rr(int *stack, int argc, char *c)
{
	int	i;
	int	tmp;

	tmp = stack[argc - 2];
	i = argc - 3;
	while (i >= 0)
	{
		stack[i + 1] = stack[i];
		i--;
	}
	stack[0] = tmp;
	write(1, c, ft_strlen(c));
}

void	pa(int **stack_a, int **stack_b, int a_size, int b_size)
{
	int	tmp;

	a_size += 1;
	b_size -= 1;
	tmp = (*stack_b)[0];
	if (*stack_b)
	{
		(*stack_a) = ft_reallocate_2(stack_a, a_size);
		(*stack_a)[0] = tmp;
		(*stack_b) = ft_reallocate_1(stack_b, b_size);
		write(1, "pa\n", ft_strlen("pa\n"));
	}
}

void	pb(int **stack_a, int **stack_b, int a_size, int b_size)
{
	int	tmp;

	b_size += 1;
	a_size -= 1;
	tmp = (*stack_a)[0];
	if (*stack_a)
	{
		(*stack_b) = ft_reallocate_2(stack_b, b_size);
		(*stack_b)[0] = tmp;
		(*stack_a) = ft_reallocate_1(stack_a, a_size);
		write(1, "pb\n", ft_strlen("pb\n"));
	}
}
