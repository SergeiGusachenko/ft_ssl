/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:55:31 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/07 04:46:00 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int		get_hash(char *str)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		sum += 11 * (int)str[i] + i + (int)str[i];
		i++;
	}
	sum = sum / 7;
	return (sum % NUM_F);
}

int		main(int argc, char **argv)
{
	t_s_func func;

	func = NULL;
	if (argc > 1)
	{
		func = get_s_func(argv[1]);
		if (func != NULL)
			func(argv);
		else
		{
			ft_printf("ft_ssl: Error: '%s' is an invalid command \n\n",
			argv[1]);
			ft_printf("Standart commands:\nmd5\nsha256\n");
		}
	}
	else
		error("Usage : {hash_function} [flag] {file_name}\n");
	return (0);
}
