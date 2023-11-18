/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:59:30 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 16:53:00 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"

# define TRUE 1
# define FALSE 0

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

char	**ft_arg_parser(int argc, char **argv);
int		ft_arg_check_digit(int argc, char **argv);
int		ft_arg_check_overflow(int argc, char **argv);
int		ft_compare_int_min(int len, char **argv, int i);
int		ft_compare_int_max(int len, char **argv, int i);
int		ft_arg_check_duplicates(int argc, char **argv);
t_node	*ft_init_stack_a(t_node *stack_a, int argc, char **argv);
void	ft_free_strs(char **num_strs);

t_node	*ft_node_new(int content);
void	ft_node_prepend(t_node **head, t_node *new);
void	ft_node_append(t_node **head, t_node *new);
void	ft_node_del(t_node **head, t_node *node_to_delete);
void	ft_node_clearlist(t_node **head);
t_node	*ft_node_last(t_node *head);
size_t	ft_node_count(t_node *head);
int		ft_node_pos(t_node *head, t_node *target);
t_node	*ft_node_find(t_node *head, int value);

void	ft_swap(t_node **head);
void	ft_push(t_node **remove_from, t_node **push_to);
void	ft_rotate(t_node **head);
void	ft_reverse(t_node **head);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_b, t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

void	ft_algo_decider(t_node **stack_a, t_node **stack_b);
void	ft_algo_max3(t_node **stack);
void	ft_algo_max5(t_node **stack_a, t_node **stack_b);
void	ft_algo_radix(t_node **stack_a, t_node **stack_b);
void	ft_algo_radix_sort(t_node **stack_a, t_node **stack_b,
			unsigned int max_digit, size_t stack_size);
int		ft_check_sorted(t_node *stack);
t_node	*ft_find_biggest(t_node *stack);
t_node	*ft_find_smallest(t_node *stack);
void	ft_index_stack(t_node *stack);

#endif