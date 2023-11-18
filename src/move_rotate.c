/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:24 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 16:55:02 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate(t_node **head)
{
	t_node	*rotate_target;
	t_node	*last_node;

	if (!head || !(*head) || !((*head)->next))
		return ;
	rotate_target = *head;
	last_node = ft_node_last(*head);
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next = rotate_target;
	rotate_target->prev = last_node;
	rotate_target->next = NULL;
}

void	ra(t_node **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_node **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
