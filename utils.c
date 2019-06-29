/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergeygusachenko <sergeygusachenko@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:26:11 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/28 19:40:59 by sergeygusac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	error(char *str)
{
	ft_putstr(str);
	exit(1);
}

int		check_f(t_ssl **ssl, char *str)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'p')
			return (*ssl)->f_p = i;
		else if (str[i] == 'q')
			return (*ssl)->f_q = i;
		else if (str[i] == 'r')
			return (*ssl)->f_r = i;
		else if (str[i] == 's')
			return (*ssl)->f_s = i;
		i++;
	}
	return 0;
}

void	parse_flag(t_ssl **ssl, char **str)
{
	int i;

	i = 2;
	while (str[i])
	{
		if (str[i][0] == '-')
		{
			if (((*ssl)->max_f = check_f(ssl, str[i])))
				i++;
			else
				error("invalid  option");
		}
		else if(i == 2 && str[i][0] != '-')
			(*ssl)->no_f++;
		i++;
	}
}
