/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:30:13 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 16:38:41 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_free_strs(char **num_strs)
{
	int	i;

	i = 0;
	while (num_strs[i])
	{
		free(num_strs[i]);
		i++;
	}
	free(num_strs);
}

t_node	*ft_init_stack_a(t_node *stack_a, int argc, char **argv)
{
	int		i;
	t_node	*temp;
	t_node	*tail;

	i = 0;
	while (i < argc)
	{
		temp = ft_node_new(ft_atoi(argv[i]));
		temp->index = -1;
		if (stack_a == NULL)
		{
			stack_a = temp;
			tail = stack_a;
		}
		else
			ft_node_append(&tail, temp);
		i++;
	}
	return (stack_a);
}
