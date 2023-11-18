/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:35:42 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 16:58:19 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//parse arguments that are input as multiple strings or just one string
char	**ft_arg_parser(int argc, char **argv)
{
	char	**num_strs;
	size_t	len;
	int		i;

	argc--;
	i = 0;
	if (argc == 1)
		num_strs = ft_split(argv[1], ' ');
	else
	{
		num_strs = malloc(sizeof(char **) * (argc + 1));
		if (!num_strs)
			exit (EXIT_FAILURE);
		while (i < argc)
		{
			len = ft_strlen(argv[i + 1]);
			num_strs[i] = malloc(sizeof(char *) * (len + 1));
			if (!num_strs[i])
				exit (EXIT_FAILURE);
			ft_strlcpy(num_strs[i], argv[i + 1], len + 1);
			i++;
		}
		num_strs[i] = NULL;
	}
	return (num_strs);
}
