/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:05:55 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 16:52:02 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_algo_decider(t_node **stack_a, t_node **stack_b)
{
	int	node_count;

	if (ft_check_sorted(*stack_a) == TRUE)
		exit(EXIT_SUCCESS);
	node_count = ft_node_count(*stack_a);
	if (node_count <= 3)
		ft_algo_max3(stack_a);
	else if (node_count <= 5)
		ft_algo_max5(stack_a, stack_b);
	else
		ft_algo_radix(stack_a, stack_b);
}

void	ft_algo_max3(t_node **stack)
{
	t_node	*biggest;

	biggest = ft_find_biggest(*stack);
	if (biggest->content == (*stack)->content)
		ra(stack);
	else if (biggest->content == (*stack)->next->content)
		rra(stack);
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}

void	ft_algo_max5(t_node **stack_a, t_node **stack_b)
{
	int		i;
	t_node	*smallest;
	int		smallest_pos;

	i = 0;
	while (i < 2)
	{
		smallest = ft_find_smallest(*stack_a);
		smallest_pos = ft_node_pos(*stack_a, smallest);
		while (smallest != *stack_a)
		{
			if (smallest_pos <= 3)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		i++;
	}
	ft_algo_max3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	ft_algo_radix(t_node **stack_a, t_node **stack_b)
{
	size_t			stack_size;
	unsigned int	biggest_num;
	unsigned int	max_digit;

	ft_index_stack(*stack_a);
	stack_size = ft_node_count(*stack_a);
	biggest_num = stack_size - 1;
	max_digit = 0;
	while ((biggest_num >> max_digit) != 0)
		max_digit++;
	ft_algo_radix_sort(stack_a, stack_b, max_digit, stack_size);
}
