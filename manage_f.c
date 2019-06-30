/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:50:41 by sergeygusac       #+#    #+#             */
/*   Updated: 2019/06/30 06:22:30 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

char	*read_file(t_ssl **ssl, char *str)
{
	int 	fd;
	int 	num_r;
	char	buff[BUFFSIZE];
	char	*temp;

	(*ssl)->f_p = 0;
	num_r = 0;
	fd = 0;
	fd = open(str, O_RDONLY);
	temp = ft_strnew(1);
	if(fd < 0)
	{
		ft_printf("%s :No such file or directory",str);
		error("");
	}
	while ((num_r = read(fd, &buff, BUFFSIZE)) > 0)
	{
		buff[num_r] = '\0';
		temp = ft_update(temp, ft_strjoin(temp, buff));
		(*ssl)->msg_len+=num_r;
	}
	return (temp);
}

unsigned char		*file_r(t_ssl **ssl, char **str)
{
	char *s;
	int i;

	i = 0;
	s = str[2];
	while(s[i])
	{
		if(s[i] != '-')
			return ((unsigned char*)read_file(ssl, s));
	}
	return (NULL);
}