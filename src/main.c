/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:58:35 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/19 11:15:49 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	stack_b = (int *)malloc(sizeof(int));
	stack_a = input(argc, argv);
	if (is_sorted(stack_a, argc))
	{
		ft_free_error(stack_a, stack_b, 0);
		return (0);
	}
	if (argc == 3 && stack_a[0] > stack_a[1])
		r(stack_a, argc, "ra\n");
	if (argc == 4)
		sort_3_numbers(&stack_a, argc);
	if (argc == 5)
		sort_4_numbers(&stack_a, &stack_b, argc);
	if (argc == 6)
		sort_5_numbers(&stack_a, &stack_b, argc);
	ft_free_error(stack_a, stack_b, 0);
	return (0);
}

int	check_dups(int argc, char **argv)
{
	int	a[10000];
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_numeric(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_p(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc < 2 || !is_numeric(argv))
		return (write(1, "ERROR\n", ft_strlen("ERROR\n")), 0);
	while (argv[i])
	{
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			return (write(1, "ERROR\n", ft_strlen("ERROR\n")), 0);
		i++;
	}
	if (!check_dups(argc, argv))
		return (write(1, "ERROR", ft_strlen("ERROR")), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	args(argc, argv);
	return (0);
}
