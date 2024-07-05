/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:22:57 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/06 11:45:08 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	min_(int *stack, int size)
{
	int	min;
	int	i;
	int	j;

	j = 0;
	i = 0;
	min = stack[0];
	while (j < size)
	{
		if (stack[j] < min)
		{
			i = j;
			min = stack[j];
		}
		j++;
	}
	return (i);
}

int	max_(int *stack, int size)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max = stack[0];
	while (j < size)
	{
		if (stack[j] > max)
		{
			i = j;
			max = stack[j];
		}
		j++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	get_max(t_list **stack)
{
	int		max;
	t_list	*head;
	int		i;

	i = 0;
	head = *stack;
	max = head->index;
	while (head)
	{
		if (max < head->index)
			max = head->index;
		head = head->next;
	}
	while (max >> i)
		i++;
	return (i);
}
