/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:46:44 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 17:02:30 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_sorted(t_node *stack)
{
	if (stack == NULL)
		return (FALSE);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

t_node	*ft_find_biggest(t_node *stack)
{
	t_node	*biggest;

	if (stack == NULL)
		return (FALSE);
	biggest = stack;
	while (stack->next)
	{
		if (stack->next->content > biggest->content)
			biggest = stack->next;
		stack = stack->next;
	}
	return (biggest);
}

t_node	*ft_find_smallest(t_node *stack)
{
	t_node	*smallest;

	if (stack == NULL)
		return (FALSE);
	smallest = stack;
	while (stack->next)
	{
		if (stack->next->content < smallest->content)
			smallest = stack->next;
		stack = stack->next;
	}
	return (smallest);
}

void	ft_index_stack(t_node *stack)
{
	t_node			*smallest;
	t_node			*head;
	size_t			stack_size;
	unsigned int	i;
	int				j;

	head = stack;
	stack_size = ft_node_count(stack);
	i = 0;
	j = 0;
	while (i < stack_size)
	{
		stack = head;
		smallest = NULL;
		while (stack)
		{
			if (stack->index == -1
				&& (smallest == NULL || stack->content < smallest->content))
				smallest = stack;
			stack = stack->next;
		}
		if (smallest != NULL)
			smallest->index = j++;
		i++;
	}
}

void	ft_algo_radix_sort(t_node **stack_a, t_node **stack_b,
		unsigned int max_digit, size_t stack_size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < max_digit)
	{
		j = 0;
		while (j < stack_size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_b, stack_a);
		i++;
	}
}
