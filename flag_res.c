/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 23:45:36 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/01 04:07:24 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	m_p(t_ssl **ssl, char *str)
{
	int		num_r;
	char	buff[BUFFSIZE];
	char	*temp;

	num_r = (int)*str;
	num_r = 0;
	temp = ft_strnew(1);
	while ((num_r = read(1, &buff, BUFFSIZE)) > 0)
	{
		buff[num_r] = '\0';
		temp = ft_update(temp, ft_strjoin(temp, buff));
		(*ssl)->msg_len+=num_r;
	}
	md5((unsigned char*)temp, ssl);
	print_msg(*ssl);
}

void	m_s(t_ssl **ssl, char *str, char **arg, int pos)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	while(str[i] != 's')
		i++;
	if (str[i + 1] == '\0')
	{
		if(arg[pos + 1] == NULL)
		{
			ft_printf("md5: option requires an argument -- s\n");
			error("usage: md5 [-pqrtx] [-s string] [files ...]\n");
		}
		(*ssl)->msg_len = ft_strlen(arg[pos + 1]);
		md5((unsigned char*)arg[pos + 1], ssl);
		ft_printf("MD5 (%s) = ",arg[pos + 1]);
		print_msg(*ssl);
	}
	else
	{
		s = &(str[i + 1]);
		(*ssl)->msg_len = ft_strlen(s);
		md5((unsigned char*)s, ssl);
		ft_printf("MD5 (%s) = ",s);
		print_msg(*ssl);
	}

}
