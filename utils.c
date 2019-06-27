/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:26:11 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/24 22:06:02 by sgusache         ###   ########.fr       */
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
			return (*ssl)->f_p++;
		else if (str[i] == 'q')
			return (*ssl)->f_q++;
		else if (str[i] == 'r')
			return (*ssl)->f_r++;
		else if (str[i] == 's')
			return (*ssl)->f_s++;
		i++;
	}
	return 0;
}

void	parse_flag(t_ssl **ssl, char **str)
{
	int i;
	int res;

	i = 2;
	while (str[i])
	{
		if (str[i][0] == '-')
		{
			if (check_f(ssl, str[i]))
				i++;
			else
				error("invalid  option");
		}
		else
			(*ssl)->no_f++;
	}
}
