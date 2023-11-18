/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:00:04 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 16:57:53 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//FOR TESTING PURPOSES
// void	ft_print_stack(t_node *stack_a, t_node *stack_b)
// {
// 	t_node	*p_a;
// 	t_node	*p_b;
// 	size_t	length_a;
// 	size_t	length_b;
// 	size_t	max_size;
// 	int		i;
// 	p_a = stack_a;
// 	length_a = ft_node_count(p_a);
// 	p_b = stack_b;
// 	length_b = ft_node_count(p_b);
// 	if (length_a > length_b)
// 		max_size = length_a;
// 	else
// 		max_size = length_b;
// 	ft_printf("A:\t\t\t\tB:\n");
// 	i = 0;
// 	while((size_t)i < max_size)
// 	{
// 		if (p_a != NULL)
// 		{
// 			ft_printf("%d, index: %d", p_a->content, p_a->index);
// 			p_a = p_a->next;
// 		}
// 		else
// 			ft_printf("-");
// 		ft_printf("\t\t\t\t");
// 		if (p_b != NULL)
// 		{
// 			ft_printf("%d", p_b->content);
// 			p_b = p_b->next;
// 		}
// 		else
// 			ft_printf("-");
// 		ft_printf("\n");
// 		i++;
// 	}
// 	ft_printf("\n\n");
// }

int	main(int argc, char **argv)
{
	char	**num_strs;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		exit (EXIT_SUCCESS);
	num_strs = ft_arg_parser(argc, argv);
	argc = 0;
	while (num_strs[argc])
		argc++;
	ft_arg_check_digit(argc, num_strs);
	ft_arg_check_overflow(argc, num_strs);
	ft_arg_check_duplicates(argc, num_strs);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_init_stack_a(stack_a, argc, num_strs);
	ft_free_strs(num_strs);
	ft_algo_decider(&stack_a, &stack_b);
	ft_node_clearlist(&stack_a);
	ft_node_clearlist(&stack_b);
	return (0);
}
