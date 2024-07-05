/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:44:10 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/10 14:19:50 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	input_2(int argc, char **argv)
{
	int		i;
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*new;

	i = 1;
	argc--;
	stack_a = (t_list **)malloc(sizeof(t_list));
	if (!stack_a)
		return (0);
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_b)
		return (ft_free_lst(stack_a, 0), 0);
	while (i < argc + 1)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, new, i);
		i++;
	}
	if (sorted(stack_a))
		return (ft_free_lst(stack_a, stack_b), 0);
	index_stack(stack_a);
	sortit(stack_a, stack_b);
	ft_free_lst(stack_a, stack_b);
	return (1);
}

int	*input(int argc, char **argv)
{
	int	*stack_a;
	int	i;

	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		return (0);
	i = 1;
	while (i < argc)
	{
		stack_a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (stack_a);
}

int	*ft_reallocate_1(int **stack, int size)
{
	int	*tmp_stack;
	int	i;

	i = 0;
	if (size == 0)
	{
		free(*stack);
		return (0);
	}
	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	while (i < size)
	{
		tmp_stack[i] = (*stack)[i + 1];
		i++;
	}
	if (stack)
		ft_free_error(*stack, 0, 0);
	return (tmp_stack);
}

int	*ft_reallocate_2(int **stack, int size)
{
	int	*tmp_stack;
	int	i;

	i = 0;
	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	if (size > 1)
	{
		while (i < size)
		{
			tmp_stack[i + 1] = (*stack)[i];
			i++;
		}
	}
	if (stack)
		ft_free_error(*stack, 0, 0);
	return (tmp_stack);
}

void	ft_free_lst(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	tmp = *b;
	free(a);
	while (tmp)
	{
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
	free(b);
}
