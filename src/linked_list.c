/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:03:03 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 17:01:53 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*ft_node_new(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_node_prepend(t_node **head, t_node *new)
{
	if (*head != NULL)
		(*head)->prev = new;
	new->prev = NULL;
	new->next = *head;
	*head = new;
}

void	ft_node_append(t_node **tail, t_node *new)
{
	if (!tail || !new)
		return ;
	if (*tail == NULL)
		*tail = new;
	else
	{
		(*tail)->next = new;
		new->prev = *tail;
		new->next = NULL;
		*tail = new;
	}
}

void	ft_node_del(t_node **head, t_node *node_to_delete)
{
	if (*head == node_to_delete)
		*head = node_to_delete->next;
	if (node_to_delete->next != NULL)
		node_to_delete->next->prev = node_to_delete->prev;
	if (node_to_delete->prev != NULL)
		node_to_delete->prev->next = node_to_delete->next;
	free(node_to_delete);
}

void	ft_node_clearlist(t_node **head)
{
	t_node	*temp;

	if (*head == NULL)
		return ;
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		ft_node_del(head, temp->prev);
	}
	free(temp);
	*head = NULL;
}
