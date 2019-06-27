/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:55:31 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/26 19:47:22 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int get_hash(char *str)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while(str[i])
	{
		sum += 11 * (int)str[i] + i + (int)str[i];
		i++;
	}
	sum = sum / 7;
	return (sum % NUM_SPEC);
}

int main(int argc, char **argv)
{
	t_spec_func func;

	int i = get_hash("md5");
	i = get_hash("me5");

	func = NULL;
	if (argc > 1)
	{
		func = get_spec_func(argv[1]);
		if(func != NULL)
			func(argv);
		else
			error("Error: invalid command.\n");
	}
	error("Usage : {hash_function} [flag] {file_name}\n");
	return (0);
}
