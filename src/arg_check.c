/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:11:51 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/04 16:59:32 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//check if arguments are digits
int	ft_arg_check_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-' && ft_isdigit(argv[i][1]))
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (0);
}

//check if arguments will overflow if converted to ints
int	ft_arg_check_overflow(int argc, char **argv)
{
	int		i;
	int		len;

	i = 0;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (argv[i][0] == '-')
			ft_compare_int_min(len, argv, i);
		else
			ft_compare_int_max(len, argv, i);
		i++;
	}
	return (0);
}

//check if argument with negative num is bigger than int_min
int	ft_compare_int_min(int len, char **argv, int i)
{
	char	*int_min;

	if (len > 11)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (len < 11)
		return (0);
	int_min = "-2147483648";
	if (ft_strncmp(argv[i], int_min, len) > 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (0);
}

//check if argument with positive num is bigger than int_max
int	ft_compare_int_max(int len, char **argv, int i)
{
	char	*int_max;

	if (len > 10)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (len < 10)
		return (0);
	int_max = "2147483647";
	if (ft_strncmp(argv[i], int_max, len) > 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (0);
}

//check for duplicate arguments
int	ft_arg_check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	len_arr[2];

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			len_arr[0] = ft_strlen(argv[i]);
			len_arr[1] = ft_strlen(argv[j]);
			if (len_arr[0] == len_arr[1])
			{
				if (ft_strncmp(argv[i], argv[j], len_arr[0]) == 0)
				{
					write(2, "Error\n", 6);
					exit(EXIT_FAILURE);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
