/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:00:25 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/05 10:57:20 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(int *stack, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else if (stack[i] > stack[i + 1])
			return (0);
	}
	return (1);
}

void	ft_fix(int **stack_a, int **stack_b, int a_size, int b_size)
{
	if (!is_sorted((*stack_a), a_size + 1))
	{
		pb(stack_a, stack_b, a_size, b_size);
		a_size--;
		b_size++;
		sort_3_numbers(stack_a, a_size + 1);
		pa(stack_a, stack_b, a_size, b_size);
	}
}

void	sort_3_numbers(int **stack_a, int argc)
{
	int	max;

	max = max_(*stack_a, argc - 1);
	if (max == 0)
	{
		r((*stack_a), argc, "ra\n");
	}
	else if (max == 1)
		rr((*stack_a), argc, "rra\n");
	if ((*stack_a)[0] > (*stack_a)[1])
		s((*stack_a), "sa\n");
}

void	sort_4_numbers(int **stack_a, int **stack_b, int argc)
{
	int	min;
	int	a_size;
	int	b_size;

	if (argc == 6)
	{
		a_size = argc - 2;
		b_size = 1;
	}
	else
	{
		b_size = 0;
		a_size = argc - 1;
	}
	min = min_((*stack_a), a_size);
	if (min == 1)
		s((*stack_a), "sa\n");
	else if (min == 2)
	{
		r((*stack_a), argc, "ra\n");
		r((*stack_a), argc, "ra\n");
	}
	else if (min == 3)
		rr((*stack_a), argc, "rra\n");
	ft_fix(stack_a, stack_b, a_size, b_size);
}

void	sort_5_numbers(int **stack_a, int **stack_b, int argc)
{
	find_2_min(stack_a, stack_b, argc);
	sort_3_numbers(stack_a, argc - 2);
	pa(stack_a, stack_b, 3, 2);
	pa(stack_a, stack_b, 4, 1);
}
