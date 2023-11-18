/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:35:13 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 16:54:29 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*ft_node_last(t_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

size_t	ft_node_count(t_node *head)
{
	size_t	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

int	ft_node_pos(t_node *head, t_node *target)
{
	int	pos;

	pos = 1;
	while (head)
	{
		if (head == target)
			return (pos);
		pos++;
		head = head->next;
	}
	return (-1);
}

t_node	*ft_node_find(t_node *head, int value)
{
	if (head == NULL)
		return (NULL);
	if (head->content == value)
		return (head);
	return (ft_node_find(head->next, value));
}
