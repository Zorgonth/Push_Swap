/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:08:52 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/10 17:05:23 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int					content;
	struct s_list		*next;
	int					index;
}				t_list;

void	r(int *stack, int argc, char *c);
void	rr(int *stack, int argc, char *c);
void	s(int *stack, char *c);
void	pa(int **stack_a, int **stack_b, int a_size, int b_size);
void	pb(int **stack_a, int **stack_b, int a_size, int b_size);
void	sort_3_numbers(int **stack_a, int argc);
void	sort_4_numbers(int **stack_a, int **stack_b, int argc);
void	sort_5_numbers(int **stack_a, int **stack_b, int argc);
void	ft_fix(int **stack_a, int **stack_b, int a_size, int b_size);
void	find_2_min(int **stack_a, int **stack_b, int argc);
void	find_2_min_2(int **stack_a, int **stack_b, int a_size, int b_size);
void	ft_lstadd_back(t_list **lst, t_list *new, int i);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	push(t_list **stack1, t_list **stack2, char *c);
void	sort(t_list **stack_a, t_list **stack_b);
void	push2(t_list **s1, t_list **s2, char *c);
void	ft_free_lst(t_list **a, t_list **b);
void	index_stack(t_list **stack);
void	sortit(t_list **stack_a, t_list **stack_b);
char	**ft_free(char **str, int x);
char	*ft_word(char const *str, int start, int end);
char	**ft_split(char const *s, char c);
char	*ft_r(char *s);
char	**args(int argc, char **argv);
char	*ft_strjoin(char *s1, char const *s2);
long	ft_atol(const char *str);
int		fix_args(int argc, char *argv);
int		*ft_reallocate_1(int **stack, int size);
int		*ft_reallocate_2(int **stack, int size);
int		min_(int *stack, int size);
int		is_sorted(int *stack, int argc);
int		max_(int *stack, int size);
int		*input(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_free_error(int *stack_a, int *stack_b, int i);
int		ft_check_p(int argc, char **argv);
int		main(int argc, char **argv);
int		ft_lstsize(t_list *lst);
int		input_2(int argc, char **argv);
int		get_max(t_list **stack);
int		rotate(t_list **stack, char *c);
int		check_dups(int argc, char **argv);
int		sorted(t_list **stack);
int		is_numeric(char **argv);
int		ft_wordend(char const *s, char c, int i);
int		ft_countwords(char const *s, char c);
int		init(int argc, char **argv);
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list **lst);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);

#endif