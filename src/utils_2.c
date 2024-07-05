/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:37:06 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/10 17:06:09 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_2_min(int **stack_a, int **stack_b, int argc)
{
	int	min;
	int	a_size;
	int	b_size;

	b_size = 0;
	a_size = argc - 1;
	min = min_((*stack_a), a_size);
	if (min == 1)
		s((*stack_a), "sa\n");
	else if (min == 2)
	{
		r((*stack_a), argc, "ra\n");
		r((*stack_a), argc, "ra\n");
	}
	else if (min == 3)
	{
		rr((*stack_a), argc, "rra\n");
		rr((*stack_a), argc, "rra\n");
	}
	else if (min == 4)
		rr((*stack_a), argc, "rra\n");
	pb(stack_a, stack_b, a_size, b_size);
	b_size++;
	a_size--;
	find_2_min_2(stack_a, stack_b, a_size, b_size);
}

void	find_2_min_2(int **stack_a, int **stack_b, int a_size, int b_size)
{
	int	min;

	min = min_((*stack_a), a_size);
	if (min == 1)
		s((*stack_a), "sa\n");
	else if (min == 2)
	{
		r((*stack_a), a_size + 1, "ra\n");
		r((*stack_a), a_size + 1, "ra\n");
	}
	else if (min == 3)
		rr((*stack_a), a_size + 1, "rra\n");
	pb(stack_a, stack_b, a_size, b_size);
}

int	sorted(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}	
	return (1);
}

int	ft_free_error(int *stack_a, int *stack_b, int i)
{
	free(stack_a);
	free(stack_b);
	if (i != 0)
		write(1, "ERROR\n", 6);
	return (0);
}

int	fix_args(int argc, char *argv)
{
	char	**tmp;
	int		i;

	argc--;
	i = 0;
	tmp = ft_split(argv, ' ');
	while (tmp[i])
		i++;
	if (!ft_check_p(i, tmp))
		return (ft_free(tmp, i), 0);
	if (i < 7)
		init(i, tmp);
	if (i >= 7)
		input_2(i, tmp);
	ft_free(tmp, i);
	return (0);
}
