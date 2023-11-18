/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:26 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 17:00:11 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_reverse(t_node **head)
{
	t_node	*last_node;

	if (!head || !(*head) || !((*head)->next))
		return ;
	last_node = ft_node_last(*head);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = *head;
	(*head)->prev = last_node;
	*head = (*head)->next;
	*head = last_node;
}

void	rra(t_node **stack_a)
{
	ft_reverse(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	ft_reverse(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
	ft_printf("rrr\n");
}
