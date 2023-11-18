/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:28 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 16:54:10 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push(t_node **from, t_node **to)
{
	t_node	*push_target;

	if (!from || !(*from))
		return ;
	push_target = *from;
	*from = (*from)->next;
	if (!from)
		(*from)->prev = NULL;
	push_target->prev = NULL;
	if (*to != NULL)
	{
		push_target->next = *to;
		(*to)->prev = push_target;
	}
	else
		push_target->next = NULL;
	*to = push_target;
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
